<?php 

class RosPurchaseProcess {
	
	public function __construct($form_state) {
		// Work out the total
		$this->orderables = RosPurchaseBuild::getOrderables();
		
		$this->grants_access = false;
		$net_total = 0;
		
		foreach ($form_state['input'] as $fieldname => $fieldvalue) {
			$countpos = strrpos( $fieldname, '_count');
			if ( $countpos  == strlen($fieldname) - 6) {
				// ends with _count
				$itemname = substr($fieldname, 0, $countpos);
					
				$net_total += $fieldvalue * $this->orderables[$itemname]->price;
				if ($fieldvalue > 0) {
					$this->grants_access |= $this->orderables[$itemname]->web_access;
				}
				
				$this->fields[$fieldname] = (object)array('count' => true, 'value' => $fieldvalue, 'itemname' => $itemname);
			}
			else {
				$this->fields[$fieldname] = (object)array('count' => false, 'value' => $fieldvalue);
			}
			
		}
		
		$net_total += $this->orderables['_freight']->price;
		
		$this->gst = round($net_total * $this->orderables['_gst']->price, 2);
		$this->total_amount = round($net_total + $this->gst, 2);
		
	}

	public function MakeMoneyMarkup($id, $field) {
		return '<div id="' . $id . '">$' . money_format('%i', $this->$field) . '</div>';
	}
	
	public function SendFulfillmentMail() {
		$to = self::GetEmailsForRoles(array('administrator', 'order processor'));
				
		global $language;
		
		drupal_mail('ros_purchase', 'ros_purchase_adminbuy', $to, $language, array('order_object' => $this));
	}

	public function SendAcknowlegeMail() {
		$to = self::GetEmailsForRoles(array('administrator'));
		
		$to .= ', ' . $this->fields['email']->value;
	
		global $language;
	
		drupal_mail('ros_purchase', 'ros_purchase_ack', $to, $language, array('order_object' => $this));
	}
	
	public function MakeOrderDetails() {
		$res = '';
		
		foreach ($this->fields as $fieldname => $fieldvalue) {
			if(! $fieldvalue->count || 0==$fieldvalue->value ) {
				continue;
			}
			
			$res .= $fieldvalue->value . ' x ' . 	$this->orderables[$fieldvalue->itemname]->name . ' @ $' . $this->orderables[$fieldvalue->itemname]->price . "\n";
		}

		$res .= "____________________________________________________\n";
		$res .= $this->orderables['_freight']->name . ': $' . $this->orderables['_freight']->price . "\n";
		$res .= $this->orderables['_gst']->name . ' @ ' . $this->orderables['_gst']->price . '% = $' . $this->gst . "\n";
		$res .= 'Total: $' . $this->total_amount . "\n";
		
		return $res;
	}

	public function MakeContactDetails() {
		$contact_fields = array(
			'Organization'=>'org_name',
			'First name'=>'purchaser_first_name',
			'Last name'=>'purchaser_last_name',
			'Address'=>'street_address',
			'City'=>'city',
			'Postcode'=>'postcode',
			'Email'=>'email',
			'Phone' => 'telephone',
			'Order number' => 'order_number',
			'Comments' => 'comments'
		);
		
		return $this->MakeFieldList($contact_fields);
	}
	
	public function MakeLoginDetails() {
		$login_fields = array(
			'User id' => 'user_id',
			'Admin email' => 'admin_email'
		);
		
		return $this->MakeFieldList($login_fields);
	}
		
	public function GrantAccess() {
		return $this->grants_access && ( !isset($this->fields) || !array_key_exists('existing_login', $this->fields) || !$this->fields['existing_login']->value);
	}
	
	public function Validate() {
		if(user_is_logged_in() || !$this->GrantAccess()) {
			return null;
		}
		
		$res = array();

		if(!array_key_exists('password', $this->fields) || empty($this->fields['password']->value['pass1']) || empty($this->fields['password']->value['pass2'])) {
			$res[] =  (object)array('fieldname' => 'password', 'message' => 'A password is required');
		}
		
		if(!array_key_exists('user_id', $this->fields) || empty($this->fields['user_id']->value)) {
			$res[] = (object)array('fieldname' => 'user_id', 'message' => 'A user name is required');
			
			return $res;	// No user id so can't validate
		}
		
		$userid = $this->fields['user_id']->value;

		$email = $this->FetchEmail();
		
		$users = entity_load('user');
		
		// debug('Create user, users=' . print_r($users, true));
		
		foreach ($users as $check_user) {
			if (strcasecmp($check_user->name, $userid)==0) {
				$res[] =  (object)array('fieldname' => 'user_id', 'message' => 'User name is in use, please select another');
			}
			
			if(strcasecmp($check_user->mail, $email)==0) {
				$res[] =  (object)array('fieldname' => 'user_id', 'message' => 'Email is already in use. Please select another or check the \'I already have an account\' box');
			}
		}
		
		return $res;
	}
	
	public function CreateUser() {
		$edit = array(
			'name' => $this->fields['user_id']->value,
			'pass' => $this->fields['password']->value['pass1'],
			'mail' => $this->FetchEmail(),
			'field_first_name' => array(LANGUAGE_NONE => array(array('value' => $this->fields['purchaser_first_name']->value))),
			'field_last_name' => array(LANGUAGE_NONE => array(array('value' => $this->fields['purchaser_last_name']->value))),
			'field_phone_number' => array(LANGUAGE_NONE => array(array('value' => $this->fields['telephone']->value))),
			'field_organization' => array(LANGUAGE_NONE => array(array('value' => $this->fields['org_name']->value))),
// 		'field_first_name' => $this->fields['purchaser_first_name']->value,
// 		'field_last_name' => $this->fields['purchaser_last_name']->value,
// 		'field_phone_number' => $this->fields['telephone']->value,
// 		'field_organization' => $this->fields['org_name']->value,
		'status' => 0
		);
		
		$account = user_save(null, $edit);
		
		return FALSE !== $account;
	}
	
	public static function GetEmailsForRoles($roles) {

		$users = entity_load('user');
		
		$email_array = array();
		
		foreach ($roles as $role) {
			foreach($users as $user) {
				if (array_search($role, $user->roles)) {
					$email_array[$user->mail] = $user->name;
				}
			}
		}
		
		return implode(',', array_keys($email_array));
	}
	private function FetchEmail() {
		if(!array_key_exists('admin_email', $this->fields) || empty($this->fields['admin_email']->value)) {
			return $this->fields['email']->value;
		}

		return $this->fields['admin_email']->value;
	}

	private function MakeFieldList($fields) {
		
		$res = '';
		foreach ($fields as $label => $fieldname) {
			
			if(array_key_exists($fieldname, $this->fields) && !empty($this->fields[$fieldname]->value)) {
				$res .= "$label: " . $this->fields[$fieldname]->value . "\n";
			}
		}
		return $res;
	}

}


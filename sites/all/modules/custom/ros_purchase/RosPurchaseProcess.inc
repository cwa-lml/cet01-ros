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

	public function SendFulfillmentMail() {
		$admin = 'richardparratt@learningmedia.co.nz';
		
		global $language;
		
		drupal_mail('ros_purchase', 'ros_purchase_adminbuy', $admin, $language, array('order_object' => $this));
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


}

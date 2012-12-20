<?php 

class RosPurchaseBuild {

	public static function getOrderables() {
		$qry_products = new EntityFieldQuery();
	
		$res_products = $qry_products
		->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'product_item')
		->execute();
	
		$node_products = node_load_multiple(array_keys($res_products['node']));
	
		// debug('node_products:' . print_r($node_products, true));
	
		$res = array();
	
		foreach ($node_products as $nid => $node) {
			$res[$node->title] = (object)array('name' => self::getFieldFirst($node,'body'), 
				'price' => self::getFieldFirst($node,'field_price'), 
				'web_access' => self::getFieldFirst($node,'field_web_access'),
				'weight' => self::getFieldFirst($node, 'field_weight'));
		}
	
		uasort($res, function($a,$b) {
			return  ($a->weight == $b->weight) ? 0 : ( ($a->weight > $b->weight) ? 1 : -1 );
		} );
		return $res;
	
		//	return array('resource' => (object)array('name' => t('A River of Stories Educational Resource'), 'price' => '89.00'),
		//		'hardbook' => (object)array('name' => t('A River of Stories Book - hard cover'), 'price' => '89.00'),
		//		'softbook' => (object)array('name' => t('A River of Stories Book - soft cover'), 'price' => '89.00'),
		//		'cards' => (object)array('name' => t('Read and Respond cards - 1 set'), 'price' => '89.00'));
	}
	
	public static function pageForm() {
				
		$form['header'] = array(
				'#type' => 'item',
				'#after_build' => array('ros_purchase_load_javascript'),
				'#title' => t('Purchase the resource'),
				'#markup' => t('You can purchase several Educational Resources but only one login id will be provided.'
		. 'On confirmation of your order, the login details will be sent to the Administrator email address. '
		. 'Currently this Educational Resource is only available for New Zealand. Access to the secure area of this site is only '
		. 'granted to those purchasing the full Educational Resource and not to individual item purchases.'
		. '<br/>'
		. 'For any queries or requests for other items in the Educational Resource please call Customer Services on '
		. '0800 800 565 (8am - 5pm weekdays)'),
		);
		
		$form['order'] = array(
				'#type' => 'fieldset',
				'#title' => 'Your order',
		);
		
		// Build the order form with ajaxy stuff
		$ros_orderables = self::getOrderables();
		foreach ($ros_orderables as $type => $item) {
			if ($type[0] == '_' ) {
				continue;
			}
		
			$form['order'][$type . '_count'] = array(
					'#type' => 'textfield',
					'#size' => 2,
					'#default_value' => 0,
					'#ajax' => array('callback' => 'ros_purchase_updated_count'));
		
			$form['order'][$type . '_price'] = array(
					'#type' => 'textfield',
					'#title' => $item->name . ' (NZD)',
					'#size' => 6,
					'#default_value' => '$' . $item->price,
					'#disabled' => TRUE
			);
		}
		
		$form['order']['freight_price'] = array(
			'#type' => 'textfield',
						'#title' => $ros_orderables['_freight']->name,
						'#size' => 6,
						'#default_value' => '$' . $ros_orderables['_freight']->price,
						'#disabled' => TRUE
		);
		
		$form['order']['gst_amount'] = array(
				'#type' => 'item',
				'#title' => $ros_orderables['_gst']->name,
				'#markup' => '<div id="gst-amount" />'
		);
		
		$form['order']['total_amount'] = array(
					'#type' => 'item',
					'#title' => 'Total NZD (incl. shipping)',
					'#markup' => '<div id="total-amount" />'
		);
		
		
		// Collect the order deets
		$form['details'] = array(
				'#type' => 'fieldset',
				'#title' => 'Your details',
		);
		
		$form['details']['purchase_for'] = array(
							'#type' => 'radios',
							'#title' => t('Purchase for'),
							'#options' => array('organisation' => t('Organisation or school'), 'individual' => t('Individual')),
							'#required' => true
		);

		$form['details']['purchaser_first_name'] = array(
									'#type' => 'textfield',
									'#title' => t('Your name'),
									'#required' => true,
									'#size' => 20,
		);

		$form['details']['purchaser_last_name'] = array(
			'#type' => 'textfield',
			'#required' => true,
			'#title_display' => 'invisible',
			'#size' => 20,
		);
		
		$form['details']['org_name'] = array(
											'#type' => 'textfield',
											'#title' => t('Organisation or school name'),
											'#size' => 45,
		);
		
		$form['details']['street_address'] = array(
													'#type' => 'textarea',
													'#title' => t('Street address'),
													'#cols' => 45,
													'#rows' => 3,
		);
		
		$form['details']['city'] = array(
											'#type' => 'textfield',
											'#title' => t('City'),
											'#size' => 20,
		);
		
		$form['details']['postcode'] = array(
					'#type' => 'textfield',
					'#title' => t('Post code'),
					'#size' => 20,
		);

		$form['details']['email'] = array(
								'#type' => 'textfield',
								'#title' => t('Email'),
								'#required' => true,
								'#size' => 20,
		);
		
		$form['details']['telephone'] = array(
						'#type' => 'textfield',
						'#title' => t('Telephone'),
						'#required' => true,
						'#size' => 20,
		);
		
		$form['details']['telephone_note'] = array(
								'#type' => 'item',
								'#title' => t('(area code) 000 0000'),
		);
		
		
		$form['details']['order_number'] = array(
							'#type' => 'textfield',
							'#title' => t('Your purchase order number or reference'),
							'#size' => 45,
		);
		$form['details']['order_note'] = array(
										'#type' => 'item',
										'#title' => t('If you have one, please enter it above.'),
		);
		
		
		$form['details']['comments'] = array(
															'#type' => 'textarea',
															'#title' => t('Comments for customer service'),
															'#cols' => 45,
															'#rows' => 4,
		);
		
		// Collect the login deets
		$form['login'] = array(
						'#type' => 'fieldset',
						'#title' => 'Requested login details',
						'#attributes' => array('style' => array('display:none')),
		);
		
		$form['login']['user_id'] = array(
											'#type' => 'textfield',
											'#title' => t('Requested User ID'),
											'#required' => false,
											'#size' => 20,
		);

		$form['login']['password'] = array(
													'#type' => 'password_confirm',
													'#required' => false,
													'#size' => 20,
													'#attributes' => array('autocomplete' => 'off')
		);
		
		$form['login']['admin_email'] = array(
											'#type' => 'textfield',
											'#title' => t('Administrator email'),
											'#size' => 20,
		);
		$form['login']['admin_note'] = array(
										'#type' => 'item',
										'#title' => t('Person who will administer this account. If left blank, the contact email address will be used'),
		);
		
		$form['accept_tc'] = array(
			'#type' => 'checkbox',
			'#title' => t('I have read and understood the <a href="/termsandconditions">Terms and Conditions</a>'),
			'#required' => true,
			);
		
		$form['submit'] = array(
				'#type' => 'submit',
				'#value' => t('Submit'),
		);
		
		return $form;
		
	}
	
	private static function getFieldFirst($entity, $fieldname) {
		$all_values = self::getFieldMultiple($entity, $fieldname);

		if(empty($all_values)) {
			return null;
		}
		
		return $all_values[0];
	}
	
	private static function getFieldMultiple($entity, $fieldname) {
		$lang = field_language('node', $entity, $fieldname);
		$value_entries = $entity->{$fieldname}[$lang];
		
		$res = array();
		foreach ($value_entries as $value_entry) {
			$res[] = $value_entry['value'];
		}
		
		return $res;
	}
}

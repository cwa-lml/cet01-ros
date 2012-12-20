<?php 

class RosPurchaseProcess {
	
	public function __construct($form_state) {
		// Work out the total
		$ros_orderables = RosPurchaseBuild::getOrderables();
		
		$this->grants_access = false;
		$net_total = 0;
		
		foreach ($form_state['input'] as $fieldname => $fieldcount) {
			$countpos = strrpos( $fieldname, '_count');
			if ( $countpos  == strlen($fieldname) - 6) {
				// ends with _count
				$itemname = substr($fieldname, 0, $countpos);
					
				$net_total += $fieldcount * $ros_orderables[$itemname]->price;
				if ($fieldcount > 0) {
					$this->grants_access |= $ros_orderables[$itemname]->web_access;
				}
			}
		}
		
		$net_total += $ros_orderables['_freight']->price;
		
		$this->gst = $net_total * $ros_orderables['_gst']->price;
		$this->total_amount = $net_total + $gst;
	}

}
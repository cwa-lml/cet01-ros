<?php 

// Autocomplete for the organisation block with school details


/**
 * Called from ros_purchase_menu to get the dummy menu entry for the autocomplete
 * 
 * @return the menu 
 */
function ros_purchase_skoolcomplete_menu() {
	$items['schools/autocomplete'] = array(
	    'page callback' => 'ros_purchase_skoolcomplete_autocomplete',
	    'access callback' => TRUE,
	    'type' => MENU_CALLBACK,
	);
	return $items;
}

/**
 * Autocomplete page callback
 * Returns (to json) a list of NZ schools matching the passed string
 * 
 * @param String $typing
 */
function ros_purchase_skoolcomplete_autocomplete($typing=null) {
	
	// Want at least 3 chars
	if(empty($typing) || strlen($typing) < 3) {
		return drupal_json_output(array());
	}
	
	// Try the cache
	$cache_key = "school_$typing";
	$cache = cache_get($cache_key);
	if($cache) {
		drupal_json_output($cache->data);
		return;
	}
	
	// Get schools from Solr and cache
	
	$query = 'http://search.tki.org.nz:8983/solr/select?indent=on&version=2.2&q=institution_name_t:' . $typing . '&fq=tki_record_type%3Aschool&start=0&rows=3000&fl=institution_name_t&qt=standard&wt=json&explainOther=&sort=institution_name_t+asc';
	
	$ch = curl_init($query);
	curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_ANY);
	curl_setopt($ch, CURLOPT_USERPWD, 'admin:hf5B88m5HYmAXdY874hH');
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
		
	$schools_json = curl_exec($ch);
	curl_close($ch);

	$schools_result = json_decode($schools_json, true);
	
	$school_comp = array();
	foreach ($schools_result['response']['docs'] as $school_inst) {
		$school_name = $school_inst['institution_name_t'];
		$school_comp[$school_name] = $school_name;
	}
	
	asort($school_comp);
	
	cache_set($cache_key, $school_comp);
	
	drupal_json_output($school_comp);
}


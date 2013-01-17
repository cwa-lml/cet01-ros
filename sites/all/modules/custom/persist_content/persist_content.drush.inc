<?php

function persist_content_drush_command() {
	$items = array();

	$items['persisted-content-load'] = array(
            'description' => "Load persisted content",
            'arguments' => array(
	),
            'options' => array(	),
            'examples' => array(
	),
            'aliases' => array('pcl'),
            'bootstrap' => DRUSH_BOOTSTRAP_LOGIN, // Need a login to get Fedora login
	);

	return $items;
}

function drush_persist_content_persisted_content_load() {
	debug("Load persisted content");

	persist_content_load_all();
}

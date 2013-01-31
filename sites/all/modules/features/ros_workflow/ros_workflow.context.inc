<?php
/**
 * @file
 * ros_workflow.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ros_workflow_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_body_width_span1';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_body_content_width',
        'field_value' => 'span1',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-span1',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_body_width_span1'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_body_width_span2';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_body_content_width',
        'field_value' => 'span2',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-span2',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_body_width_span2'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_body_width_span3';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_body_content_width',
        'field_value' => 'span3',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-span3',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_body_width_span3'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_body_width_span4';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_body_content_width',
        'field_value' => 'span4',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-span4',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_body_width_span4'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_body_width_span5';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_body_content_width',
        'field_value' => 'span5',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-span5',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_body_width_span5'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_body_width_span6';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_body_content_width',
        'field_value' => 'span6',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'span6',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_body_width_span6'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_body_width_span7';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_body_content_width',
        'field_value' => 'span7',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-span7',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_body_width_span7'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_body_width_span8';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_body_content_width',
        'field_value' => 'span8',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-span8',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_body_width_span8'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_type_poem';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_type',
        'field_value' => 'poem',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-type-poem',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_type_poem'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'interactive_whiteboard_type_story';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'entity_field' => array(
      'values' => array(
        'entity_type' => 'a:7:{s:4:"node";s:4:"node";s:7:"comment";i:0;s:4:"file";i:0;s:13:"taxonomy_term";i:0;s:19:"taxonomy_vocabulary";i:0;s:4:"user";i:0;s:12:"rules_config";i:0;}',
        'field_name' => 'field_type',
        'field_value' => 'story',
        'field_empty' => 0,
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'iwb-content-type-story',
    ),
  );
  $context->condition_mode = 0;
  $export['interactive_whiteboard_type_story'] = $context;

	$context = new stdClass;
	$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
	$context->api_version = 3;
	$context->name = 'header-user-menus';
	$context->description = 'Add user ';
	$context->tag = '';
	$context->conditions = array(
	  'user' => array(
	    'values' => array(
	      'administrator' => 'administrator',
	      'authenticated user' => 'authenticated user',
	      'order processor' => 'order processor',
	    ),
	  ),
	);
	$context->reactions = array(
	  'block' => array(
	    'blocks' => array(
	      'menu-menu-top-right-logged-in' => array(
	        'module' => 'menu',
	        'delta' => 'menu-top-right-logged-in',
	        'region' => 'header',
	        'weight' => '-9',
	      ),
	      'ros_extra-ROSEXTRA' => array(
	        'module' => 'ros_extra',
	        'delta' => 'ROSEXTRA',
	        'region' => 'header',
	        'weight' => '-8',
	      ),
	    ),
	  ),
	);
	$context->condition_mode = 0;
	
	// Translatables
	// Included for use with string extractors like potx.
	t('Add user ');
  
	$context = new stdClass;
	$context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
	$context->api_version = 3;
	$context->name = 'header-user-menus-anon';
	$context->description = 'Add user ';
	$context->tag = '';
	$context->conditions = array(
	  'user' => array(
	    'values' => array(
	      'anonymous user' => 'anonymous user',
	),
	),
	);
	$context->reactions = array(
	  'block' => array(
	    'blocks' => array(
	      'menu-menu-top-right' => array(
	        'module' => 'menu',
	        'delta' => 'menu-top-right',
	        'region' => 'header',
	        'weight' => '-10',
	),
	      'ros_extra-ROSEXTRA' => array(
	        'module' => 'ros_extra',
	        'delta' => 'ROSEXTRA',
	        'region' => 'header',
	        'weight' => '-8',
	),
	),
	),
	);
	$context->condition_mode = 0;
	
	// Translatables
	// Included for use with string extractors like potx.
	t('Add user ');
	
  return $export;
}

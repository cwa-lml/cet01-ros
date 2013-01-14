<?php
/**
 * @file
 * ros_workflow.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ros_workflow_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ros_workflow_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function ros_workflow_node_info() {
  $items = array(
    'front_page_text' => array(
      'name' => t('Front Page Text'),
      'base' => 'node_content',
      'description' => t('The text to display on the front page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'front_page_video' => array(
      'name' => t('Front Page Video'),
      'base' => 'node_content',
      'description' => t('Define a front page video to show'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'interactive_whiteboard' => array(
      'name' => t('Interactive whiteboard'),
      'base' => 'node_content',
      'description' => t('This content type defines an Interactive Whiteboard (IWB) with popups for metaphors and word definitions'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page_with_multiple_files' => array(
      'name' => t('Page with multiple files'),
      'base' => 'node_content',
      'description' => t('An article type page with multiple file links'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_item' => array(
      'name' => t('Product Item'),
      'base' => 'node_content',
      'description' => t('A product item description with price details'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'purchase_page' => array(
      'name' => t('Purchase page'),
      'base' => 'node_content',
      'description' => t('The purchase page.
Only one of these.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'resource_item_description' => array(
      'name' => t('Resource item description'),
      'base' => 'node_content',
      'description' => t('A description of a resource/module or other item.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

<?php
/**
 * @file
 * ros_workflow.features.inc
 */

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
    'resource_item_description' => array(
      'name' => t('Resource item description'),
      'base' => 'node_content',
      'description' => t('A description of a resource item that will be displayed on the "What\'s in the resource" page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

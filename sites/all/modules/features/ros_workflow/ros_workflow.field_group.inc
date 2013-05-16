<?php
/**
 * @file
 * ros_workflow.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ros_workflow_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_order|node|purchase_page|form';
  $field_group->group_name = 'group_order';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Your order',
    'weight' => '2',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Your order',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_order|node|purchase_page|form'] = $field_group;

  return $export;
}

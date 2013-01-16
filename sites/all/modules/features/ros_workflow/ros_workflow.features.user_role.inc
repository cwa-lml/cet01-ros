<?php
/**
 * @file
 * ros_workflow.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ros_workflow_user_default_roles() {
  $roles = array();

  // Exported role: order processor
  $roles['order processor'] = array(
    'name' => 'order processor',
    'weight' => '3',
  );

  return $roles;
}

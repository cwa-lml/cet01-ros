<?php
/**
 * @file
 * ros_workflow.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ros_workflow_user_default_permissions() {
  $permissions = array();

  // Exported permission: ros_purchase
  $permissions['ros_purchase'] = array(
    'name' => 'ros_purchase',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
      3 => 'order processor',
    ),
    'module' => 'ros_purchase',
  );

  return $permissions;
}

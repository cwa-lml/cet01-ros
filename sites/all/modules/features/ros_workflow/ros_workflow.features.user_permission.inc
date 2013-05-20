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

  // Exported permission: access dashboard
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      0 => 'administrator',
      1 => 'order processor',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'administrator',
      1 => 'order processor',
    ),
    'module' => 'user',
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'administrator',
      1 => 'order processor',
    ),
    'module' => 'user',
  );

  // Exported permission: cancel account
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

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

  // Exported permission: select account cancellation method
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'user',
  );

  return $permissions;
}

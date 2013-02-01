<?php
/**
 * @file
 * ros_workflow.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ros_workflow_default_fe_block_settings() {
  $export = array();

  $export['version'] = '1.0';

  // Theme independent visibility settings.
  $export['visibility'] = array(
    'menu-menu-footer' => array(
      'delta' => 'menu-footer',
      'module' => 'menu',
    ),
    'menu-menu-top-right' => array(
      'delta' => 'menu-top-right',
      'module' => 'menu',
    ),
    'menu-menu-top-right-logged-in' => array(
      'delta' => 'menu-top-right-logged-in',
      'module' => 'menu',
    ),
    'ros_extra-ROSEXTRA' => array(
      'delta' => 'ROSEXTRA',
      'module' => 'ros_extra',
    ),
    'system-main' => array(
      'delta' => 'main',
      'module' => 'system',
      'node_type' => array(
        'article' => TRUE,
      ),
    ),
    'user-login' => array(
      'delta' => 'login',
      'module' => 'user',
    ),
    'views-video_block-block' => array(
      'delta' => 'video_block-block',
      'module' => 'views',
    ),
  );

  // cet
  $theme = array();

  $theme['menu-menu-footer'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer',
    'theme' => 'cet',
    'status' => '1',
    'weight' => '0',
    'region' => 'footer',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['menu-menu-top-right'] = array(
    'module' => 'menu',
    'delta' => 'menu-top-right',
    'theme' => 'cet',
    'status' => 0,
    'weight' => '2',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['menu-menu-top-right-logged-in'] = array(
    'module' => 'menu',
    'delta' => 'menu-top-right-logged-in',
    'theme' => 'cet',
    'status' => 0,
    'weight' => '1',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['ros_extra-ROSEXTRA'] = array(
    'module' => 'ros_extra',
    'delta' => 'ROSEXTRA',
    'theme' => 'cet',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '1',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['system-main'] = array(
    'module' => 'system',
    'delta' => 'main',
    'theme' => 'cet',
    'status' => '1',
    'weight' => '0',
    'region' => 'content',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['user-login'] = array(
    'module' => 'user',
    'delta' => 'login',
    'theme' => 'cet',
    'status' => '1',
    'weight' => '0',
    'region' => 'frontpage_sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-video_block-block'] = array(
    'module' => 'views',
    'delta' => 'video_block-block',
    'theme' => 'cet',
    'status' => '1',
    'weight' => '1',
    'region' => 'frontpage_sidebar_second',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['theme']['cet'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export['theme'][$theme_key]);
    }
  }
  return $export;
}

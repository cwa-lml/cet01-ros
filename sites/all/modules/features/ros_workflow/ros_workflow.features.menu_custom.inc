<?php
/**
 * @file
 * ros_workflow.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ros_workflow_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer Menu',
    'description' => 'Menu to show in page footer',
  );
  // Exported menu: menu-top-right
  $menus['menu-top-right'] = array(
    'menu_name' => 'menu-top-right',
    'title' => 'Top Right Anon',
    'description' => 'Top right menu (for anon user when not logged in)',
  );
  // Exported menu: menu-top-right-logged-in
  $menus['menu-top-right-logged-in'] = array(
    'menu_name' => 'menu-top-right-logged-in',
    'title' => 'Top Right Logged In',
    'description' => 'Top Right menu for logged in user',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer Menu');
  t('Main menu');
  t('Menu to show in page footer');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('Top Right Anon');
  t('Top Right Logged In');
  t('Top Right menu for logged in user');
  t('Top right menu (for anon user when not logged in)');


  return $menus;
}

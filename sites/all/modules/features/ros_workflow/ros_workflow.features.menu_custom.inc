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
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer Menu');
  t('Main menu');
  t('Menu to show in page footer');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}

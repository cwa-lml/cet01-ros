<?php
/**
 * @file
 * ros_workflow.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ros_workflow_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:whats-in-resource
  $menu_links['main-menu:whats-in-resource'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'whats-in-resource',
    'router_path' => 'whats-in-resource',
    'link_title' => 'What\'s in the resource',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-footer:<front>
  $menu_links['menu-footer:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:node/add/purchase-page
  $menu_links['navigation:node/add/purchase-page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/purchase-page',
    'router_path' => 'node/add/purchase-page',
    'link_title' => 'Purchase page',
    'options' => array(
      'attributes' => array(
        'title' => 'The purchase page.
Only one of these.',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/resource-item-description
  $menu_links['navigation:node/add/resource-item-description'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/resource-item-description',
    'router_path' => 'node/add/resource-item-description',
    'link_title' => 'Resource item description',
    'options' => array(
      'attributes' => array(
        'title' => 'A description of a resource item that will be displayed on the "What\'s in the resource" page',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:ros_purchase
  $menu_links['navigation:ros_purchase'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'ros_purchase',
    'router_path' => 'ros_purchase',
    'link_title' => 'Purchase',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:search
  $menu_links['navigation:search'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('Purchase');
  t('Purchase page');
  t('Resource item description');
  t('Search');
  t('What\'s in the resource');


  return $menu_links;
}

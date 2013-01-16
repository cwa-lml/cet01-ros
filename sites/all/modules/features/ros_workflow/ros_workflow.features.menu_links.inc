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
  // Exported menu link: menu-top-right-logged-in:node/14
  $menu_links['menu-top-right-logged-in:node/14'] = array(
    'menu_name' => 'menu-top-right-logged-in',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(
        'title' => 'Display contact details for this site',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Exported menu link: menu-top-right-logged-in:user/logout
  $menu_links['menu-top-right-logged-in:user/logout'] = array(
    'menu_name' => 'menu-top-right-logged-in',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(
        'title' => 'Log out from this site',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-top-right:node/14
  $menu_links['menu-top-right:node/14'] = array(
    'menu_name' => 'menu-top-right',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(
        'title' => 'Display our contact information',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '2',
  );
  // Exported menu link: menu-top-right:user/login
  $menu_links['menu-top-right:user/login'] = array(
    'menu_name' => 'menu-top-right',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(
        'title' => 'Log in with your River Of Stories username',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: navigation:node/add/interactive-whiteboard
  $menu_links['navigation:node/add/interactive-whiteboard'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/interactive-whiteboard',
    'router_path' => 'node/add/interactive-whiteboard',
    'link_title' => 'Interactive whiteboard',
    'options' => array(
      'attributes' => array(
        'title' => 'This content type defines an Interactive Whiteboard (IWB) with popups for metaphors and word definitions',
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
        'title' => 'A description of a resource/module or other item.',
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
  t('Contact Us');
  t('Home');
  t('Interactive whiteboard');
  t('Login');
  t('Logout');
  t('Purchase');
  t('Purchase page');
  t('Resource item description');
  t('Search');
  t('What\'s in the resource');


  return $menu_links;
}

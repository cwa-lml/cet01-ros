<?php
/**
 * @file
 * ros_workflow.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ros_workflow_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'whats_in_resource';
  $view->description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut ';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Whats In Resource';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'What\'s in the resource';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Description';
  $handler->display->display_options['header']['area_text_custom']['content'] = '(Description text for What\'s In The Resource)';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Resource Image */
  $handler->display->display_options['fields']['field_resource_image']['id'] = 'field_resource_image';
  $handler->display->display_options['fields']['field_resource_image']['table'] = 'field_data_field_resource_image';
  $handler->display->display_options['fields']['field_resource_image']['field'] = 'field_resource_image';
  $handler->display->display_options['fields']['field_resource_image']['label'] = '';
  $handler->display->display_options['fields']['field_resource_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_resource_image']['element_class'] = 'row-img';
  $handler->display->display_options['fields']['field_resource_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_resource_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_resource_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Free Samples */
  $handler->display->display_options['fields']['field_freesamples']['id'] = 'field_freesamples';
  $handler->display->display_options['fields']['field_freesamples']['table'] = 'field_data_field_freesamples';
  $handler->display->display_options['fields']['field_freesamples']['field'] = 'field_freesamples';
  $handler->display->display_options['fields']['field_freesamples']['label'] = '';
  $handler->display->display_options['fields']['field_freesamples']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_freesamples']['element_label_colon'] = FALSE;
  /* Field: Content: Listen */
  $handler->display->display_options['fields']['field_listen']['id'] = 'field_listen';
  $handler->display->display_options['fields']['field_listen']['table'] = 'field_data_field_listen';
  $handler->display->display_options['fields']['field_listen']['field'] = 'field_listen';
  $handler->display->display_options['fields']['field_listen']['label'] = '';
  $handler->display->display_options['fields']['field_listen']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_listen']['alter']['text'] = '[title]
[body] 
[field_freesamples]
[field_listen]
';
  $handler->display->display_options['fields']['field_listen']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="row-bd">
  <h2><a href="/node/[nid]">[title]</a></h2>
  [body]
  <div class="controls">
    [field_freesamples]
    [field_listen]
  </div>
</div>

';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Weight (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource_item_description' => 'resource_item_description',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'whats-in-resource';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'What\'s in the resource';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['whats_in_resource'] = $view;

  return $export;
}

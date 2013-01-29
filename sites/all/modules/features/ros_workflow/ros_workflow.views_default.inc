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
  $view->name = 'interactive_whiteboard_resources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Interactive Whiteboard Resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Interactive Whiteboard Resources';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Description';
  $handler->display->display_options['header']['area']['content'] = '(Description text for interacive whiteboard)';
  $handler->display->display_options['header']['area']['format'] = 'plain_text';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'interactive_whiteboard' => 'interactive_whiteboard',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'interactive-whiteboard-resources';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Interactive Whiteboard Resources';
  $handler->display->display_options['menu']['description'] = 'Display interactive whiteboard resources';
  $handler->display->display_options['menu']['weight'] = '40';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['interactive_whiteboard_resources'] = $view;

  $view = new view();
  $view->name = 'read_and_respond_cards';
  $view->description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut ';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Read and Respond Cards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Read and Respond Cards';
  $handler->display->display_options['css_class'] = 'ros-list-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Description';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>(Description text for Read and Respond cards)</p>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Download all';
  $handler->display->display_options['header']['area']['content'] = '<div class=\'download-all\'><a href="#" class="btn">Download all</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Download */
  $handler->display->display_options['fields']['field_download_module']['id'] = 'field_download_module';
  $handler->display->display_options['fields']['field_download_module']['table'] = 'field_data_field_download_module';
  $handler->display->display_options['fields']['field_download_module']['field'] = 'field_download_module';
  $handler->display->display_options['fields']['field_download_module']['label'] = '';
  $handler->display->display_options['fields']['field_download_module']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_download_module']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_download_module']['alter']['text'] = '<p><a href="[field_download_module]" title="View sample. " class="btn btn-sample">View sample</a></p>';
  $handler->display->display_options['fields']['field_download_module']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download_module']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_download_module']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_download_module']['delta_offset'] = '0';
  /* Field: Content: Audio file */
  $handler->display->display_options['fields']['field_audio_file']['id'] = 'field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['table'] = 'field_data_field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['field'] = 'field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['label'] = '';
  $handler->display->display_options['fields']['field_audio_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_audio_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_audio_file']['alter']['text'] = ' <p><a href="#sample-audio-[nid]" role="button" data-toggle="modal" class="btn btn-listen">Listen</a></p>
    <div id="sample-audio-[nid]" class="modal hide">
      <div class="modal-header">
        <a  class="close">X</a>
        <h3>Sample audio file</h3>
      </div>
      <div class="modal-body">
        [field_audio_file]
      </div>
    </div>';
  $handler->display->display_options['fields']['field_audio_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_audio_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_audio_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio_file']['type'] = 'videojs';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="row-bd">
  <h2>[title]</h2>
<!-- <h2><a href="/node/[nid]">[title]</a></h2> -->
  [body]
  <div class="controls">
    [field_download_module]
    [field_audio_file]
  </div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  /* Filter criterion: Content: Resource Type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_value']['id'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_value']['field'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['value'] = array(
    'card' => 'card',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'readandrespond';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Read and Respond Cards';
  $handler->display->display_options['menu']['description'] = 'Display list of read and respond cards';
  $handler->display->display_options['menu']['weight'] = '20';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['read_and_respond_cards'] = $view;

  $view = new view();
  $view->name = 'teachers_resource_book';
  $view->description = 'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut ';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Teachers\' Resource Book';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Teachers\' Resource Book';
  $handler->display->display_options['css_class'] = 'ros-list-view';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>Rate aborporepre ni dolupti osanditat imus. Nequo tem. Sediosa quam, ute veliam quosser chicia velenet, consequo torporro volor molo di accatat officip issinti ut qui dolores tioremque ma demoles serioriatust autem voluptatem ipicimp orestis et esto illes aut volore venimpore et landipsam lab ipiendignis sum evernamet que officia vendis est, veliquasped experunt. </p>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Teachers Resource Book Download All';
  $handler->display->display_options['header']['area']['content'] = '<div class=\'download-all\'><a href="#" class="btn">Download all</a></div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Download */
  $handler->display->display_options['fields']['field_download_module']['id'] = 'field_download_module';
  $handler->display->display_options['fields']['field_download_module']['table'] = 'field_data_field_download_module';
  $handler->display->display_options['fields']['field_download_module']['field'] = 'field_download_module';
  $handler->display->display_options['fields']['field_download_module']['label'] = '';
  $handler->display->display_options['fields']['field_download_module']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_download_module']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_download_module']['alter']['text'] = '<p><a href="[field_download_module]" title="View sample. " class="btn btn-sample">View sample</a></p>';
  $handler->display->display_options['fields']['field_download_module']['alter']['path'] = '[field_download_module]';
  $handler->display->display_options['fields']['field_download_module']['alter']['link_class'] = 'btn btn-sample';
  $handler->display->display_options['fields']['field_download_module']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download_module']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_download_module']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_download_module']['delta_offset'] = '0';
  /* Field: Content: Audio file */
  $handler->display->display_options['fields']['field_audio_file']['id'] = 'field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['table'] = 'field_data_field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['field'] = 'field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['label'] = '';
  $handler->display->display_options['fields']['field_audio_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_audio_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_audio_file']['alter']['text'] = ' <p><a href="#sample-audio-[nid]" role="button" data-toggle="modal" class="btn btn-listen">Listen</a></p>
    <div id="sample-audio-[nid]" class="modal hide">
      <div class="modal-header">
        <a  class="close">X</a>
        <h3>Sample audio file</h3>
      </div>
      <div class="modal-body">
        [field_audio_file]
      </div>
    </div>';
  $handler->display->display_options['fields']['field_audio_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_audio_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_audio_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio_file']['type'] = 'videojs';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="row-bd">
  <h2>[title]</h2>
<!-- <h2><a href="/node/[nid]">[title]</a></h2> -->
  [body]
  <div class="controls">
    [field_download_module]
    [field_audio_file]
  </div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  /* Filter criterion: Content: Resource Type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_value']['id'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_value']['field'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['value'] = array(
    'teachersbook' => 'teachersbook',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'teachersresource';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Teachers\' Resource Book';
  $handler->display->display_options['menu']['description'] = 'Display the Teacher\'s Resource Book';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $export['teachers_resource_book'] = $view;

  $view = new view();
  $view->name = 'video_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'front_page_video' => 'front_page_video',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['video_block'] = $view;

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
  $handler->display->display_options['css_class'] = 'ros-list-view';
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
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>(Description text for What\'s In The Resource)</p>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'What\'s in the resource Download All';
  $handler->display->display_options['header']['area']['content'] = '<div class="download-all"><a href="#" class="btn">Download all</a></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Download */
  $handler->display->display_options['fields']['field_download_module']['id'] = 'field_download_module';
  $handler->display->display_options['fields']['field_download_module']['table'] = 'field_data_field_download_module';
  $handler->display->display_options['fields']['field_download_module']['field'] = 'field_download_module';
  $handler->display->display_options['fields']['field_download_module']['label'] = '';
  $handler->display->display_options['fields']['field_download_module']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_download_module']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_download_module']['alter']['text'] = '<p><a href="[field_download_module]" title="View sample. " class="btn btn-sample">View sample</a></p>';
  $handler->display->display_options['fields']['field_download_module']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_download_module']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_download_module']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_download_module']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_download_module']['delta_offset'] = '0';
  /* Field: Content: Audio file */
  $handler->display->display_options['fields']['field_audio_file']['id'] = 'field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['table'] = 'field_data_field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['field'] = 'field_audio_file';
  $handler->display->display_options['fields']['field_audio_file']['label'] = '';
  $handler->display->display_options['fields']['field_audio_file']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_audio_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_audio_file']['alter']['text'] = ' <p><a href="#sample-audio-[nid]" role="button" data-toggle="modal" class="btn btn-listen">Listen</a></p>
    <div id="sample-audio-[nid]" class="modal hide">
      <div class="modal-header">
        <a  class="close">X</a>
        <h3>Sample audio file</h3>
      </div>
      <div class="modal-body">
        [field_audio_file]
      </div>
    </div>';
  $handler->display->display_options['fields']['field_audio_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_audio_file']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_audio_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_audio_file']['type'] = 'videojs';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="row-bd">
  <h2>[title]</h2>
<!--   <h2><a href="/node/[nid]">[title]</a></h2> -->
  [body]
  <div class="controls">
    [field_download_module]
    [field_audio_file]
  </div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  /* Filter criterion: Content: Resource Type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_value']['id'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_value']['field'] = 'field_resource_type_value';
  $handler->display->display_options['filters']['field_resource_type_value']['value'] = array(
    'whats' => 'whats',
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

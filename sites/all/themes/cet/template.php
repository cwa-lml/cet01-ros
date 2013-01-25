<?php

function cet_link($variables) {
  if ($variables['path'] == 'user/password') {
    return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>Forgot password?</a>';
  }
  return theme_link($variables);
}

function cet_js_alter(&$javascript) {
  // Note the following is neeed to populate all the defaults in the javascript array
  // and avoid getting warnings from drupal_sort_css_js
  $file = drupal_get_path('theme', 'cet') . '/js/jquery.js';
  $javascript['misc/jquery.js']  = drupal_js_defaults($file);
  $javascript['misc/jquery.js']['group'] = JS_THEME;
  
}

function cet_theme(&$existing, $type, $theme, $path) {
	$items = array();
    
  $items['user_login'] = array(
    'render element' => 'form',
    'path' => drupal_get_path('theme', 'cet') . '/bootstrap/bootstrap/templates',
    'template' => 'user-login',
    'preprocess functions' => array(
       'cet_preprocess_user_login'
    ),
  );

  $items['user_pass'] = array(
      'render element' => 'form',
      'path' => drupal_get_path('theme', 'cet') . '/bootstrap/bootstrap/templates',
      'template' => 'user-pass',
      'preprocess functions' => array(
         'cet_preprocess_user_pass'
  ),
  );
  
  return $items;
}

function cet_preprocess_user_login(&$variables) {
  $variables['post_text'] = t('If you have purchased the Resource kit, an email has been sent to the Office Administrator as provided when the '
  . 'kit was purchased. Please see this person if you have forgotten your password. Otherwise if you choose to have your password reset, '
  . 'the new password will be sent to the Office Administrator. Likewise if you change the password, the new password will also be sent to the '
  . 'Office Administrator.<br/>'
  . 'For any queries call Customer Services on 0800 800 565 (8am - 5pm weekdays)');
}

function cet_preprocess_user_pass(&$variables) {
	$variables['pre_text'] = t('<b>Before proceeding:</b> If you are not the administrator of this account, we recommend you contact them before proceeding further '
	. 'as they will have a record of the current login password.<br/>');
	$variables['post_text'] = t('An email with a link will be sent to the administrator of this account who will then be requested to reset the password.<br/>'
	. 'Please check with them for the new password.');
	
}

function cet_preprocess_page(&$vars){
    if (isset($vars['node']) && $vars['node']->type == 'interactive_whiteboard'){
        drupal_set_title('');
    }
}

<?php

function cet_link($variables) {
  if ($variables['path'] == 'user/password') {
    return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>Forgot password?</a>';
  }
  return theme_link($variables);
}

function cet_js_alter(&$javascript) {
  $javascript['misc/jquery.js']['data'] = drupal_get_path('theme', 'cet') . '/js/jquery.js';
  $javascript['misc/jquery.js']['scope'] = 'header';
  $javascript['misc/jquery.js']['type'] = 'file';
}

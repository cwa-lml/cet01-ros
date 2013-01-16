<?php

function cet_link($variables) {
  if ($variables['path'] == 'user/password') {
    return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>Forgot password?</a>';
  }
  return theme_link($variables);
}

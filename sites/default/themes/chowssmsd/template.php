<?php
/**
 * Implementation of hook_preprocess_node()
 */
function chowssmsd_preprocess_node(&$variables) {
  // handle css different landing pages
  // $node = $variables['node'];
  // if (in_array($node->type, get_landing_pages())) {
  //   drupal_add_css(drupal_get_path('theme', 'ddms'). "/css/{$node->type}.less",array('group' => JS_THEME));

  //   // javascript
  //   drupal_add_js(drupal_get_path('theme', 'ddms') . '/js/jquery-1.8.3.min.js', array('group' => JS_THEME));
  //   drupal_add_js(drupal_get_path('theme', 'ddms') . '/js/common.js', array('group' => JS_THEME));
	
  //   drupal_add_js(drupal_get_path('theme', 'ddms') . "/js/{$node->type}.js", array('group' => JS_THEME, 'weight' => 98));
  //   drupal_add_js(drupal_get_path('theme', 'ddms') . '/js/switch.js', array('group' => JS_THEME, 'weight' => 99));
  // }

}



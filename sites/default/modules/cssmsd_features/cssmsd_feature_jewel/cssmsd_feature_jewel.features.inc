<?php
/**
 * @file
 * cssmsd_feature_jewel.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cssmsd_feature_jewel_image_default_styles() {
  $styles = array();

  // Exported image style: cssmsd_jewel_pic_thumb.
  $styles['cssmsd_jewel_pic_thumb'] = array(
    'label' => 'cssmsd_jewel_pic_thumb',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cssmsd_feature_jewel_node_info() {
  $items = array(
    'chowssmsd_jewel' => array(
      'name' => t('Jewel'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

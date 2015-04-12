<?php
/**
 * @file
 * cssmsd_feature_monther_type.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cssmsd_feature_monther_type_image_default_styles() {
  $styles = array();

  // Exported image style: cssmsd_mother_pic_l.
  $styles['cssmsd_mother_pic_l'] = array(
    'label' => 'cssmsd_mother_pic_l',
    'effects' => array(),
  );

  // Exported image style: cssmsd_mother_pic_s.
  $styles['cssmsd_mother_pic_s'] = array(
    'label' => 'cssmsd_mother_pic_s',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cssmsd_feature_monther_type_node_info() {
  $items = array(
    'chowssmsd_monther_type' => array(
      'name' => t('Monther Type'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

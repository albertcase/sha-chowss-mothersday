<?php
/**
 * @file
 * cssmsd_feature_monther_type.features.inc
 */

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

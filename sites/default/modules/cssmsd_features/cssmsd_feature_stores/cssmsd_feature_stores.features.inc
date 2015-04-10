<?php
/**
 * @file
 * cssmsd_feature_stores.features.inc
 */

/**
 * Implements hook_node_info().
 */
function cssmsd_feature_stores_node_info() {
  $items = array(
    'chowssmsd_stores' => array(
      'name' => t('Stores'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Store Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

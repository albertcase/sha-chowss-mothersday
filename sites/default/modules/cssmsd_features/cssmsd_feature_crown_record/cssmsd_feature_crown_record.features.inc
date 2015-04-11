<?php
/**
 * @file
 * cssmsd_feature_crown_record.features.inc
 */

/**
 * Implements hook_node_info().
 */
function cssmsd_feature_crown_record_node_info() {
  $items = array(
    'chowssmsd_crown_record' => array(
      'name' => t('Friend Crown Record'),
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

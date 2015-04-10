<?php
/**
 * @file
 * cssmsd_feature_user_winning_record.features.inc
 */

/**
 * Implements hook_node_info().
 */
function cssmsd_feature_user_winning_record_node_info() {
  $items = array(
    'chowssmsd_winning_record' => array(
      'name' => t('User Winning Record'),
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

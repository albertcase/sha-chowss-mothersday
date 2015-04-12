<?php
/**
 * @file
 * cssmsd_feature_users_mother.features.inc
 */

/**
 * Implements hook_node_info().
 */
function cssmsd_feature_users_mother_node_info() {
  $items = array(
    'chowssmsd_users_mother' => array(
      'name' => t('User`s Mother'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Mother Type'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

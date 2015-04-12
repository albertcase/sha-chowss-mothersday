<?php
/**
 * @file
 * cssmsd_feature_jewel.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cssmsd_feature_jewel_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_chowssmsd_jewel_pic'
  $field_bases['field_chowssmsd_jewel_pic'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_chowssmsd_jewel_pic',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}

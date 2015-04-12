<?php
/**
 * @file
 * cssmsd_feature_jewel.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cssmsd_feature_jewel_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-chowssmsd_jewel-field_chowssmsd_jewel_pic'
  $field_instances['node-chowssmsd_jewel-field_chowssmsd_jewel_pic'] = array(
    'bundle' => 'chowssmsd_jewel',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chowssmsd_jewel_pic',
    'label' => 'Picture',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'cssmsd_jewel_pic',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Picture');

  return $field_instances;
}

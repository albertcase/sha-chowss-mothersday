<?php
/**
 * @file
 * cssmsd_feature_user_winning_record.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cssmsd_feature_user_winning_record_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-chowssmsd_winning_record-field_chowssmsd_win_prize_code'
  $field_instances['node-chowssmsd_winning_record-field_chowssmsd_win_prize_code'] = array(
    'bundle' => 'chowssmsd_winning_record',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chowssmsd_win_prize_code',
    'label' => 'Prize Code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-chowssmsd_winning_record-field_chowssmsd_win_prize_name'
  $field_instances['node-chowssmsd_winning_record-field_chowssmsd_win_prize_name'] = array(
    'bundle' => 'chowssmsd_winning_record',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chowssmsd_win_prize_name',
    'label' => 'Prize Name',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-chowssmsd_winning_record-field_chowssmsd_win_prize_status'
  $field_instances['node-chowssmsd_winning_record-field_chowssmsd_win_prize_status'] = array(
    'bundle' => 'chowssmsd_winning_record',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chowssmsd_win_prize_status',
    'label' => 'Prize Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-chowssmsd_winning_record-field_chowssmsd_win_prize_winner'
  $field_instances['node-chowssmsd_winning_record-field_chowssmsd_win_prize_winner'] = array(
    'bundle' => 'chowssmsd_winning_record',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chowssmsd_win_prize_winner',
    'label' => 'Prize Winner',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-chowssmsd_winning_record-field_chowssmsd_win_store_name'
  $field_instances['node-chowssmsd_winning_record-field_chowssmsd_win_store_name'] = array(
    'bundle' => 'chowssmsd_winning_record',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chowssmsd_win_store_name',
    'label' => 'Store Name',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Prize Code');
  t('Prize Name');
  t('Prize Status');
  t('Prize Winner');
  t('Store Name');

  return $field_instances;
}

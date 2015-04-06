<?php

/**
 * DDMS staticpage setting form
 */
function ssbd_staticpage_settings_form($form, &$form_state) {
  $form['ssbd_staticpage_simulate_mobile'] = array(
    '#title' => t('Simulate Mobile'),
    '#type' => 'checkbox',
    '#required' => FALSE,
    '#default_value' => variable_get('ssbd_staticpage_simulate_mobile', NULL),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );
  return $form;
}

/**
 * Save the DDMS user settings.
 */
function ssbd_staticpage_settings_form_submit($form, &$form_state) {
  variable_set('ssbd_staticpage_simulate_mobile', $form_state['values']['ssbd_staticpage_simulate_mobile']);
}

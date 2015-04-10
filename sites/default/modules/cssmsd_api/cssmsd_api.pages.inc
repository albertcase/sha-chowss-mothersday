<?

/**
 * CSSMSD api setting form
 */
function cssmsd_api_settings_form($form, &$form_state) {

  $form['cssmsd_api_prize_probability'] = array(
    '#title' => t('Prize Probability (20/100 20/1000 ...)'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => variable_get('cssmsd_api_prize_probability', NULL),
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
function cssmsd_api_settings_form_submit($form, &$form_state) {

  variable_set('cssmsd_api_prize_probability', $form_state['values']['cssmsd_api_prize_probability']);

  drupal_set_message(t('Your configuration have been saved.'));
}


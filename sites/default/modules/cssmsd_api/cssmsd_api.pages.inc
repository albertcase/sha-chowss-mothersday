<?
include_once drupal_realpath('sites/all/libraries/PHPExcel/PHPExcel/IOFactory.php');
/**
 * Import Form.
 */
function ddms_2014_annual_campaign_form($form, &$form_state) {

  drupal_add_css('.excel-radio-red {color:red;} .excel-radio-green {color:green;}',$option['type'] = 'inline');
  
  
  $files = file_scan_directory('public://2014_annual_campaign/survey/upload', '/.*\.xlsx$/');

  $active = array();
  $msg = array('import_pending' => array('color' => 'red', 'msg' =>'正在导入中...'),
               'import_finished' => array('color' => 'green', 'msg' =>'导入完成'),
               'export_pending' => array('color' => 'red', 'msg' =>'正在导出中...'),
               'export_finished' => array('color' => 'green', 'msg' =>'导出完成'),
               );
  foreach($files as $file) {
    $data = array_shift(file_load_multiple(array(), array('uri' => $file->uri)));
    $info = _get_import_export_log($data->fid);
    $status = $msg[$info];
    $active[$data->fid] = date('Y-m-d-h-i-s', $data->timestamp) . '-' . $file->filename . "<span class='excel-radio-" . $status['color'] . "'>  " . $status['msg'] . "</span>";
  }

  $form = array();
  $form['#attributes'] = array(
    'enctype' => "multipart/form-data",
  );
  $form['#prefix'] = "<p>";
  $form['#prefix'] = t('Excel Import') . " ";
  $form['#prefix'] .= "</p>";

  $form['upload'] = array(
    '#type' => 'fieldset',
    '#title' => t('Upload file'),
    '#collapsible' => FALSE,
    '#collapsed' => !$values['file'],
  );
  $form['upload']['file'] = array(
    '#type' => 'file',
    '#description' => t('To clear this field, <a href="!reset">reset the form</a>.', array('!reset' => url($_GET['q'])))
  );

  $form['upload']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  $form['download'] = array(
    '#type' => 'fieldset',
    '#title' => t('Download file'),
    '#collapsible' => FALSE,
  );
  $form['download']['files'] = array(
    '#type' => 'radios',
    '#options' => $active,
    '#description' => t('Choose one of them to download.'),
  );

  $form['download']['export'] = array(
    '#type' => 'submit',
    '#value' => t('Export'),
  );

  $form['download']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Download'),
  );

  $form['download']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );

  return $form;
}

/**
 * Submit function for import form.
 */
function ddms_2014_annual_campaign_form_submit($form, &$form_state) {

  if ($form_state['input']['op'] == 'Import') {
    $survey_dir = 'public://2014_annual_campaign/survey/upload';
    if (!file_prepare_directory($survey_dir)) {
      drupal_mkdir($survey_dir, 0775, TRUE);
    }
    $validators['file_validate_extensions'] = array('xlsx');
    $file = file_save_upload('file', $validators);
    $file = file_move($file, $survey_dir);
    exec("php var/scripts/create_excell/create_excel.php $file->fid import > /dev/null 2>&1 &");
  }

  if ($form_state['input']['op'] == 'Download') {

    $fid = $form_state['input']['files'];
    $log = _get_import_export_log($fid);

    if($log == 'export_finished') {
        $file = file_load($fid);
        header('Content-type: ' . $file->filemime);
        header('Content-Disposition: attachment; filename="' . $file->filename . '"');
        print(file_get_contents(_create_download_filename($file)));
        exit;
    } 
  }

  if ($form_state['input']['op'] == 'Export') {

    $fid = $form_state['input']['files'];
    $log = _get_import_export_log($fid);

    $status = array('import_pending', 'export_pending');
    if(!in_array($log, $status)) {
      $file = file_load($fid);
      exec("php var/scripts/create_excell/create_excel.php $file->fid export > /dev/null 2>&1 &");
    }
  }

  if ($form_state['input']['op'] == 'Delete') {
    $file = file_load($form_state['input']['files']);
    file_delete($file);
  }
}

class ExcellReadFilter implements PHPExcel_Reader_IReadFilter
{
  private $_startRow = 0;

  private $_endRow = 0;

  private $_columns;

  /**  We expect a list of the rows that we want to read to be passed into the constructor  */
  public function __construct($columns, $startRow = 0, $chunkSize = 0) {
    $this->_startRow = $startRow;
    $this->_endRow = $startRow + $chunkSize;
    $this->_columns = $columns;
  }

  public function readCell($column, $row, $worksheetName = '') {
    //  Only read the heading row, and the rows that were configured in the constructor
    if (in_array($column, $this->_columns)) {
      if ($this->_startRow && $this->_endRow) {
        if ($row >= $this->_startRow && $row < $this->_endRow)
          return true;
      } else {
        return true;
      }
    }
    return false;
  }
}

/**
 * Handle excell to db.
 */
function _import_excell_to_db($file) {

  $mapping = array('A' => 'title', 'B' => 'field_2014ac_survey_surveylink', 'F' => 'field_2014ac_survey_surveylink', 'F' => 'field_2014ac_survey_feedback');

  $objPHPExcel = _objreader_load($file, array_keys($mapping));

  $startRow = 7;
  $maxRows = $objPHPExcel->getActiveSheet()->getHighestRow();

  for ($i = $startRow; $i <= $maxRows; $i++) {

    $node = new StdClass;
    $node->type = '2014_annual_campaign_survey_link';
    $node->status = 0;
    $node->uid = 0;
    $node->language = LANGUAGE_NONE;
    foreach($mapping as $cell => $field) {

      $value = $objPHPExcel->getActiveSheet()->getCell($cell . $i)->getValue();
        
      if($field == 'title') {
        if(!$value) 
          break 2;
        $node->$field = $value;
      } elseif($field == 'field_2014ac_survey_surveylink') {
        if(!$value) 
          break 2;
        $f[LANGUAGE_NONE][0]['url'] = $value;
        $node->$field = $f;
      } else {
        $f[LANGUAGE_NONE][0]['value'] = $value;
        $node->$field = $f;
      }

    } 

    $nodes = node_load_multiple(array(), array('type' => '2014_annual_campaign_survey_link', 'title' => $node->title));
    if($nodes){
      $node_update = array_shift($nodes);
      if ($node_update->field_2014ac_survey_feedback !== $node->field_2014ac_survey_feedback) {
        $node_update->field_2014ac_survey_feedback = $node->field_2014ac_survey_feedback;
        node_save($node_update);
      }
    } else {
      node_save($node);
    }
    
  }

}

function _export_db_to_excel($file) {

  $objPHPExcel = _objreader_load($file, array('A'));
  $sheetData = $objPHPExcel->getActiveSheet()->toArray(null,true,true,true);

  //create excell
  $objPHPExcel = PHPExcel_IOFactory::load(drupal_realpath($file->uri));
  $objPHPExcel->setActiveSheetIndex(0);

  $nodes = node_load_multiple(array(), array('type' => '2014_annual_campaign_survey_link'));

  if (!empty($nodes)) {
    foreach ($nodes as $node) {
      $cell = find_cell_by_value($node->title, $sheetData);
      $map = array('1' => 'C', '2' => 'D');
      if($phase = $node->field_2014ac_survey_used_phase) {
        $value = $phase[LANGUAGE_NONE][0]['value'];
        $objPHPExcel->getActiveSheet()->setCellValue($map[$value] . $cell, 1);
      }
    }
  }

  $objWriter = PHPExcel_IOFactory::createWriter($objPHPExcel, 'Excel2007');
  $export_dir = 'public://2014_annual_campaign/survey/export';
  if (!file_prepare_directory($export_dir)) {
    drupal_mkdir($export_dir, 0775, TRUE);
  }
  $objWriter->save(_create_download_filename($file));
}

function _create_download_filename($file){
  $export_dir = 'public://2014_annual_campaign/survey/export';
  if (!file_prepare_directory($export_dir)) {
    drupal_mkdir($export_dir, 0775, TRUE);
  }
  $info = explode('/', $file->uri);
  $filename = drupal_realpath($export_dir) . '/' . $info[5];
  return $filename;
}

function _get_import_export_log($fid) {
  $log_dir = 'public://2014_annual_campaign/survey/log';
  $log = file_get_contents(drupal_realpath($log_dir) . '/' . $fid);
  return $log;
}
/**
 * Find cell bu value
 */
function find_cell_by_value($value, $sheetData){

  foreach($sheetData as $index => $A) {
    if($A['A'] == $value) {
      return $index;
    }
  }
}

/**
 * Init the reader obj
 */
function _objreader_load($file, $filter = FALSE) {
  $inputFileName = drupal_realpath($file->uri);
  $inputFileType = 'Excel2007';
  $objReader = PHPExcel_IOFactory::createReader($inputFileType);
  if(is_array($filter)) {
    $readFilter = new ExcellReadFilter($filter);
    $objReader->setReadFilter($readFilter);
  }
  $objPHPExcel = $objReader->load($inputFileName);
  return $objPHPExcel;
}

/**
 *  User calendar form
 */
function ddms_2014ac_user_calendar_form($form, &$form_state) {

  $active = array('0' => 'All', '1' => '1 to 5 pins', '5' => 'more than 5 pins');

  if(isset($form_state['input']['value'])) {
    $filter = $form_state['input']['value'];
  } else {
    $filter = 0;
  }
    
  $result = _get_user_calendar_data($filter);
//var_dump($result);exit;
  $form = array();

  $form['filter'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Calendar'),
    '#collapsible' => FALSE,
  );
  $form['filter']['value'] = array(
    '#type' => 'radios',
    '#options' => $active,
    '#description' => t('Choose one of them to filter.'),
  );

  $form['filter']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Filter'),
  );

  $form['result']['#prefix'] = '<table>' . $result . '</table>';

  return $form;
}

/**
 * Submit User calendar form
 */
function ddms_2014ac_user_calendar_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;  
}

function _get_user_calendar_data($filter) {
  $thead = '<thead><tr><th>用户名</th><th>pin 数</th></tr></thead>';
  $tbody = '';
//var_dump($filter);exit;
  if($filter == '1') {
    $result = db_query('SELECT u.name, count(u.name) as count FROM {node} n LEFT JOIN {users} u ON n.uid = u.uid WHERE n.uid != :uid  AND n.type = :type GROUP BY u.name HAVING count(u.name) > :start AND count(u.name) < :end', array(':uid' => 0, ':type' => '2014_annual_campaign_pin', ':start' => 0, ':end' => 6));    
  } else {
    $result = db_query('SELECT u.name, count(u.name) as count FROM {node} n LEFT JOIN {users} u ON n.uid = u.uid WHERE n.uid != :uid  AND n.type = :type GROUP BY u.name HAVING count(u.name) > :start', array(':uid' => 0, ':type' => '2014_annual_campaign_pin', ':start' => $filter)); 
  }

  foreach ($result as $record) {
    $tbody .= "<tr><td>$record->name</td><td>$record->count</td></tr>";
  }
  $tbody = "<tbody>$tbody</tbody>";
  $table = $thead . $tbody;
  return $table;
}
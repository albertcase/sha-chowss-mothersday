<?php
/**
 * @file
 * ssbd_feature_static_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ssbd_feature_static_page_node_info() {
  $items = array(
    'static_page' => array(
      'name' => t('Static Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('静态页url与模板创建方法<br>
桌面版：<br>
1.进入 Url path settings 设置 URL alias<br>
2.根据 URL alias 设置模板名称<br>
模板命名规则<br>
1.如果使用默认html与page两层嵌套<br>
命名并创建页面为例: <br>
url = aa/bb/cc-dd-ee  <br>
tpl = node--staticpage--aa--bb--cc-dd-ee.tpl.php<br>
2.如果全新定义html与page两层嵌套<br>
命名并创建页面为 例:  <br>
url = aa/bb/cc-dd-ee  <br>
html--staticpage--aa--bb--cc-dd-ee.tpl.php<br>
page--staticpage--aa--bb--cc-dd-ee.tpl.php<br>
node--staticpage--aa--bb--cc-dd-ee.tpl.php<br>
MOBILE版：<br>
所有方式与桌面版一样只需在末尾加上--mobile 例： <br>
url = aa/bb/cc-dd-ee  <br>
html--staticpage--aa--bb--cc-dd-ee--mobile.tpl.php<br>
page--staticpage--aa--bb--cc-dd-ee--mobile.tpl.php<br>
node--staticpage--aa--bb--cc-dd-ee--mobile.tpl.php<br>'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

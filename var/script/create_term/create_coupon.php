#!/usr/bin/env php
<?php

/**
 * @file
 * Dumps a Drupal 7 database into a PHP script to test the upgrade process.
 *
 * Run this script at the root of an existing Drupal 7 installation.
 *
 * The output of this script is a PHP script that can be run inside Drupal 7
 * and recreates the Drupal 7 database as dumped. Transient data from cache,
 * session, and watchdog tables are not recorded.
 */

// Define default settings.
define('DRUPAL_ROOT', getcwd());
$cmd = 'index.php';
$_SERVER['HTTP_HOST']       = 'default';
$_SERVER['REMOTE_ADDR']     = '127.0.0.1';
$_SERVER['SERVER_SOFTWARE'] = NULL;
$_SERVER['REQUEST_METHOD']  = 'GET';
$_SERVER['QUERY_STRING']    = '';
$_SERVER['PHP_SELF']        = $_SERVER['REQUEST_URI'] = '/';
$_SERVER['HTTP_USER_AGENT'] = 'console';

// Bootstrap Drupal.
include_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
set_time_limit(0);
$handle = fopen('./var/script/create_term/20.txt', 'r');
$consolation_term = taxonomy_get_term_by_name('ESHOP20元优惠券');
$type = array_shift($consolation_term)->tid;
while(!feof($handle)){
    $code=fgets($handle, 1024);
    db_insert("cssmsd_coupon")->fields(array('coupon_code'=>$code,'type'=>$type,'status'=>'0'))->execute();
}
fclose($handle);
$handle = fopen('./var/script/create_term/50.txt', 'r');
$consolation_term = taxonomy_get_term_by_name('ESHOP50元优惠券');
$type = array_shift($consolation_term)->tid;
while(!feof($handle)){
    $code=fgets($handle, 1024);
    db_insert("cssmsd_coupon")->fields(array('coupon_code'=>$code,'type'=>$type,'status'=>'0'))->execute();
}
fclose($handle);

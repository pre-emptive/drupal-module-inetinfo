<?php

// $Id: inetinfo.admin.inc,v 1.1 2008/09/10 13:09:44 ralph Exp $

// inetinfo.admin.inc - Administrative functions

/**
 * Provide a form of settings for the module. This function is used to show the
 * administration settings page and the block settings page.
 * @param none
 * @return an array of form items
 */
function inetinfo_admin_settings_form() {
  $form = array();

  $form['core'] = array(
    '#type' => 'fieldset',
    '#title' => t('Module Configuration'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['core']['inetinfo_use_ajax'] = array(
    '#type' => 'radios',
    '#title' => t('Use Ajax for Information Screen'),
    '#description' => t('The information screen can be displayed in plain HTML (which takes longer to load) or with Ajax with information being filled in asynchronously.'),
    '#options' => array(0 => t('Plain HTML'), 1 => t('Asynchronous Ajax')),
    '#default_value' => variable_get('inetinfo_use_ajax',0),
  );

  $form['geo'] = array(
    '#type' => 'fieldset',
    '#title' => t('GeoIP Lookup Configuration'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['geo']['inetinfo_geoip_lookup_type'] = array(
    '#type' => 'radios',
    '#title' => t('GeoIP Lookup Method'),
    '#description' => t('The information screen can be displayed in plain HTML (which takes longer to load) or with Ajax with information being filled in asynchronously.'),
    '#options' => array('none' => t('Disabled - no GeoIP lookups'), 'cmd' => t('Shell Command'), 'url' => t('Internet Web Service')),
    '#default_value' => variable_get('inetinfo_geoip_lookup_type', 'cmd'),
  );
  $form['geo']['inetinfo_geoip_lookup_cmd'] = array(
    '#type' => 'textfield',
    '#title' => t('GeoIP Lookup Shell Command'),
    '#description' => t('The shell command used to perform Geo lookups. %HOST% is substituted with the hostname/IP address to lookup. Eg. "/usr/bin/geoiplookup %HOST%"'),
    '#default_value' => variable_get('inetinfo_geoip_lookup_cmd', '/usr/bin/geoiplookup %HOST%'),
  );

  $form['geo']['inetinfo_geoip_lookup_url'] = array(
    '#type' => 'textfield',
    '#title' => t('GeoIP Lookup Web Service'),
    '#description' => t('The URL used for Web Service GeoIP lookups. %HOST% is substituted with the hostname/IP address to lookup. Eg. "http://api.hostip.info/get_html.php?ip=%HOST%"'),
    '#default_value' => variable_get('inetinfo_geoip_lookup_url', 'http://api.hostip.info/get_html.php?ip=%HOST%'),
  );

  $form['whois'] = array(
    '#type' => 'fieldset',
    '#title' => t('Whois Lookup Configuration'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['whois']['inetinfo_whois_lookup_type'] = array(
    '#type' => 'radios',
    '#title' => t('Whois Lookup Method'),
    '#description' => t('The information screen can be displayed in plain HTML (which takes longer to load) or with Ajax with information being filled in asynchronously.'),
    '#options' => array('none' => t('Disabled - no Whois lookups'), 'cmd' => t('Shell Command'), 'php' => t('Online API with PHP')),
    '#default_value' => variable_get('inetinfo_whois_lookup_type', 'cmd'),
  );
  $form['whois']['inetinfo_whois_lookup_cmd'] = array(
    '#type' => 'textfield',
    '#title' => t('Whois Lookup Shell Command'),
    '#description' => t('The shell command used to perform Whois lookups. %HOST% is substituted with the hostname/IP address to lookup. Eg. "/usr/bin/whois %HOST%"'),
    '#default_value' => variable_get('inetinfo_whois_lookup_cmd', '/usr/bin/whois %HOST%'),
  );

  return system_settings_form($form);
}

// The following line is for Vim users - please don't delete it.
// vim: set filetype=php expandtab tabstop=2 shiftwidth=2:

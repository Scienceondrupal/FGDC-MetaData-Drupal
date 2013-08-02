<?php

/**
 * This module was developed with initial funding from the NSF EPsCOR Grant.  Currently, the module is being maintained with funding from the NASA ACCESS Grant.
 * Copyright (c) 2013, Information Technology & Systems Center.  University of Alabama in Huntsville
 * All rights reserved.
 * Redistribution and use of the module, with or without modification, are permitted with proper credit to Information Technology & Systems Center,  University of Alabama in Huntsville.
 */

/**
 * @file
 * metadata_catalog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function metadata_catalog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function metadata_catalog_node_info() {
  $items = array(
    'ct_metadata_core' => array(
      'name' => t('Metadata'),
      'base' => 'node_content',
      'description' => t('Use Metadata for storing FGDC standard XML contents over it, to export XML to nodes.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

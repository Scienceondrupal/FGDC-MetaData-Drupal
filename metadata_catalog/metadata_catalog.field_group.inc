<?php
/**
 * @file
 * metadata_catalog.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function metadata_catalog_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_altsys|node|ct_metadata_core|form';
  $field_group->group_name = 'group_altsys';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical_coordinate_sys';
  $field_group->data = array(
    'label' => 'Altitude System Definition',
    'weight' => '1',
    'children' => array(
      0 => 'field_altdatum',
      1 => 'field_altenc',
      2 => 'field_altres',
      3 => 'field_altunits',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_altsys|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attr_hori_tab_grp|field_collection_item|field_attr|form';
  $field_group->group_name = 'group_attr_hori_tab_grp';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_attr';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attribute hori tab grp',
    'weight' => '7',
    'children' => array(
      0 => 'group_entiry_attr_general',
      1 => 'group_entity_attr_dates',
      2 => 'group_attrdomv',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_attr_hori_tab_grp|field_collection_item|field_attr|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attrdomv|field_collection_item|field_attr|form';
  $field_group->group_name = 'group_attrdomv';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_attr';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attr_hori_tab_grp';
  $field_group->data = array(
    'label' => 'Attribute Domain Values',
    'weight' => '9',
    'children' => array(
      0 => 'field_attrdomv',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_attrdomv|field_collection_item|field_attr|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_citation_contact|node|ct_metadata_core|form';
  $field_group->group_name = 'group_citation_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Point of Contact ',
    'weight' => '13',
    'children' => array(
      0 => 'field_cnttdd',
      1 => 'field_cont_cit_email',
      2 => 'field_cont_cit_fax',
      3 => 'field_cont_cit_name_org',
      4 => 'field_cont_cit_name_person',
      5 => 'field_cont_cit_phone',
      6 => 'field_iden_originator_add',
      7 => 'field_position',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Point of Contact ',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_citation_contact|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_citation|node|ct_metadata_core|form';
  $field_group->group_name = 'group_citation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Citation',
    'weight' => '5',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_geoform',
      2 => 'field_issue',
      3 => 'field_onlink',
      4 => 'field_origin',
      5 => 'field_othercit',
      6 => 'field_pubdate',
      7 => 'field_publish',
      8 => 'field_pubplace',
      9 => 'field_pubtime',
      10 => 'field_sername',
      11 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_citation|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_constraints|node|ct_metadata_core|form';
  $field_group->group_name = 'group_constraints';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Constraints',
    'weight' => '12',
    'children' => array(
      0 => 'field_core_res_access',
      1 => 'field_core_res_constraint',
      2 => 'field_core_res_quality',
      3 => 'field_data_set_credit',
      4 => 'field_native',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_constraints|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_core_basic_info|node|ct_metadata_core|form';
  $field_group->group_name = 'group_core_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_description',
      1 => 'field_core_resource_lang',
      2 => 'field_purpose',
      3 => 'field_supplinf',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_core_basic_info|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_core_extent_horizontal|node|ct_metadata_core|form';
  $field_group->group_name = 'group_core_extent_horizontal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Geographic Extent - Horizontal',
    'weight' => '9',
    'children' => array(
      0 => 'field_core_lat_n',
      1 => 'field_core_lat_s',
      2 => 'field_core_long_e',
      3 => 'field_core_long_w',
      4 => 'field_dsgpoly',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_core_extent_horizontal|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_core_extent_temporal|node|ct_metadata_core|form';
  $field_group->group_name = 'group_core_extent_temporal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Identification Time Period and Status',
    'weight' => '8',
    'children' => array(
      0 => 'field_i_iden_timeperiod',
      1 => 'field_progress',
      2 => 'field_updatefrequency',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Identification Time Period and Status',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'The temporal extent during which the resource was collected or for which the resource is valid. NOTE: Enter geologic time units as temporal keywords!',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_core_extent_temporal|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_core_extent_vertical|node|ct_metadata_core|form';
  $field_group->group_name = 'group_core_extent_vertical';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Geographic Extent - Vertical',
    'weight' => '10',
    'children' => array(
      0 => 'field_core_elev_max',
      1 => 'field_core_elev_min',
      2 => 'field_core_elev_surface',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Geographic Extent - Vertical',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Elevations extent for resources such as borehole samples and well logs in Meters relative to mean sea level.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_core_extent_vertical|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_crossref|node|ct_metadata_core|form';
  $field_group->group_name = 'group_crossref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Cross Reference',
    'weight' => '16',
    'children' => array(
      0 => 'field_citation',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_crossref|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_d_attraccr|node|ct_metadata_core|form';
  $field_group->group_name = 'group_d_attraccr';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dataquality_grp';
  $field_group->data = array(
    'label' => 'Data Quality Attribute Accuracy',
    'weight' => '14',
    'children' => array(
      0 => 'field_d_accuracy_assessment',
      1 => 'field_d_attraccr',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_d_attraccr|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_d_process_step|node|ct_metadata_core|form';
  $field_group->group_name = 'group_d_process_step';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dataquality_grp';
  $field_group->data = array(
    'label' => 'Data Quality Process Step',
    'weight' => '17',
    'children' => array(
      0 => 'field_d_process_step',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_d_process_step|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_d_source_info|node|ct_metadata_core|form';
  $field_group->group_name = 'group_d_source_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dataquality_grp';
  $field_group->data = array(
    'label' => 'Data Quality Source Citation',
    'weight' => '16',
    'children' => array(
      0 => 'field_d_sourcecitation',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Data Quality Source Citation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_d_source_info|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_organization|node|ct_metadata_core|form';
  $field_group->group_name = 'group_data_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadata';
  $field_group->data = array(
    'label' => 'Data Organization',
    'weight' => '5',
    'children' => array(
      0 => 'field_colcount',
      1 => 'field_direct_spatial_ref',
      2 => 'field_indirect_spatial_ref',
      3 => 'field_rasttype',
      4 => 'field_rowcount',
      5 => 'field_sdtsterm',
      6 => 'field_select_sdts_vpf',
      7 => 'field_vpflevel',
      8 => 'field_vpfterm',
      9 => 'field_vrtcount',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_data_organization|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_quality_attribute_acc|node|ct_metadata_core|default';
  $field_group->group_name = 'group_data_quality_attribute_acc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_dataquality';
  $field_group->data = array(
    'label' => 'Data Quality Attribute Accuracy',
    'weight' => '2',
    'children' => array(
      0 => 'field_d_accuracy_assessment',
      1 => 'field_d_attraccr',
      2 => 'field_d_sourcecitation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_data_quality_attribute_acc|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_quality_general|node|ct_metadata_core|form';
  $field_group->group_name = 'group_data_quality_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dataquality_grp';
  $field_group->data = array(
    'label' => 'Data Quality General',
    'weight' => '13',
    'children' => array(
      0 => 'field_d_cloud',
      1 => 'field_d_complete',
      2 => 'field_d_logic',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_data_quality_general|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_quality|node|ct_metadata_core|form';
  $field_group->group_name = 'group_data_quality';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadata';
  $field_group->data = array(
    'label' => 'Data Quality',
    'weight' => '4',
    'children' => array(
      0 => 'group_dataquality_grp',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_data_quality|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dataquality_grp|node|ct_metadata_core|form';
  $field_group->group_name = 'group_dataquality_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_data_quality';
  $field_group->data = array(
    'label' => 'Data Quality Group',
    'weight' => '105',
    'children' => array(
      0 => 'group_d_attraccr',
      1 => 'group_d_process_step',
      2 => 'group_d_source_info',
      3 => 'group_data_quality_general',
      4 => 'group_postional_accuracy',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dataquality_grp|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_datetime|field_collection_item|field_i_iden_timeperiod|form';
  $field_group->group_name = 'group_datetime';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_i_iden_timeperiod';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date/Time',
    'weight' => '18',
    'children' => array(
      0 => 'group_single_datetime',
      1 => 'group_multiple_datetime',
      2 => 'group_range_datetime',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_datetime|field_collection_item|field_i_iden_timeperiod|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_depthsys|node|ct_metadata_core|form';
  $field_group->group_name = 'group_depthsys';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_vertical_coordinate_sys';
  $field_group->data = array(
    'label' => 'Depth System Definition',
    'weight' => '2',
    'children' => array(
      0 => 'field_depthdn',
      1 => 'field_depthdu',
      2 => 'field_depthem',
      3 => 'field_depthres',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_depthsys|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dialinst|field_collection_item|field_computer|form';
  $field_group->group_name = 'group_dialinst';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_computer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dialup Instructions',
    'weight' => '1',
    'children' => array(
      0 => 'field_lowbps',
      1 => 'field_highbps',
      2 => 'field_numdata',
      3 => 'field_numstop',
      4 => 'field_parity',
      5 => 'field_compress',
      6 => 'field_dialtel',
      7 => 'field_dialfile',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dialinst|field_collection_item|field_computer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_digform_gen|field_collection_item|field_digform|form';
  $field_group->group_name = 'group_digform_gen';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_digform';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_digform';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '10',
    'children' => array(
      0 => 'field_formname',
      1 => 'field_formvern',
      2 => 'field_formverd',
      3 => 'field_formspec',
      4 => 'field_formcont',
      5 => 'field_filedec',
      6 => 'field_transize',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_digform_gen|field_collection_item|field_digform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_digform|field_collection_item|field_stdorder|form';
  $field_group->group_name = 'group_digform';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_stdorder';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_stdorder';
  $field_group->data = array(
    'label' => 'Digital Form',
    'weight' => '8',
    'children' => array(
      0 => 'field_digform',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_digform|field_collection_item|field_stdorder|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_altitude_system|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_altitude_system';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_spatial_ref';
  $field_group->data = array(
    'label' => 'Altitude System Definition',
    'weight' => '125',
    'children' => array(
      0 => 'field_altdatum',
      1 => 'field_altenc',
      2 => 'field_altres',
      3 => 'field_altunits',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_altitude_system|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_attr_dates|field_collection_item|field_attr|default';
  $field_group->group_name = 'group_dis_attr_dates';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_attr';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attribute Dates',
    'weight' => '1',
    'children' => array(
      0 => 'field_attr_dates',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Attribute Dates',
      'instance_settings' => array(
        'classes' => 'fieldset_singleline',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_dis_attr_dates|field_collection_item|field_attr|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_attrdomainval|field_collection_item|field_attr|default';
  $field_group->group_name = 'group_dis_attrdomainval';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_attr';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attribute Domain Values',
    'weight' => '9',
    'children' => array(
      0 => 'field_attrdomv',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Attribute Domain Values',
      'instance_settings' => array(
        'classes' => 'fieldset_singleline',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_dis_attrdomainval|field_collection_item|field_attr|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_attribute|field_collection_item|field_en_detail_desc|default';
  $field_group->group_name = 'group_dis_attribute';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_en_detail_desc';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attribute',
    'weight' => '1',
    'children' => array(
      0 => 'field_attr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_attribute|field_collection_item|field_en_detail_desc|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_browse_graphics|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_browse_graphics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Browse Graphics',
    'weight' => '10',
    'children' => array(
      0 => 'field_i_browse_graphics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_browse_graphics|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_citation|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_citation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Citation',
    'weight' => '1',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_geoform',
      2 => 'field_issue',
      3 => 'field_onlink',
      4 => 'field_origin',
      5 => 'field_othercit',
      6 => 'field_pubdate',
      7 => 'field_publish',
      8 => 'field_pubplace',
      9 => 'field_pubtime',
      10 => 'field_sername',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Citation',
      'instance_settings' => array(
        'classes' => 'singleline',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_dis_citation|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_constraints|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_constraints';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Constraints',
    'weight' => '8',
    'children' => array(
      0 => 'field_core_res_access',
      1 => 'field_core_res_constraint',
      2 => 'field_core_res_quality',
      3 => 'field_data_set_credit',
      4 => 'field_native',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_constraints|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_d_srccitation|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_d_srccitation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_dataquality';
  $field_group->data = array(
    'label' => 'Process Step',
    'weight' => '3',
    'children' => array(
      0 => 'field_d_process_step',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Process Step',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_dis_d_srccitation|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_data_quality_gen|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_data_quality_gen';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_dataquality';
  $field_group->data = array(
    'label' => 'Data Quality General',
    'weight' => '1',
    'children' => array(
      0 => 'field_d_cloud',
      1 => 'field_d_complete',
      2 => 'field_d_logic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_data_quality_gen|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_dataorganization|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_dataorganization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_metadata';
  $field_group->data = array(
    'label' => 'Data Organization',
    'weight' => '3',
    'children' => array(
      0 => 'field_colcount',
      1 => 'field_direct_spatial_ref',
      2 => 'field_indirect_spatial_ref',
      3 => 'field_rasttype',
      4 => 'field_rowcount',
      5 => 'field_sdtsterm',
      6 => 'field_select_sdts_vpf',
      7 => 'field_vpflevel',
      8 => 'field_vpfterm',
      9 => 'field_vrtcount',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_dataorganization|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_dataquality|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_dataquality';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_metadata';
  $field_group->data = array(
    'label' => 'Data Quality',
    'weight' => '2',
    'children' => array(
      0 => 'group_data_quality_attribute_acc',
      1 => 'group_dis_d_srccitation',
      2 => 'group_dis_data_quality_gen',
      3 => 'group_dis_positionalacc',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_dataquality|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_depthsystem|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_depthsystem';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_spatial_ref';
  $field_group->data = array(
    'label' => 'Depth System Definition',
    'weight' => '126',
    'children' => array(
      0 => 'field_depthdn',
      1 => 'field_depthdu',
      2 => 'field_depthem',
      3 => 'field_depthres',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_depthsystem|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_description|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_description';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '3',
    'children' => array(
      0 => 'field_core_description',
      1 => 'field_core_resource_lang',
      2 => 'field_purpose',
      3 => 'field_supplinf',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_description|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_distribution|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_distribution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_metadata';
  $field_group->data = array(
    'label' => 'Distribution',
    'weight' => '6',
    'children' => array(
      0 => 'field_distribution',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_distribution|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_entity_attr_gen|field_collection_item|field_attr|default';
  $field_group->group_name = 'group_dis_entity_attr_gen';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_attr';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_attrlabl',
      1 => 'field_attrdef',
      2 => 'field_attrdefs',
      3 => 'field_attrva',
      4 => 'field_attrvae',
      5 => 'field_attrmfrq',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'General',
      'instance_settings' => array(
        'classes' => 'fieldset_singleline',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_dis_entity_attr_gen|field_collection_item|field_attr|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_entity_attribute|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_entity_attribute';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_metadata';
  $field_group->data = array(
    'label' => 'Entity Attribute',
    'weight' => '5',
    'children' => array(
      0 => 'field_en_detail_desc',
      1 => 'field_en_overview',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_entity_attribute|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_entitytype|field_collection_item|field_en_detail_desc|default';
  $field_group->group_name = 'group_dis_entitytype';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_en_detail_desc';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Entity Type',
    'weight' => '0',
    'children' => array(
      0 => 'field_enttypl',
      1 => 'field_enttypd',
      2 => 'field_enttypds',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_entitytype|field_collection_item|field_en_detail_desc|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_general|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '4',
    'children' => array(
      0 => 'field_attachment',
      1 => 'field_collectionid',
      2 => 'field_core_res_id',
      3 => 'field_permission',
      4 => 'field_resourcetheme',
      5 => 'field_resourcetype',
      6 => 'field_core_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_general|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_geodetic|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_geodetic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_spatial_ref';
  $field_group->data = array(
    'label' => 'Geodetic Model',
    'weight' => '124',
    'children' => array(
      0 => 'field_denflat',
      1 => 'field_ellips',
      2 => 'field_horizdn',
      3 => 'field_semiaxis',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_geodetic|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_geographics|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_geographics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_spatial_ref';
  $field_group->data = array(
    'label' => 'Geographics',
    'weight' => '123',
    'children' => array(
      0 => 'field_geogunit',
      1 => 'field_latres',
      2 => 'field_longres',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_geographics|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_identification|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_identification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_metadata';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '1',
    'children' => array(
      0 => 'field_citation',
      1 => 'field_core_template',
      2 => 'field_secsys',
      3 => 'group_dis_browse_graphics',
      4 => 'group_dis_citation',
      5 => 'group_dis_constraints',
      6 => 'group_dis_description',
      7 => 'group_dis_general',
      8 => 'group_dis_keywords',
      9 => 'group_dis_pointofcontact',
      10 => 'group_dis_securityinfo',
      11 => 'group_dis_spatial_domain',
      12 => 'group_dis_status',
      13 => 'group_dis_timeperiod',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_identification|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_keywords|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_keywords';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Keywords',
    'weight' => '7',
    'children' => array(
      0 => 'field_place_keywords',
      1 => 'field_stratum_keywords',
      2 => 'field_temporal_keywords',
      3 => 'field_themekeywords',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_keywords|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_local|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_local';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_spatial_ref';
  $field_group->data = array(
    'label' => 'Local',
    'weight' => '127',
    'children' => array(
      0 => 'field_localdes',
      1 => 'field_localgeo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_local|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_metadata_ref|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_metadata_ref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_metadata';
  $field_group->data = array(
    'label' => 'Metadata Reference',
    'weight' => '9',
    'children' => array(
      0 => 'field_contact_info',
      1 => 'field_metac',
      2 => 'field_metd',
      3 => 'field_metextns',
      4 => 'field_metfrd',
      5 => 'field_metrd',
      6 => 'field_metstdn',
      7 => 'field_metstdv',
      8 => 'field_mettc',
      9 => 'field_metuc',
      10 => 'group_dis_metsec_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_metadata_ref|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_metadata|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'metadata display',
    'weight' => '1',
    'children' => array(
      0 => 'group_dis_dataorganization',
      1 => 'group_dis_dataquality',
      2 => 'group_dis_distribution',
      3 => 'group_dis_entity_attribute',
      4 => 'group_dis_identification',
      5 => 'group_dis_metadata_ref',
      6 => 'group_dis_spatial_ref',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_metadata|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_metsec_info|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_metsec_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_metadata_ref';
  $field_group->data = array(
    'label' => 'Metadata Security Information',
    'weight' => '194',
    'children' => array(
      0 => 'field_metsc',
      1 => 'field_metscs',
      2 => 'field_metshd',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_metsec_info|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_overview|field_collection_item|field_en_overview|default';
  $field_group->group_name = 'group_dis_overview';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_en_overview';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overview Description',
    'weight' => '0',
    'children' => array(
      0 => 'field_eaover',
      1 => 'field_eadetcit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_overview|field_collection_item|field_en_overview|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_planar|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_planar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_spatial_ref';
  $field_group->data = array(
    'label' => 'Planar',
    'weight' => '128',
    'children' => array(
      0 => 'field_planar',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_planar|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_pointofcontact|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_pointofcontact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Point of Contact',
    'weight' => '9',
    'children' => array(
      0 => 'field_cnttdd',
      1 => 'field_cont_cit_email',
      2 => 'field_cont_cit_fax',
      3 => 'field_cont_cit_name_org',
      4 => 'field_cont_cit_name_person',
      5 => 'field_cont_cit_phone',
      6 => 'field_iden_originator_add',
      7 => 'field_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_pointofcontact|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_positionalacc|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_positionalacc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_dataquality';
  $field_group->data = array(
    'label' => 'Positional Accuracy',
    'weight' => '229',
    'children' => array(
      0 => 'field_horizpar',
      1 => 'field_qhorizpa',
      2 => 'field_qvertpa',
      3 => 'field_vertaccr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_positionalacc|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_securityinfo|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_securityinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Security Information',
    'weight' => '13',
    'children' => array(
      0 => 'field_secclass',
      1 => 'field_sechandl',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_securityinfo|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_spatial_domain|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_spatial_domain';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Spatial Domain',
    'weight' => '6',
    'children' => array(
      0 => 'field_core_elev_max',
      1 => 'field_core_elev_min',
      2 => 'field_core_elev_surface',
      3 => 'field_core_lat_n',
      4 => 'field_core_lat_s',
      5 => 'field_core_long_e',
      6 => 'field_core_long_w',
      7 => 'field_core_mbr_wkt',
      8 => 'field_dsgpoly',
      9 => 'field_loc_x',
      10 => 'field_loc_y',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_spatial_domain|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_spatial_ref|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_spatial_ref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_metadata';
  $field_group->data = array(
    'label' => 'Spatial Reference',
    'weight' => '4',
    'children' => array(
      0 => 'group_dis_altitude_system',
      1 => 'group_dis_depthsystem',
      2 => 'group_dis_geodetic',
      3 => 'group_dis_geographics',
      4 => 'group_dis_local',
      5 => 'group_dis_planar',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_spatial_ref|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_src_timeperiod|field_collection_item|field_d_sourcecitation|default';
  $field_group->group_name = 'group_dis_src_timeperiod';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_sourcecitation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Source Time Period of Content',
    'weight' => '30',
    'children' => array(
      0 => 'field_i_iden_timeperiod',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_src_timeperiod|field_collection_item|field_d_sourcecitation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_srccitation_gen|field_collection_item|field_d_sourcecitation|default';
  $field_group->group_name = 'group_dis_srccitation_gen';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_sourcecitation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_srcscale',
      1 => 'field_typesrc',
      2 => 'field_srccitea',
      3 => 'field_srccontr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'General',
      'instance_settings' => array(
        'classes' => 'fieldset_singleline',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_dis_srccitation_gen|field_collection_item|field_d_sourcecitation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_srccitation|field_collection_item|field_d_sourcecitation|default';
  $field_group->group_name = 'group_dis_srccitation';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_sourcecitation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Source Citation',
    'weight' => '1',
    'children' => array(
      0 => 'field_title',
      1 => 'field_origin',
      2 => 'field_pubdate',
      3 => 'field_pubtime',
      4 => 'field_edition',
      5 => 'field_geoform',
      6 => 'field_onlink',
      7 => 'field_sername',
      8 => 'field_issue',
      9 => 'field_pubplace',
      10 => 'field_publish',
      11 => 'field_othercit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Source Citation',
      'instance_settings' => array(
        'classes' => 'fieldset_singleline',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_dis_srccitation|field_collection_item|field_d_sourcecitation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_status|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_status';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Status',
    'weight' => '11',
    'children' => array(
      0 => 'field_progress',
      1 => 'field_updatefrequency',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_status|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dis_timeperiod|node|ct_metadata_core|default';
  $field_group->group_name = 'group_dis_timeperiod';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_dis_identification';
  $field_group->data = array(
    'label' => 'Time Period',
    'weight' => '5',
    'children' => array(
      0 => 'field_i_iden_timeperiod',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_dis_timeperiod|node|ct_metadata_core|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_distribution_gen|field_collection_item|field_distribution|form';
  $field_group->group_name = 'group_distribution_gen';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_distribution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_distribution';
  $field_group->data = array(
    'label' => 'Distribution General',
    'weight' => '0',
    'children' => array(
      0 => 'field_resdesc',
      1 => 'field_distliab',
      2 => 'field_custom',
      3 => 'field_techpreq',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_distribution_gen|field_collection_item|field_distribution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_distribution|node|ct_metadata_core|form';
  $field_group->group_name = 'group_distribution';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadata';
  $field_group->data = array(
    'label' => 'Distribution',
    'weight' => '8',
    'children' => array(
      0 => 'field_distribution',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_distribution|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_distributor_time_period|field_collection_item|field_distribution|form';
  $field_group->group_name = 'group_distributor_time_period';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_distribution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_distribution';
  $field_group->data = array(
    'label' => 'Time Period',
    'weight' => '3',
    'children' => array(
      0 => 'field_i_iden_timeperiod',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_distributor_time_period|field_collection_item|field_distribution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_distributor|field_collection_item|field_distribution|form';
  $field_group->group_name = 'group_distributor';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_distribution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_distribution';
  $field_group->data = array(
    'label' => 'Distributor',
    'weight' => '2',
    'children' => array(
      0 => 'field_contact_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_distributor|field_collection_item|field_distribution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_encodinginfo|field_collection_item|field_planar|form';
  $field_group->group_name = 'group_encodinginfo';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_planar';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_planar_grp';
  $field_group->data = array(
    'label' => 'Encoding Information',
    'weight' => '7',
    'children' => array(
      0 => 'field_mapprojn',
      1 => 'field_stdparll',
      2 => 'field_longcm',
      3 => 'field_latprjo',
      4 => 'field_feast',
      5 => 'field_fnorth',
      6 => 'field_sfequat',
      7 => 'field_heightpt',
      8 => 'field_longpc',
      9 => 'field_latprjc',
      10 => 'field_sfctrlin',
      11 => 'field_azimangl',
      12 => 'field_azimptl',
      13 => 'field_obqllat',
      14 => 'field_obqllong',
      15 => 'field_svlong',
      16 => 'field_sfprjorg',
      17 => 'field_landsat',
      18 => 'field_pathnum',
      19 => 'field_sfctrmer',
      20 => 'field_utmzone',
      21 => 'field_upszone',
      22 => 'field_spcszone',
      23 => 'field_arczone',
      24 => 'field_othergrd',
      25 => 'field_localpd',
      26 => 'field_localpgi',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_encodinginfo|field_collection_item|field_planar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entiry_attr_general|field_collection_item|field_attr|form';
  $field_group->group_name = 'group_entiry_attr_general';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_attr';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attr_hori_tab_grp';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '7',
    'children' => array(
      0 => 'field_attrlabl',
      1 => 'field_attrdef',
      2 => 'field_attrdefs',
      3 => 'field_attrva',
      4 => 'field_attrvae',
      5 => 'field_attrmfrq',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_entiry_attr_general|field_collection_item|field_attr|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entity_attr_dates|field_collection_item|field_attr|form';
  $field_group->group_name = 'group_entity_attr_dates';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_attr';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_attr_hori_tab_grp';
  $field_group->data = array(
    'label' => 'Dates',
    'weight' => '8',
    'children' => array(
      0 => 'field_attr_dates',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_entity_attr_dates|field_collection_item|field_attr|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entity_attribute|node|ct_metadata_core|form';
  $field_group->group_name = 'group_entity_attribute';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadata';
  $field_group->data = array(
    'label' => 'Entity Attribute',
    'weight' => '7',
    'children' => array(
      0 => 'group_entityatt_des',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_entity_attribute|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entity_detail_descrip|node|ct_metadata_core|form';
  $field_group->group_name = 'group_entity_detail_descrip';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_entityatt_des';
  $field_group->data = array(
    'label' => 'Detailed Description',
    'weight' => '113',
    'children' => array(
      0 => 'field_en_detail_desc',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_entity_detail_descrip|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entity_overview_desc|node|ct_metadata_core|form';
  $field_group->group_name = 'group_entity_overview_desc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_entityatt_des';
  $field_group->data = array(
    'label' => 'Overview Description',
    'weight' => '114',
    'children' => array(
      0 => 'field_en_overview',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_entity_overview_desc|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entity_sub_attribute|field_collection_item|field_en_detail_desc|form';
  $field_group->group_name = 'group_entity_sub_attribute';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_en_detail_desc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_entitytype_attr';
  $field_group->data = array(
    'label' => 'Attribute',
    'weight' => '7',
    'children' => array(
      0 => 'field_attr',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_entity_sub_attribute|field_collection_item|field_en_detail_desc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entity_type|field_collection_item|field_en_detail_desc|form';
  $field_group->group_name = 'group_entity_type';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_en_detail_desc';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_entitytype_attr';
  $field_group->data = array(
    'label' => 'Entity Type',
    'weight' => '6',
    'children' => array(
      0 => 'field_enttypl',
      1 => 'field_enttypd',
      2 => 'field_enttypds',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_entity_type|field_collection_item|field_en_detail_desc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entityatt_des|node|ct_metadata_core|form';
  $field_group->group_name = 'group_entityatt_des';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_entity_attribute';
  $field_group->data = array(
    'label' => 'Entity Attribute Description',
    'weight' => '113',
    'children' => array(
      0 => 'group_entity_detail_descrip',
      1 => 'group_entity_overview_desc',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_entityatt_des|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_entitytype_attr|field_collection_item|field_en_detail_desc|form';
  $field_group->group_name = 'group_entitytype_attr';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_en_detail_desc';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Entity type and attribute',
    'weight' => '6',
    'children' => array(
      0 => 'group_entity_type',
      1 => 'group_entity_sub_attribute',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_entitytype_attr|field_collection_item|field_en_detail_desc|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|ct_metadata_core|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '7',
    'children' => array(
      0 => 'field_attachment',
      1 => 'field_collectionid',
      2 => 'field_core_met_uuid',
      3 => 'field_core_res_id',
      4 => 'field_core_template',
      5 => 'field_permission',
      6 => 'field_resourcetheme',
      7 => 'field_resourcetype',
      8 => 'field_core_url',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_general|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_geodetic_model|node|ct_metadata_core|form';
  $field_group->group_name = 'group_geodetic_model';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hori_coordinate_sys_grp';
  $field_group->data = array(
    'label' => 'Geodetic Model',
    'weight' => '107',
    'children' => array(
      0 => 'field_denflat',
      1 => 'field_ellips',
      2 => 'field_horizdn',
      3 => 'field_semiaxis',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_geodetic_model|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_h_geographic|node|ct_metadata_core|form';
  $field_group->group_name = 'group_h_geographic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hori_coordinate_sys_grp';
  $field_group->data = array(
    'label' => 'Geographic',
    'weight' => '106',
    'children' => array(
      0 => 'field_geogunit',
      1 => 'field_latres',
      2 => 'field_longres',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Geographic',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_h_geographic|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hori_coordinate_sys_grp|node|ct_metadata_core|form';
  $field_group->group_name = 'group_hori_coordinate_sys_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hori_coordinate_sys';
  $field_group->data = array(
    'label' => 'Group Horizontal Coordinate System',
    'weight' => '30',
    'children' => array(
      0 => 'group_geodetic_model',
      1 => 'group_h_geographic',
      2 => 'group_local',
      3 => 'group_planar',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_hori_coordinate_sys_grp|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hori_coordinate_sys|node|ct_metadata_core|form';
  $field_group->group_name = 'group_hori_coordinate_sys';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_spatial_ref_hori';
  $field_group->data = array(
    'label' => 'Horizontal Coordinate System',
    'weight' => '28',
    'children' => array(
      0 => 'group_hori_coordinate_sys_grp',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Horizontal Coordinate System',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_hori_coordinate_sys|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hori_process_contact|field_collection_item|field_d_process_step|form';
  $field_group->group_name = 'group_hori_process_contact';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_process_step';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_horigrp_process_step';
  $field_group->data = array(
    'label' => 'Process Contact',
    'weight' => '10',
    'children' => array(
      0 => 'field_contact_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_hori_process_contact|field_collection_item|field_d_process_step|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hori_process_step|field_collection_item|field_d_process_step|form';
  $field_group->group_name = 'group_hori_process_step';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_process_step';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_horigrp_process_step';
  $field_group->data = array(
    'label' => 'process step',
    'weight' => '9',
    'children' => array(
      0 => 'field_d_process_descp',
      1 => 'field_d_processdate',
      2 => 'field_d_processtime',
      3 => 'field_srcused',
      4 => 'field_srcprod',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_hori_process_step|field_collection_item|field_d_process_step|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horigrp_process_step|field_collection_item|field_d_process_step|form';
  $field_group->group_name = 'group_horigrp_process_step';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_process_step';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'process step group',
    'weight' => '0',
    'children' => array(
      0 => 'group_hori_process_step',
      1 => 'group_hori_process_contact',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_horigrp_process_step|field_collection_item|field_d_process_step|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_horizpa|node|ct_metadata_core|form';
  $field_group->group_name = 'group_horizpa';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_postional_accuracy';
  $field_group->data = array(
    'label' => 'Horizontal Positional Accuracy ',
    'weight' => '136',
    'children' => array(
      0 => 'field_horizpar',
      1 => 'field_qhorizpa',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_horizpa|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_i_browse_graphics|node|ct_metadata_core|form';
  $field_group->group_name = 'group_i_browse_graphics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Browse Graphics',
    'weight' => '14',
    'children' => array(
      0 => 'field_i_browse_graphics',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_i_browse_graphics|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identification_grp|node|ct_metadata_core|form';
  $field_group->group_name = 'group_identification_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification';
  $field_group->data = array(
    'label' => 'Identification Group',
    'weight' => '105',
    'children' => array(
      0 => 'group_citation_contact',
      1 => 'group_citation',
      2 => 'group_constraints',
      3 => 'group_core_basic_info',
      4 => 'group_core_extent_horizontal',
      5 => 'group_core_extent_temporal',
      6 => 'group_core_extent_vertical',
      7 => 'group_crossref',
      8 => 'group_i_browse_graphics',
      9 => 'group_keywords',
      10 => 'group_secinfo',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_identification_grp|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identification|node|ct_metadata_core|form';
  $field_group->group_name = 'group_identification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadata';
  $field_group->data = array(
    'label' => 'Identification',
    'weight' => '3',
    'children' => array(
      0 => 'group_identification_grp',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_identification|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_keywords|node|ct_metadata_core|form';
  $field_group->group_name = 'group_keywords';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Keywords',
    'weight' => '11',
    'children' => array(
      0 => 'field_place_keywords',
      1 => 'field_stratum_keywords',
      2 => 'field_temporal_keywords',
      3 => 'field_themekeywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_keywords|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_local|node|ct_metadata_core|form';
  $field_group->group_name = 'group_local';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hori_coordinate_sys_grp';
  $field_group->data = array(
    'label' => 'Local',
    'weight' => '148',
    'children' => array(
      0 => 'field_localdes',
      1 => 'field_localgeo',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_local|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata_contact|node|ct_metadata_core|form';
  $field_group->group_name = 'group_metadata_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadataref_horiref';
  $field_group->data = array(
    'label' => 'Metadata Contact',
    'weight' => '117',
    'children' => array(
      0 => 'field_contact_info',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_metadata_contact|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadataref_gen|node|ct_metadata_core|form';
  $field_group->group_name = 'group_metadataref_gen';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadataref_horiref';
  $field_group->data = array(
    'label' => 'Metadata Reference General',
    'weight' => '115',
    'children' => array(
      0 => 'field_metac',
      1 => 'field_metd',
      2 => 'field_metfrd',
      3 => 'field_metrd',
      4 => 'field_metstdn',
      5 => 'field_metstdv',
      6 => 'field_mettc',
      7 => 'field_metuc',
      8 => 'group_metsi',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Metadata Reference General',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_metadataref_gen|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadataref_horiref|node|ct_metadata_core|form';
  $field_group->group_name = 'group_metadataref_horiref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadataref';
  $field_group->data = array(
    'label' => 'Metadata Reference Horigrp',
    'weight' => '115',
    'children' => array(
      0 => 'group_metadata_contact',
      1 => 'group_metadataref_gen',
      2 => 'group_metextns',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_metadataref_horiref|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadataref|node|ct_metadata_core|form';
  $field_group->group_name = 'group_metadataref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadata';
  $field_group->data = array(
    'label' => 'Metadata Reference',
    'weight' => '9',
    'children' => array(
      0 => 'group_metadataref_horiref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_metadataref|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|ct_metadata_core|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '4',
    'children' => array(
      0 => 'group_data_organization',
      1 => 'group_data_quality',
      2 => 'group_distribution',
      3 => 'group_entity_attribute',
      4 => 'group_identification',
      5 => 'group_metadataref',
      6 => 'group_spacial_ref',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_metadata|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metextns|node|ct_metadata_core|form';
  $field_group->group_name = 'group_metextns';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadataref_horiref';
  $field_group->data = array(
    'label' => 'Extension',
    'weight' => '116',
    'children' => array(
      0 => 'field_metextns',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_metextns|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metsi|node|ct_metadata_core|form';
  $field_group->group_name = 'group_metsi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadataref_gen';
  $field_group->data = array(
    'label' => 'Metadata Security Information',
    'weight' => '124',
    'children' => array(
      0 => 'field_metsc',
      1 => 'field_metscs',
      2 => 'field_metshd',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_metsi|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_multiple_datetime|field_collection_item|field_i_iden_timeperiod|form';
  $field_group->group_name = 'group_multiple_datetime';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_i_iden_timeperiod';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_datetime';
  $field_group->data = array(
    'label' => 'Multiple Date/Time',
    'weight' => '21',
    'children' => array(
      0 => 'field_mul_calendar_datetime',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_multiple_datetime|field_collection_item|field_i_iden_timeperiod|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_networka|field_collection_item|field_computer|form';
  $field_group->group_name = 'group_networka';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_computer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Network Address',
    'weight' => '0',
    'children' => array(
      0 => 'field_networkr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_networka|field_collection_item|field_computer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_nondig|field_collection_item|field_stdorder|form';
  $field_group->group_name = 'group_nondig';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_stdorder';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_stdorder';
  $field_group->data = array(
    'label' => ' Non-digital Form',
    'weight' => '7',
    'children' => array(
      0 => 'field_nondig',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_nondig|field_collection_item|field_stdorder|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_offoptn|field_collection_item|field_digform|form';
  $field_group->group_name = 'group_offoptn';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_digform';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_digform';
  $field_group->data = array(
    'label' => 'Offline Transfer',
    'weight' => '12',
    'children' => array(
      0 => 'field_offoptn',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_offoptn|field_collection_item|field_digform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_onlinopt|field_collection_item|field_digform|form';
  $field_group->group_name = 'group_onlinopt';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_digform';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_digform';
  $field_group->data = array(
    'label' => 'Online Transfer Option',
    'weight' => '11',
    'children' => array(
      0 => 'field_onlinopt',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_onlinopt|field_collection_item|field_digform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_outer_gring|field_collection_item|field_dsgpoly|form';
  $field_group->group_name = 'group_outer_gring';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_dsgpoly';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Outer G-Ring',
    'weight' => '0',
    'children' => array(
      0 => 'field_dsgpolyo',
      1 => 'field_gring',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_outer_gring|field_collection_item|field_dsgpoly|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_planar_grp|field_collection_item|field_planar|form';
  $field_group->group_name = 'group_planar_grp';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_planar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Planar Grp',
    'weight' => '6',
    'children' => array(
      0 => 'group_planci',
      1 => 'group_encodinginfo',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_planar_grp|field_collection_item|field_planar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_planar|node|ct_metadata_core|form';
  $field_group->group_name = 'group_planar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hori_coordinate_sys_grp';
  $field_group->data = array(
    'label' => 'Planar',
    'weight' => '150',
    'children' => array(
      0 => 'field_planar',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_planar|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_planci|field_collection_item|field_planar|form';
  $field_group->group_name = 'group_planci';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_planar';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_planar_grp';
  $field_group->data = array(
    'label' => 'Planar Coordinate Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_plance',
      1 => 'field_planar_repre',
      2 => 'field_plandu',
      3 => 'field_coordrep',
      4 => 'field_distbrep',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_planci|field_collection_item|field_planar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_postional_accuracy|node|ct_metadata_core|form';
  $field_group->group_name = 'group_postional_accuracy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_dataquality_grp';
  $field_group->data = array(
    'label' => 'Positional Accuracy',
    'weight' => '15',
    'children' => array(
      0 => 'group_horizpa',
      1 => 'group_vertacc',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_postional_accuracy|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_range_datetime|field_collection_item|field_i_iden_timeperiod|form';
  $field_group->group_name = 'group_range_datetime';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_i_iden_timeperiod';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_datetime';
  $field_group->data = array(
    'label' => 'Range of Date/Time',
    'weight' => '22',
    'children' => array(
      0 => 'field_beginning_date',
      1 => 'field_beginning_time',
      2 => 'field_ending_date',
      3 => 'field_ending_time',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_range_datetime|field_collection_item|field_i_iden_timeperiod|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_reccap|field_collection_item|field_offoptn|form';
  $field_group->group_name = 'group_reccap';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_offoptn';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Recording Capacity ',
    'weight' => '4',
    'children' => array(
      0 => 'field_recden',
      1 => 'field_recdenu',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_reccap|field_collection_item|field_offoptn|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_secinfo|node|ct_metadata_core|form';
  $field_group->group_name = 'group_secinfo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_identification_grp';
  $field_group->data = array(
    'label' => 'Security Information',
    'weight' => '15',
    'children' => array(
      0 => 'field_secclass',
      1 => 'field_sechandl',
      2 => 'field_secsys',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_secinfo|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_single_datetime|field_collection_item|field_i_iden_timeperiod|form';
  $field_group->group_name = 'group_single_datetime';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_i_iden_timeperiod';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_datetime';
  $field_group->data = array(
    'label' => 'Single Date/Time',
    'weight' => '20',
    'children' => array(
      0 => 'field_time_of_day',
      1 => 'field_calendar_date',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_single_datetime|field_collection_item|field_i_iden_timeperiod|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spacial_ref|node|ct_metadata_core|form';
  $field_group->group_name = 'group_spacial_ref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_metadata';
  $field_group->data = array(
    'label' => 'Spacial Reference',
    'weight' => '6',
    'children' => array(
      0 => 'group_spatial_ref_hori',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_spacial_ref|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_spatial_ref_hori|node|ct_metadata_core|form';
  $field_group->group_name = 'group_spatial_ref_hori';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_spacial_ref';
  $field_group->data = array(
    'label' => 'Spatial Reference Horizontal Group',
    'weight' => '30',
    'children' => array(
      0 => 'group_hori_coordinate_sys',
      1 => 'group_vertical_coordinate_sys',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_spatial_ref_hori|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_src_citation|field_collection_item|field_d_sourcecitation|form';
  $field_group->group_name = 'group_src_citation';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_sourcecitation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_src_info';
  $field_group->data = array(
    'label' => 'Source Citation',
    'weight' => '18',
    'children' => array(
      0 => 'field_title',
      1 => 'field_origin',
      2 => 'field_pubdate',
      3 => 'field_pubtime',
      4 => 'field_edition',
      5 => 'field_geoform',
      6 => 'field_onlink',
      7 => 'field_sername',
      8 => 'field_issue',
      9 => 'field_pubplace',
      10 => 'field_publish',
      11 => 'field_othercit',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_src_citation|field_collection_item|field_d_sourcecitation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_src_info_general|field_collection_item|field_d_sourcecitation|form';
  $field_group->group_name = 'group_src_info_general';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_sourcecitation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_src_info';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '17',
    'children' => array(
      0 => 'field_srcscale',
      1 => 'field_typesrc',
      2 => 'field_srccitea',
      3 => 'field_srccontr',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_src_info_general|field_collection_item|field_d_sourcecitation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_src_info|field_collection_item|field_d_sourcecitation|form';
  $field_group->group_name = 'group_src_info';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_sourcecitation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Source Information',
    'weight' => '17',
    'children' => array(
      0 => 'group_src_info_general',
      1 => 'group_src_citation',
      2 => 'group_src_timeperiod',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_src_info|field_collection_item|field_d_sourcecitation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_src_timeperiod|field_collection_item|field_d_sourcecitation|form';
  $field_group->group_name = 'group_src_timeperiod';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_d_sourcecitation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_src_info';
  $field_group->data = array(
    'label' => 'Source Time Period of Content',
    'weight' => '19',
    'children' => array(
      0 => 'field_i_iden_timeperiod',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_src_timeperiod|field_collection_item|field_d_sourcecitation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stdorder|field_collection_item|field_distribution|form';
  $field_group->group_name = 'group_stdorder';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_distribution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_distribution';
  $field_group->data = array(
    'label' => 'Standard Order Process',
    'weight' => '1',
    'children' => array(
      0 => 'field_stdorder',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stdorder|field_collection_item|field_distribution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_digform|field_collection_item|field_digform|form';
  $field_group->group_name = 'group_sub_digform';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_digform';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sub Digital Form',
    'weight' => '10',
    'children' => array(
      0 => 'group_digform_gen',
      1 => 'group_onlinopt',
      2 => 'group_offoptn',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_sub_digform|field_collection_item|field_digform|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_distribution|field_collection_item|field_distribution|form';
  $field_group->group_name = 'group_sub_distribution';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_distribution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sub Distribution',
    'weight' => '1',
    'children' => array(
      0 => 'group_distributor',
      1 => 'group_distributor_time_period',
      2 => 'group_distribution_gen',
      3 => 'group_stdorder',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_sub_distribution|field_collection_item|field_distribution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_stdorder_gen|field_collection_item|field_stdorder|form';
  $field_group->group_name = 'group_sub_stdorder_gen';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_stdorder';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_stdorder';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '6',
    'children' => array(
      0 => 'field_fees',
      1 => 'field_ordering',
      2 => 'field_turnarnd',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sub_stdorder_gen|field_collection_item|field_stdorder|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_stdorder|field_collection_item|field_stdorder|form';
  $field_group->group_name = 'group_sub_stdorder';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_stdorder';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'sub standard order',
    'weight' => '6',
    'children' => array(
      0 => 'group_sub_stdorder_gen',
      1 => 'group_nondig',
      2 => 'group_digform',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_sub_stdorder|field_collection_item|field_stdorder|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vertacc|node|ct_metadata_core|form';
  $field_group->group_name = 'group_vertacc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_postional_accuracy';
  $field_group->data = array(
    'label' => 'Vertical Positional Accuracy ',
    'weight' => '138',
    'children' => array(
      0 => 'field_qvertpa',
      1 => 'field_vertaccr',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_vertacc|node|ct_metadata_core|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vertical_coordinate_sys|node|ct_metadata_core|form';
  $field_group->group_name = 'group_vertical_coordinate_sys';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ct_metadata_core';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_spatial_ref_hori';
  $field_group->data = array(
    'label' => 'Vertical Coordinate System',
    'weight' => '29',
    'children' => array(
      0 => 'group_altsys',
      1 => 'group_depthsys',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_vertical_coordinate_sys|node|ct_metadata_core|form'] = $field_group;

  return $export;
}

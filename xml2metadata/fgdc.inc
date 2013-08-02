<?php

/**
 * This module was developed with initial funding from the NSF EPsCOR Grant.  Currently, the module is being maintained with funding from the NASA ACCESS Grant.
 * Copyright (c) 2013, Information Technology & Systems Center.  University of Alabama in Huntsville
 * All rights reserved.
 * Redistribution and use of the module, with or without modification, are permitted with proper credit to Information Technology & Systems Center,  University of Alabama in Huntsville.
 */
 
 /**
 * @file
 * fgdc.inc
 */
 
function exportToFGDC() {
    return drupal_get_form('fgdc_form');
}

function fgdc_form() {
    $nid=$_REQUEST['nid'];
    $file_path = getFullFilePath($nid);
    $node = node_load($nid);
    if (!file_exists($file_path)) {
        writeXMLFile($file_path,$node);
    }
    drupal_goto($file_path);
}


function getFullFilePath($nid){
    $fileName = "metadata_" . $nid . ".xml";
    $file_path = variable_get('file_public_path', 'sites/default/files') . '/xml_metadata/' . $fileName;
    return $file_path;
}

function writeXMLFile($file_path,$node){
    $node->language = LANGUAGE_NONE;
    $fh = fopen($file_path, 'w') or die("can't open file");

    $xml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<metadata>
<idinfo>
<citation>
<citeinfo>" . PHP_EOL;

    foreach ($node->field_origin[$node->language] as $origin) {
        $xml.="<origin>" . $origin['value'] . "</origin>" . PHP_EOL;
    }

    $xml.="<title>" . $node->title . "</title>" . PHP_EOL;

    if (isset($node->field_pubdate[$node->language])) {
        $xml.="<pubdate>" . $node->field_pubdate[$node->language][0]['value'] . "</pubdate>" . PHP_EOL;
    }
    if (isset($node->field_pubtime[$node->language]) && $node->field_pubtime[$node->language][0]['value'] != "") {
        $xml.="<pubtime>" . $node->field_pubtime[$node->language][0]['value'] . "</pubtime>" . PHP_EOL;
    }
    if (isset($node->field_edition[$node->language]) && $node->field_edition[$node->language][0]['value'] != "") {
        $xml.="<edition>" . $node->field_edition[$node->language][0]['value'] . "</edition>" . PHP_EOL;
    }
    if (isset($node->field_geoform[$node->language]) && $node->field_geoform[$node->language][0]['value'] != "") {
        $xml.="<geoform>" . $node->field_geoform[$node->language][0]['value'] . "</geoform>" . PHP_EOL;
    }
    foreach ($node->field_onlink[$node->language] as $onlink) {
        $xml.="<onlink>" . $onlink['url'] . "</onlink>" . PHP_EOL;
    }
    if (isset($node->field_sername[$node->language]) && $node->field_sername[$node->language][0]['value'] != "") {
        $xml.="<sername>" . $node->field_sername[$node->language][0]['value'] . "</sername>" . PHP_EOL;
    }

    if (isset($node->field_issue[$node->language]) && $node->field_issue[$node->language][0]['value'] != "") {
        $xml.="<issue>" . $node->field_issue[$node->language][0]['value'] . "</issue>" . PHP_EOL;
    }

    $maintag = "";
    if (isset($node->field_pubplace[$node->language]) && $node->field_pubplace[$node->language][0]['value'] != "") {
        $pubinfo.="<pubplace>" . $node->field_pubplace[$node->language][0]['value'] . "</pubplace>" . PHP_EOL;
    }
    if (isset($node->field_publish[$node->language]) && $node->field_publish[$node->language][0]['value'] != "") {
        $pubinfo.="<publish>" . $node->field_publish[$node->language][0]['value'] . "</publish>" . PHP_EOL;
    }
    if (pubinfo != "") {
        $xml.="<pubinfo>" . PHP_EOL . $pubinfo . "</pubinfo>" . PHP_EOL;
    }
    if (isset($node->field_othercit[$node->language]) && $node->field_othercit[$node->language][0]['value'] != "") {
        $xml.="<othercit>" . $node->field_othercit[$node->language][0]['value'] . "</othercit>" . PHP_EOL;
    }

    $xml.="</citeinfo>" . PHP_EOL . "</citation>" . PHP_EOL;

    $maintag = "";
    if (isset($node->field_core_description[$node->language]) && $node->field_core_description[$node->language][0]['value'] != "") {
        $maintag.="<abstract>" . $node->field_core_description[$node->language][0]['value'] . "</abstract>" . PHP_EOL;
    }
    if (isset($node->field_purpose[$node->language]) && $node->field_purpose[$node->language][0]['value'] != "") {
        $maintag.="<purpose>" . $node->field_purpose[$node->language][0]['value'] . "</purpose>" . PHP_EOL;
    }
    if (isset($node->field_supplinf[$node->language]) && $node->field_supplinf[$node->language][0]['value'] != "") {
        $maintag.="<supplinf>" . $node->field_supplinf[$node->language][0]['value'] . "</supplinf>" . PHP_EOL;
    }
    if ($maintag != "") {
        $xml.="<descript>" . PHP_EOL . $maintag . "</descript>" . PHP_EOL;
    }

    if (isset($node->field_i_iden_timeperiod[$node->language])) {
        $field_collection = entity_load('field_collection_item', array($node->field_i_iden_timeperiod[$node->language][0]['value']));
        foreach ($field_collection as $field_entity) {
            $timeperd = "";
            if (isset($field_entity->field_currentness_ref[$node->language]) && $field_entity->field_currentness_ref[$node->language][0]['value'] != "") {
                $timeperd.="<current>" . $field_entity->field_currentness_ref[$node->language][0]['value'] . "</current>" . PHP_EOL;
            }
            $timeinfo = "";
            $sngdate = "";

            if (isset($field_entity->field_calendar_date[$node->language]) && $field_entity->field_calendar_date[$node->language][0]['value'] != "") {
                $sngdate.="<caldate>" . $field_entity->field_calendar_date[$node->language][0]['value'] . "</caldate>" . PHP_EOL;
            }
            if (isset($field_entity->field_time_of_day[$node->language]) && $field_entity->field_time_of_day[$node->language][0]['value'] != "") {
                $sngdate.="<time>" . $field_entity->field_time_of_day[$node->language][0]['value'] . "</time>" . PHP_EOL;
            }
            if ($sngdate != "") {
                $sngdate = "<sngdate>" . PHP_EOL . $sngdate . "</sngdate>";
            }

            $mdattim = "";
            foreach ($field_entity->field_mul_calendar_datetime[$node->language] as $mulcalendar) {
                $field_collection1 = entity_load('field_collection_item', array($mulcalendar['value']));
                $sngdate1 = "";
                foreach ($field_collection1 as $field_entity1) {
                    $sngdate1.="<caldate>" . $field_entity1->field_calendar_date[$node->language][0]['value'] . "</caldate>" . PHP_EOL;
                    $sngdate1.="<time>" . $field_entity1->field_time_of_day[$node->language][0]['value'] . "</time>" . PHP_EOL;
                }
                if ($sngdate1 != "") {
                    $sngdate = "<sngdate>" . PHP_EOL . $sngdate1 . "</sngdate>";
                    $mdattim.=$sngdate1 . PHP_EOL;
                }
            }
            if ($mdattim != "") {
                $mdattim = "<mdattim>" . PHP_EOL . $mdattim . "</mdattim>";
            }

            $rngdates = "";
            if (isset($field_entity->field_beginning_date[$node->language]) && $field_entity->field_beginning_date[$node->language][0]['value'] != "") {
                $rngdates.="<begdate>" . $field_entity->field_beginning_date[$node->language][0]['value'] . "</begdate>" . PHP_EOL;
            }
            if (isset($field_entity->field_beginning_time[$node->language]) && $field_entity->field_beginning_time[$node->language][0]['value'] != "") {
                $rngdates.="<begtime>" . $field_entity->field_beginning_time[$node->language][0]['value'] . "</begtime>" . PHP_EOL;
            }
            if (isset($field_entity->field_ending_date[$node->language]) && $field_entity->field_ending_date[$node->language][0]['value'] != "") {
                $rngdates.="<enddate>" . $field_entity->field_ending_date[$node->language][0]['value'] . "</enddate>" . PHP_EOL;
            }
            if (isset($field_entity->field_ending_time[$node->language]) && $field_entity->field_ending_time[$node->language][0]['value'] != "") {
                $rngdates.="<endtime>" . $field_entity->field_ending_time[$node->language][0]['value'] . "</endtime>" . PHP_EOL;
            }
            if ($rngdates != "") {
                $rngdates = "<rngdates>" . PHP_EOL . $rngdates . "</rngdates>";
            }

            $timeinfo = $sngdate . PHP_EOL . $rngdates . PHP_EOL . $mdattim;

            if ($timeinfo != "") {
                $timeinfo = "<timeinfo>" . PHP_EOL . $timeinfo . PHP_EOL . "</timeinfo>";
            }
            $timeperd = $timeperd . $timeinfo;

            if ($timeperd != "") {
                $xml .="<timeperd>" . PHP_EOL . $timeperd . PHP_EOL . "</timeperd>" . PHP_EOL;
            }
        }
    }

    $status = "";
    if (isset($node->field_progress[$node->language][0]['value'])) {
        $status.="<progress>" . $node->field_progress[$node->language][0]['value'] . "</progress>" . PHP_EOL;
    }
    if (isset($node->field_updatefrequency[$node->language][0]['value'])) {
        $status.="<update>" . $node->field_updatefrequency[$node->language][0]['value'] . "</update>" . PHP_EOL;
    }
    if ($status != "") {
        $xml.="<status>" . PHP_EOL . $status . "</status>" . PHP_EOL;
    }

    $spdom = "";
    $boundingbox = "";

    if (isset($node->field_core_lat_n[$node->language][0]['value'])) {
        $boundingbox.="<northbc>" . $node->field_core_lat_n[$node->language][0]['value'] . "</northbc>" . PHP_EOL;
    }
    if (isset($node->field_core_lat_s[$node->language][0]['value'])) {
        $boundingbox.="<southbc>" . $node->field_core_lat_s[$node->language][0]['value'] . "</southbc>" . PHP_EOL;
    }
    if (isset($node->field_core_long_w[$node->language][0]['value'])) {
        $boundingbox.="<westbc>" . $node->field_core_long_w[$node->language][0]['value'] . "</westbc>" . PHP_EOL;
    }
    if (isset($node->field_core_long_e[$node->language][0]['value'])) {
        $boundingbox.="<eastbc>" . $node->field_core_long_e[$node->language][0]['value'] . "</eastbc>" . PHP_EOL;
    }
    if ($boundingbox != "") {
        $boundingbox = "<bounding>" . $boundingbox . "</bounding>";
    }



    //for each collection need two foreach--one to entity_load and second for readeach data...
    $dsgpolycollection = "";
    if (isset($node->field_dsgpoly[$node->language][0]['value'])) {
        foreach ($node->field_dsgpoly[$node->language] as $dsgpoly_field) {
            $field_collection = entity_load('field_collection_item', array($dsgpoly_field['value']));
            $dsgpoly = "";
            //cannot access directly
            foreach ($field_collection as $dsgpoly_field_entity) {
                $gring = "";
                if (isset($dsgpoly_field_entity->field_gring[$node->language][0]['value'])) {
                    $gring.="<gring>" . $dsgpoly_field_entity->field_gring[$node->language][0]['value'] . "</gring>";
                }
                $dsgpolyo = "";
                foreach ($dsgpoly_field_entity->field_dsgpolyo[$node->language] as $dsgpolyo_entity) {
                    $field_collection1 = entity_load('field_collection_item', array($dsgpolyo_entity['value']));
                    $grngpoin = "";
                    foreach ($field_collection1 as $grngpoin_entity) {
                        if (isset($grngpoin_entity->field_gringlat[$node->language][0]['value']))
                            $grngpoin.="<gringlat>" . $grngpoin_entity->field_gringlat[$node->language][0]['value'] . "</gringlat>" . PHP_EOL;
                        if (isset($grngpoin_entity->field_gringlon[$node->language][0]['value']))
                            $grngpoin.="<gringlon>" . $grngpoin_entity->field_gringlon[$node->language][0]['value'] . "</gringlon>" . PHP_EOL;

                        if ($grngpoin != "") {
                            $grngpoin = "<grngpoin>" . PHP_EOL . $grngpoin . "</grngpoin>";
                        }
                    }
                    $dsgpolyo .=$grngpoin . PHP_EOL;
                }
                $dsgpolyo = $gring . PHP_EOL . $dsgpolyo;
                if ($dsgpolyo != "") {
                    $dsgpolyo = "<dsgpolyo>" . PHP_EOL . $dsgpolyo . "</dsgpolyo>";
                }
                //
                $dsgpolyxcollection = "";
                foreach ($dsgpoly_field_entity->field_dsgpolyx[$node->language] as $dsgpolyx_entities_arr) {
                    $fieldcollection2 = entity_load('field_collection_item', array($dsgpolyx_entities_arr['value']));
                    foreach ($fieldcollection2 as $dsgpolyx_entities_obj) {
                        $gring = "";
                        if (isset($dsgpolyx_entities_obj->field_gring[$node->language][0]['value'])) {
                            $gring.="<gring>" . $dsgpolyx_entities_obj->field_gring[$node->language][0]['value'] . "</gring>";
                        }
                        $dsgpolyx = "";
                        foreach ($dsgpoly_field_entity->field_dsgpolyo[$node->language] as $dsgpolyx_entity) {
                            $field_collection1 = entity_load('field_collection_item', array($dsgpolyx_entity['value']));
                            $grngpoin = "";
                            foreach ($field_collection1 as $grngpoin_entity) {
                                if (isset($grngpoin_entity->field_gringlat[$node->language][0]['value']))
                                    $grngpoin.="<gringlat>" . $grngpoin_entity->field_gringlat[$node->language][0]['value'] . "</gringlat>" . PHP_EOL;
                                if (isset($grngpoin_entity->field_gringlon[$node->language][0]['value']))
                                    $grngpoin.="<gringlon>" . $grngpoin_entity->field_gringlon[$node->language][0]['value'] . "</gringlon>" . PHP_EOL;

                                if ($grngpoin != "") {
                                    $grngpoin = "<grngpoin>" . PHP_EOL . $grngpoin . "</grngpoin>";
                                }
                            }
                            $dsgpolyx .=$grngpoin . PHP_EOL;
                        }
                        $dsgpolyx = $gring . PHP_EOL . $dsgpolyx;
                    }
                    if ($dsgpolyx != "") {
                        $dsgpolyx = "<dsgpolyx>" . PHP_EOL . $dsgpolyx . "</dsgpolyx>" . PHP_EOL;
                    }
                    $dsgpolyxcollection.=$dsgpolyx;
                }
            }
            $dsgpoly = $dsgpolyo . $dsgpolyxcollection;
            if ($dsgpoly != "") {
                $dsgpolycollection.="<dsgpoly>" . PHP_EOL . $dsgpoly . "</dsgpoly>";
            }
        }
    }
    $spdom = $boundingbox . PHP_EOL . $dsgpolycollection;
    if ($spdom != "") {
        $xml.="<spdom>" . PHP_EOL . $spdom . PHP_EOL . "</spdom>" . PHP_EOL;
    }
    ////keywords

    $keywords = "";
    foreach ($node->field_themekeywords[$node->language] as $theme_field) {
        $field_collection = entity_load('field_collection_item', array($theme_field['value']));
        $theme = "";
        foreach ($field_collection as $theme_field_entity) {
            foreach ($theme_field_entity->field_themekey[$node->language] as $themekey_entity) {
                $term = taxonomy_term_load($themekey_entity['tid']);
                $theme.="<themekey>" . $term->name . "</themekey>" . PHP_EOL;
            }
            if (isset($theme_field_entity->field_themekt[$node->language][0]['tid'])) {
                $term = taxonomy_term_load($theme_field_entity->field_themekt[$node->language][0]['tid']);
                $theme.="<themekt>" . $term->name . "</themekt>" . PHP_EOL;
            }
        }
        if ($theme != "") {
            $theme = "<theme>" . PHP_EOL . $theme . "</theme>" . PHP_EOL;
        }
        $keywords.=$theme;
    }

    foreach ($node->field_place_keywords[$node->language] as $theme_field) {
        $field_collection = entity_load('field_collection_item', array($theme_field['value']));
        $theme = "";
        foreach ($field_collection as $theme_field_entity) {
            foreach ($theme_field_entity->field_placekey[$node->language] as $themekey_entity) {
                $term = taxonomy_term_load($themekey_entity['tid']);
                $theme.="<placekey>" . $term->name . "</placekey>" . PHP_EOL;
            }
            if (isset($theme_field_entity->field_placekt[$node->language][0]['tid'])) {
                $term = taxonomy_term_load($theme_field_entity->field_placekt[$node->language][0]['tid']);
                $theme.="<placekt>" . $term->name . "</placekt>" . PHP_EOL;
            }
        }
        if ($theme != "") {
            $theme = "<place>" . PHP_EOL . $theme . "</place>" . PHP_EOL;
        }
        $keywords.=$theme;
    }

    foreach ($node->field_stratum_keywords[$node->language] as $theme_field) {
        $field_collection = entity_load('field_collection_item', array($theme_field['value']));
        $theme = "";
        foreach ($field_collection as $theme_field_entity) {
            foreach ($theme_field_entity->field_stratumkey[$node->language] as $themekey_entity) {
                $term = taxonomy_term_load($themekey_entity['tid']);
                $theme.="<stratumkey>" . $term->name . "</stratumkey>" . PHP_EOL;
            }
            if (isset($theme_field_entity->field_stratumkt[$node->language][0]['tid'])) {
                $term = taxonomy_term_load($theme_field_entity->field_stratumkt[$node->language][0]['tid']);
                $theme.="<stratumkt>" . $term->name . "</stratumkt>" . PHP_EOL;
            }
        }
        if ($theme != "") {
            $theme = "<stratum>" . PHP_EOL . $theme . "</stratum>" . PHP_EOL;
        }
        $keywords.=$theme;
    }

    foreach ($node->field_temporal_keywords[$node->language] as $theme_field) {
        $field_collection = entity_load('field_collection_item', array($theme_field['value']));
        $theme = "";
        foreach ($field_collection as $theme_field_entity) {
            foreach ($theme_field_entity->field_temporalkey[$node->language] as $themekey_entity) {
                $term = taxonomy_term_load($themekey_entity['tid']);
                $theme.="<temporalkey>" . $term->name . "</temporalkey>" . PHP_EOL;
            }
            if (isset($theme_field_entity->field_temporalkt[$node->language][0]['tid'])) {
                $term = taxonomy_term_load($theme_field_entity->field_temporalkt[$node->language][0]['tid']);
                $theme.="<temporalkt>" . $term->name . "</temporalkt>" . PHP_EOL;
            }
        }
        if ($theme != "") {
            $theme = "<temporal>" . PHP_EOL . $theme . "</temporal>" . PHP_EOL;
        }
        $keywords.=$theme;
    }

    if ($keywords != "") {
        $xml.="<keywords>" . PHP_EOL . $keywords . "</keywords>" . PHP_EOL;
    }
///end keywords

    if (isset($node->field_core_res_access[$node->language][0]['value'])) {
        $xml.="<accconst>" . $node->field_core_res_access[$node->language][0]['value'] . "</accconst>" . PHP_EOL;
    }
    if (isset($node->field_core_res_constraint[$node->language][0]['value'])) {
        $xml.="<useconst>" . $node->field_core_res_constraint[$node->language][0]['value'] . "</useconst>" . PHP_EOL;
    }
    if (isset($node->field_native[$node->language][0]['value'])) {
        $xml.="<native>" . $node->field_native[$node->language][0]['value'] . "</native>" . PHP_EOL;
    }

    ///point of contact

    /*
      $node->field_cont_cit_name_person[$node->language][0]['value'] = $cntinfo->cntorgp->cntorg;
      $node->field_cont_cit_name_org[$node->language][0]['value'] = $cntinfo->cntorgp->cntper;
      $node->field_position[$node->language][0]['value'] = $cntinfo->cntpos;

     */

    $ptcontac = "";
    $cntinfo = "";
    $cntorgp = "";
    if (isset($node->field_cont_cit_name_person[$node->language][0]['value'])) {
        $cntorgp.="<cntorg>" . $node->field_cont_cit_name_person[$node->language][0]['value'] . "</cntorg>" . PHP_EOL;
    }
    if (isset($node->field_cont_cit_name_org[$node->language][0]['value'])) {
        $cntorgp.="<cntper>" . $node->field_cont_cit_name_org[$node->language][0]['value'] . "</cntper>" . PHP_EOL;
    }
    if ($cntorgp != "") {
        $cntorgp = "<cntorgp>" . PHP_EOL . $cntorgp . "</cntorgp>" . PHP_EOL;
    }

    $cntaddrcollection = "";
    foreach ($node->field_iden_originator_add[$node->language] as $address_fieldcoll) {
        $field_collection = entity_load('field_collection_item', array($address_fieldcoll['value']));
        $cntaddr = "";
        foreach ($field_collection as $address_entity) {
            if (isset($address_entity->field_address_type[$node->language][0]['value'])) {
                $cntaddr .="<addrtype>" . $address_entity->field_address_type[$node->language][0]['value'] . "</addrtype>" . PHP_EOL;
            }
            foreach ($address_entity->field_cont_cit_street[$node->language] as $inside_address) {
                $cntaddr.="<address>" . $inside_address['value'] . "</address>" . PHP_EOL;
            }
            if (isset($address_entity->field_cont_cit_city[$node->language][0]['value'])) {
                $cntaddr .="<city>" . $address_entity->field_cont_cit_city[$node->language][0]['value'] . "</city>" . PHP_EOL;
            }
            if (isset($address_entity->field_cont_cit_province[$node->language][0]['value'])) {
                $cntaddr .="<state>" . $address_entity->field_cont_cit_province[$node->language][0]['value'] . "</state>" . PHP_EOL;
            }
            if (isset($address_entity->field_cont_cit_postalcode[$node->language][0]['value'])) {
                $cntaddr .="<postal>" . $address_entity->field_cont_cit_postalcode[$node->language][0]['value'] . "</postal>" . PHP_EOL;
            }
            if (isset($address_entity->field_cont_cit_country[$node->language][0]['value'])) {
                $cntaddr .="<country>" . $address_entity->field_cont_cit_country[$node->language][0]['value'] . "</country>" . PHP_EOL;
            }
        }
        if ($cntaddr != "") {
            $cntaddr = "<cntaddr>" . PHP_EOL . $cntaddr . "</cntaddr>" . PHP_EOL;
        }
        $cntaddrcollection.=$cntaddr;
    }

    $cntinfo.=$cntorgp . $cntaddrcollection;


    if (isset($node->field_position[$node->language][0]['value'])) {
        $cntinfo.="<cntpos>" . $node->field_position[$node->language][0]['value'] . "</cntpos>" . PHP_EOL;
    }

    foreach ($node->field_cont_cit_phone[$node->language] as $phoneaddress) {
        $cntinfo.="<cntvoice>" . $phoneaddress['value'] . "</cntvoice>" . PHP_EOL;
    }

    foreach ($node->field_cnttdd[$node->language] as $phoneaddress) {
        $cntinfo.="<cnttdd>" . $phoneaddress['value'] . "</cnttdd>" . PHP_EOL;
    }

    foreach ($node->field_cont_cit_fax[$node->language] as $phoneaddress) {
        $cntinfo.="<cntfax>" . $phoneaddress['value'] . "</cntfax>" . PHP_EOL;
    }

    foreach ($node->field_cont_cit_email[$node->language] as $phoneaddress) {
        $cntinfo.="<cntemail>" . $phoneaddress['value'] . "</cntemail>" . PHP_EOL;
    }
    if ($cntinfo != "") {
        $xml .= "<ptcontac>" . PHP_EOL . "<cntinfo>" . PHP_EOL . $cntinfo . "</cntinfo>" . PHP_EOL . "</ptcontac>" . PHP_EOL;
    }

    foreach ($node->field_i_browse_graphics[$node->language] as $browsefieldcoll) {
        $field_collection = entity_load('field_collection_item', array($browsefieldcoll['value']));
        $browse = "";
        foreach ($field_collection as $browsefield_entity) {
            $browse.="<browsen>" . $browsefield_entity->field_i_filename[$node->language][0]['value'] . "</browsen>" . PHP_EOL;
            $browse.="<browsed>" . htmlspecialchars($browsefield_entity->field_file_description[$node->language][0]['value']) . "</browsed>" . PHP_EOL;
            $browse.="<browset>" . $browsefield_entity->field_i_filetype[$node->language][0]['value'] . "</browset>" . PHP_EOL;
        }
        if ($browse != "") {
            $xml.="<browse>" . PHP_EOL . $browse . "</browse>" . PHP_EOL;
        }
    }
    if (isset($node->field_data_set_credit[$node->language][0]['value'])) {
        $xml.="<datacred>" . $node->field_data_set_credit[$node->language][0]['value'] . "</datacred>" . PHP_EOL;
    }

    $secinfo = "";
    if (isset($node->field_secsys[$node->language][0]['value'])) {
        $secinfo.="<secsys>" . $node->field_secsys[$node->language][0]['value'] . "</secsys>" . PHP_EOL;
    }
    if (isset($node->field_secclass[$node->language][0]['value'])) {
        $secinfo.="<secclass>" . $node->field_secclass[$node->language][0]['value'] . "</secclass>" . PHP_EOL;
    }
    if (isset($node->field_sechandl[$node->language][0]['value'])) {
        $secinfo.="<sechandl>" . $node->field_sechandl[$node->language][0]['value'] . "</sechandl>" . PHP_EOL;
    }
    if ($secinfo != "") {
        $xml.=$secinfo;
    }

    foreach ($node->field_citation[$node->language] as $crossref_field) {
        $field_collection = entity_load('field_collection_item', array($crossref_field['value']));
        $crossref = "";
        $citeinfo = "";
        foreach ($field_collection as $crossref_entity) {
            if (isset($crossref_entity->title[$node->language][0]['value'])) {
                $citeinfo.="<title>" . $crossref_entity->title[$node->language][0]['value'] . "</title>" . PHP_EOL;
            }
            foreach ($crossref_entity->field_origin[$node->language] as $crossref_origin) {
                $citeinfo.="<origin>" . $crossref_entity->field_origin[$node->language][0]['value'] . "</origin>";
            }
            if (isset($crossref_entity->field_pubdate[$node->language][0]['value'])) {
                $citeinfo.="<pubdate>" . $crossref_entity->field_pubdate[$node->language][0]['value'] . "</pubdate>" . PHP_EOL;
            }
            if (isset($crossref_entity->field_pubtime[$node->language][0]['value'])) {
                $citeinfo.="<pubtime>" . $crossref_entity->field_pubtime[$node->language][0]['value'] . "</pubtime>" . PHP_EOL;
            }
            if (isset($crossref_entity->field_edition[$node->language][0]['value'])) {
                $citeinfo.="<edition>" . $crossref_entity->field_edition[$node->language][0]['value'] . "</edition>" . PHP_EOL;
            }
            if (isset($crossref_entity->field_geoform[$node->language][0]['value'])) {
                $citeinfo.="<geoform>" . $crossref_entity->field_geoform[$node->language][0]['value'] . "</geoform>" . PHP_EOL;
            }

            foreach ($crossref_entity->field_onlink[$node->language] as $crossref_origin) {
                $citeinfo.="<onlink>" . $crossref_entity->field_onlink[$node->language][0]['url'] . "</onlink>" . PHP_EOL;
            }

            $serinfo = "";
            if (isset($crossref_entity->field_sername[$node->language][0]['value'])) {
                $serinfo.="<sername>" . $crossref_entity->field_sername[$node->language][0]['value'] . "</sername>" . PHP_EOL;
            }
            if (isset($crossref_entity->field_issue[$node->language][0]['value'])) {
                $serinfo.="<issue>" . $crossref_entity->field_issue[$node->language][0]['value'] . "</issue>" . PHP_EOL;
            }
            if (isset($crossref_entity->field_pubplace[$node->language][0]['value'])) {
                $serinfo.="<pubplace>" . $crossref_entity->field_pubplace[$node->language][0]['value'] . "</pubplace>" . PHP_EOL;
            }
            if (isset($crossref_entity->field_publish[$node->language][0]['value'])) {
                $serinfo.="<publish>" . $crossref_entity->field_publish[$node->language][0]['value'] . "</publish>" . PHP_EOL;
            }
            if (isset($crossref_entity->field_othercit[$node->language][0]['value'])) {
                $serinfo.="<othercit>" . $crossref_entity->field_othercit[$node->language][0]['value'] . "</othercit>" . PHP_EOL;
            }
            if ($serinfo != "") {
                $citeinfo.= "<serinfo>" . PHP_EOL . $serinfo . "</serinfo>" . PHP_EOL;
            }
        }
        if ($citeinfo != "") {
            $citeinfo = "<crossref>" . PHP_EOL . "<citeinfo>" . PHP_EOL . $citeinfo . "</citeinfo>" . PHP_EOL . "</crossref>" . PHP_EOL;
        }
        $xml.=$citeinfo;
    }
    $xml.="</idinfo>" . PHP_EOL;

    //dataequal
    $dataequal = "";

    if (isset($node->field_d_logic[$node->language][0]['value'])) {
        $dataequal.="<logic>" . $node->field_d_logic[$node->language][0]['value'] . "</logic>" . PHP_EOL;
    }
    if (isset($node->field_d_complete[$node->language][0]['value'])) {
        $dataequal.="<complete>" . $node->field_d_complete[$node->language][0]['value'] . "</complete>" . PHP_EOL;
    }
    if (isset($node->field_d_cloud[$node->language][0]['value'])) {
        $dataequal.="<cloud>" . $node->field_d_cloud[$node->language][0]['value'] . "</cloud>" . PHP_EOL;
    }

    $attracc = "";
    if (isset($node->field_d_attraccr[$node->language][0]['value'])) {
        $attracc.="<attraccr>" . $node->field_d_attraccr[$node->language][0]['value'] . "</attraccr>" . PHP_EOL;
    }
    if ($attracc != "") {
        $dataequal.="<attracc>" . PHP_EOL . $attracc . "</attracc>" . PHP_EOL;
    }

    foreach ($node->field_d_accuracy_assessment[$node->language] as $qattracc_field) {
        $field_collection = entity_load('field_collection_item', array($qattracc_field['value']));
        $qattracc = "";
        foreach ($field_collection as $qattracc_entity) {
            $qattracc.="<attraccv>" . $qattracc_entity->field_d_value[$node->language][0]['value'] . "</attraccv>" . PHP_EOL;
            $qattracc.="<attracce>" . $qattracc_entity->field_d_explanation[$node->language][0]['value'] . "</attracce>" . PHP_EOL;
        }
        if ($qattracc != "")
            $dataequal.="<qattracc>" . PHP_EOL . $qattracc . "</qattracc>" . PHP_EOL;
    }

    $posacc = "";
    $horizpar = "";
    if (isset($node->field_horizpar[$node->language][0]['value'])) {
        $horizpar.="<horizpar>" . $node->field_horizpar[$node->language][0]['value'] . "</horizpar>" . PHP_EOL;
    }
    foreach ($node->field_qhorizpa[$node->language] as $qattracc_field) {
        $field_collection = entity_load('field_collection_item', array($qattracc_field['value']));
        $qattracc = "";
        foreach ($field_collection as $qattracc_entity) {
            $qattracc.="<horizpav>" . $qattracc_entity->field_horizpae[$node->language][0]['value'] . "</horizpav>" . PHP_EOL;
            $qattracc.="<horizpae>" . $qattracc_entity->field_horizpav[$node->language][0]['value'] . "</horizpae>" . PHP_EOL;
        }
        if ($qattracc != "")
            $horizpar.="<qhorizpa>" . PHP_EOL . $qattracc . "</qhorizpa>" . PHP_EOL;
    }

    if ($horizpar != "") {
        $posacc.="<horizpa>" . PHP_EOL . $horizpar . "</horizpa>" . PHP_EOL;
    }

    $vertacc = "";
    if (isset($node->field_vertaccr[$node->language][0]['value'])) {
        $vertacc.="<vertaccr>" . $node->field_vertaccr[$node->language][0]['value'] . "</vertaccr>" . PHP_EOL;
    }
    foreach ($node->field_qvertpa[$node->language] as $qattracc_field) {
        $field_collection = entity_load('field_collection_item', array($qattracc_field['value']));
        $qattracc = "";
        foreach ($field_collection as $qattracc_entity) {
            $qattracc.="<vertaccv>" . $qattracc_entity->field_vertaccv[$node->language][0]['value'] . "</vertaccv>" . PHP_EOL;
            $qattracc.="<vertacce>" . $qattracc_entity->field_vertacce[$node->language][0]['value'] . "</vertacce>" . PHP_EOL;
        }
        if ($qattracc != "")
            $vertacc.="<qhorizpa>" . PHP_EOL . $qattracc . "</qhorizpa>" . PHP_EOL;
    }

    if ($vertacc != "") {
        $posacc.="<vertacc>" . PHP_EOL . $vertacc . "</vertacc>" . PHP_EOL;
    }
    if ($posacc != "")
        $dataequal.="<posacc>" . PHP_EOL . $posacc . "</posacc>" . PHP_EOL;

    //source citation
    $lineage = "";
    foreach ($node->field_d_sourcecitation[$node->language] as $src_citation_field) {
        $field_collection = entity_load('field_collection_item', array($src_citation_field['value']));
        $srcinfo = "";
        foreach ($field_collection as $src_citation_entity) {
            if (isset($src_citation_entity->field_srcscale[$node->language][0]['value']))
                $srcinfo.="<srcscale>" . $src_citation_entity->field_srcscale[$node->language][0]['value'] . "</srcscale>" . PHP_EOL;
            if (isset($src_citation_entity->field_typesrc[$node->language][0]['value']))
                $srcinfo.="<typesrc>" . $src_citation_entity->field_typesrc[$node->language][0]['value'] . "</typesrc>" . PHP_EOL;
            if (isset($src_citation_entity->field_srccitea[$node->language][0]['value']))
                $srcinfo.="<srccitea>" . $src_citation_entity->field_srccitea[$node->language][0]['value'] . "</srccitea>" . PHP_EOL;
            if (isset($src_citation_entity->field_srccontr[$node->language][0]['value']))
                $srcinfo.="<srccontr>" . $src_citation_entity->field_srccontr[$node->language][0]['value'] . "</srccontr>" . PHP_EOL;

            //srccite
            if (isset($src_citation_entity->field_title[$node->language][0]['value']))
                $srcinfo.="<title>" . $src_citation_entity->field_title[$node->language][0]['value'] . "</title>" . PHP_EOL;

            foreach ($src_citation_entity->field_origin[$node->language][0] as $src_citation_origin) {
                $srcinfo.="<origin>" . $src_citation_origin['value'] . "</origin>" . PHP_EOL;
            }
            if (isset($src_citation_entity->field_pubdate[$node->language][0]['value']))
                $srcinfo.="<pubdate>" . $src_citation_entity->field_pubdate[$node->language][0]['value'] . "</pubdate>" . PHP_EOL;

            if (isset($src_citation_entity->field_pubtime[$node->language][0]['value']))
                $srcinfo.="<pubtime>" . $src_citation_entity->field_pubtime[$node->language][0]['value'] . "</pubtime>" . PHP_EOL;

            if (isset($src_citation_entity->field_edition[$node->language][0]['value']))
                $srcinfo.="<edition>" . $src_citation_entity->field_edition[$node->language][0]['value'] . "</edition>" . PHP_EOL;

            if (isset($src_citation_entity->field_geoform[$node->language][0]['value']))
                $srcinfo.="<geoform>" . $src_citation_entity->field_geoform[$node->language][0]['value'] . "</geoform>" . PHP_EOL;

            foreach ($src_citation_entity->field_onlink[$node->language] as $src_citation_onlink) {
                $srcinfo.="<onlink>" . $src_citation_onlink['url'] . "</onlink>" . PHP_EOL;
            }

            if (isset($src_citation_entity->field_sername[$node->language][0]['value']))
                $srcinfo.="<sername>" . $src_citation_entity->field_sername[$node->language][0]['value'] . "</sername>" . PHP_EOL;

            if (isset($src_citation_entity->field_issue[$node->language][0]['value']))
                $srcinfo.="<issue>" . $src_citation_entity->field_issue[$node->language][0]['value'] . "</issue>" . PHP_EOL;
            if (isset($src_citation_entity->field_pubplace[$node->language][0]['value']))
                $srcinfo.="<pubplace>" . $src_citation_entity->field_pubplace[$node->language][0]['value'] . "</pubplace>" . PHP_EOL;

            if (isset($src_citation_entity->field_publish[$node->language][0]['value']))
                $srcinfo.="<publish>" . $src_citation_entity->field_publish[$node->language][0]['value'] . "</publish>" . PHP_EOL;

            if (isset($src_citation_entity->field_othercit[$node->language][0]['value']))
                $srcinfo.="<othercit>" . $src_citation_entity->field_othercit[$node->language][0]['value'] . "</othercit>" . PHP_EOL;

            //time of source citation
            if (isset($src_citation_entity->field_i_iden_timeperiod[$node->language])) {
                $field_collection = entity_load('field_collection_item', array($src_citation_entity->field_i_iden_timeperiod[$node->language][0]['value']));
                foreach ($field_collection as $field_entity) {
                    $timeperd = "";
                    if (isset($field_entity->field_currentness_ref[$node->language]) && $field_entity->field_currentness_ref[$node->language][0]['value'] != "") {
                        $timeperd.="<current>" . $field_entity->field_currentness_ref[$node->language][0]['value'] . "</current>" . PHP_EOL;
                    }
                    $timeinfo = "";
                    $sngdate = "";

                    if (isset($field_entity->field_calendar_date[$node->language]) && $field_entity->field_calendar_date[$node->language][0]['value'] != "") {
                        $sngdate.="<caldate>" . $field_entity->field_calendar_date[$node->language][0]['value'] . "</caldate>" . PHP_EOL;
                    }
                    if (isset($field_entity->field_time_of_day[$node->language]) && $field_entity->field_time_of_day[$node->language][0]['value'] != "") {
                        $sngdate.="<time>" . $field_entity->field_time_of_day[$node->language][0]['value'] . "</time>" . PHP_EOL;
                    }
                    if ($sngdate != "") {
                        $sngdate = "<sngdate>" . PHP_EOL . $sngdate . "</sngdate>";
                    }

                    $mdattim = "";
                    foreach ($field_entity->field_mul_calendar_datetime[$node->language] as $mulcalendar) {
                        $field_collection1 = entity_load('field_collection_item', array($mulcalendar['value']));
                        $sngdate1 = "";
                        foreach ($field_collection1 as $field_entity1) {
                            $sngdate1.="<caldate>" . $field_entity1->field_calendar_date[$node->language][0]['value'] . "</caldate>" . PHP_EOL;
                            $sngdate1.="<time>" . $field_entity1->field_time_of_day[$node->language][0]['value'] . "</time>" . PHP_EOL;
                        }
                        if ($sngdate1 != "") {
                            $sngdate1 = "<sngdate>" . PHP_EOL . $sngdate1 . "</sngdate>";
                            $mdattim.=$sngdate1 . PHP_EOL;
                        }
                    }
                    if ($mdattim != "") {
                        $mdattim = "<mdattim>" . PHP_EOL . $mdattim . "</mdattim>";
                    }

                    $rngdates = "";
                    if (isset($field_entity->field_beginning_date[$node->language]) && $field_entity->field_beginning_date[$node->language][0]['value'] != "") {
                        $rngdates.="<begdate>" . $field_entity->field_beginning_date[$node->language][0]['value'] . "</begdate>" . PHP_EOL;
                    }
                    if (isset($field_entity->field_beginning_time[$node->language]) && $field_entity->field_beginning_time[$node->language][0]['value'] != "") {
                        $rngdates.="<begtime>" . $field_entity->field_beginning_time[$node->language][0]['value'] . "</begtime>" . PHP_EOL;
                    }
                    if (isset($field_entity->field_ending_date[$node->language]) && $field_entity->field_ending_date[$node->language][0]['value'] != "") {
                        $rngdates.="<enddate>" . $field_entity->field_ending_date[$node->language][0]['value'] . "</enddate>" . PHP_EOL;
                    }
                    if (isset($field_entity->field_ending_time[$node->language]) && $field_entity->field_ending_time[$node->language][0]['value'] != "") {
                        $rngdates.="<endtime>" . $field_entity->field_ending_time[$node->language][0]['value'] . "</endtime>" . PHP_EOL;
                    }
                    if ($rngdates != "") {
                        $rngdates = "<rngdates>" . PHP_EOL . $rngdates . "</rngdates>";
                    }

                    $timeinfo = $sngdate . PHP_EOL . $rngdates . PHP_EOL . $mdattim;

                    if ($timeinfo != "") {
                        $timeinfo = "<timeinfo>" . PHP_EOL . $timeinfo . PHP_EOL . "</timeinfo>";
                    }
                    $timeperd = $timeperd . $timeinfo;

                    if ($timeperd != "") {
                        $srcinfo .="<srctime>" . PHP_EOL . $timeperd . PHP_EOL . "</srctime>" . PHP_EOL;
                    }
                }
            }
        }
        if ($srcinfo != "") {
            $srcinfo = "<srcinfo>" . PHP_EOL . $srcinfo . "</srcinfo>";
        }
        $lineage.=$srcinfo;
    }
    //unlimited
    foreach ($node->field_d_process_step[$node->language] as $process_step_field) {
        $field_collection = entity_load('field_collection_item', array($process_step_field['value']));
        $procstep = "";
        foreach ($field_collection as $process_step_entity) {
            $procstep.= "<procdesc>" . $process_step_entity->field_d_process_descp[$node->language][0]['value'] . "</procdesc>" . PHP_EOL;
            $procstep.= "<procdate>" . $process_step_entity->field_d_processdate[$node->language][0]['value'] . "</procdate>" . PHP_EOL;
            $procstep.= "<proctime>" . $process_step_entity->field_d_processtime[$node->language][0]['value'] . "</proctime>" . PHP_EOL;

            foreach ($process_step_entity->field_srcused[$node->language] as $srcused_entity) {
                $procstep.="<srcused>" . $srcused_entity . "</srcused>" . PHP_EOL;
            }
            foreach ($process_step_entity->field_srcprod[$node->language] as $srcprod_entity) {
                $procstep.="<srcprod>" . $srcprod_entity . "</srcprod>" . PHP_EOL;
            }

            //field_contact_info
            foreach ($process_step_entity->field_contact_info[$node->language] as $proc_contactinfo) {
                $field_collection = entity_load('field_collection_item', array($proc_contactinfo['value']));
                $cntinfo = "";

                //only one time
                foreach ($field_collection as $proc_contactinfo_entity) {

                    /*                         * ******************** */
                    $cntinfo = "";
                    $cntorgp = "";
                    if (isset($proc_contactinfo_entity->field_cont_cit_name_person[$node->language][0]['value'])) {
                        $cntorgp.="<cntorg>" . $proc_contactinfo_entity->field_cont_cit_name_person[$node->language][0]['value'] . "</cntorg>" . PHP_EOL;
                    }
                    if (isset($proc_contactinfo_entity->field_cont_cit_name_org[$node->language][0]['value'])) {
                        $cntorgp.="<cntper>" . $proc_contactinfo_entity->field_cont_cit_name_org[$node->language][0]['value'] . "</cntper>" . PHP_EOL;
                    }
                    if ($cntorgp != "") {
                        $cntorgp = "<cntorgp>" . PHP_EOL . $cntorgp . "</cntorgp>" . PHP_EOL;
                    }

                    $cntaddrcollection = "";
                    foreach ($proc_contactinfo_entity->field_iden_originator_add[$node->language] as $address_fieldcoll) {
                        $field_collection = entity_load('field_collection_item', array($address_fieldcoll['value']));
                        $cntaddr = "";
                        foreach ($field_collection as $address_entity) {
                            if (isset($address_entity->field_address_type[$node->language][0]['value'])) {
                                $cntaddr .="<addrtype>" . $address_entity->field_address_type[$node->language][0]['value'] . "</addrtype>" . PHP_EOL;
                            }
                            foreach ($address_entity->field_cont_cit_street[$node->language] as $inside_address) {
                                $cntaddr.="<address>" . $inside_address['value'] . "</address>" . PHP_EOL;
                            }
                            if (isset($address_entity->field_cont_cit_city[$node->language][0]['value'])) {
                                $cntaddr .="<city>" . $address_entity->field_cont_cit_city[$node->language][0]['value'] . "</city>" . PHP_EOL;
                            }
                            if (isset($address_entity->field_cont_cit_province[$node->language][0]['value'])) {
                                $cntaddr .="<state>" . $address_entity->field_cont_cit_province[$node->language][0]['value'] . "</state>" . PHP_EOL;
                            }
                            if (isset($address_entity->field_cont_cit_postalcode[$node->language][0]['value'])) {
                                $cntaddr .="<postal>" . $address_entity->field_cont_cit_postalcode[$node->language][0]['value'] . "</postal>" . PHP_EOL;
                            }
                            if (isset($address_entity->field_cont_cit_country[$node->language][0]['value'])) {
                                $cntaddr .="<country>" . $address_entity->field_cont_cit_country[$node->language][0]['value'] . "</country>" . PHP_EOL;
                            }
                        }
                        if ($cntaddr != "") {
                            $cntaddr = "<cntaddr>" . PHP_EOL . $cntaddr . "</cntaddr>" . PHP_EOL;
                        }
                        $cntaddrcollection.=$cntaddr;
                    }

                    $cntinfo.=$cntorgp . $cntaddrcollection;


                    if (isset($proc_contactinfo_entity->field_position[$node->language][0]['value'])) {
                        $cntinfo.="<cntpos>" . $proc_contactinfo_entity->field_position[$node->language][0]['value'] . "</cntpos>" . PHP_EOL;
                    }

                    foreach ($proc_contactinfo_entity->field_cont_cit_phone[$node->language] as $phoneaddress) {
                        $cntinfo.="<cntvoice>" . $phoneaddress['value'] . "</cntvoice>" . PHP_EOL;
                    }

                    foreach ($proc_contactinfo_entity->field_cnttdd[$node->language] as $phoneaddress) {
                        $cntinfo.="<cnttdd>" . $phoneaddress['value'] . "</cnttdd>" . PHP_EOL;
                    }

                    foreach ($proc_contactinfo_entity->field_cont_cit_fax[$node->language] as $phoneaddress) {
                        $cntinfo.="<cntfax>" . $phoneaddress['value'] . "</cntfax>" . PHP_EOL;
                    }

                    foreach ($proc_contactinfo_entity->field_cont_cit_email[$node->language] as $phoneaddress) {
                        $cntinfo.="<cntemail>" . $phoneaddress['value'] . "</cntemail>" . PHP_EOL;
                    }
                    if ($cntinfo != "") {
                        $procstep .= "<proccont>" . PHP_EOL . "<cntinfo>" . PHP_EOL . $cntinfo . "</cntinfo>" . PHP_EOL . "</proccont>" . PHP_EOL;
                    }
                    /*                         * ************* */
                }
            }
        }
        if ($procstep != "") {
            $procstep = "<procstep>" . PHP_EOL . $procstep . "</procstep>" . PHP_EOL;
        }
        $lineage.=$procstep;
    }
    if ($lineage != "") {
        $dataequal.="<lineage>" . PHP_EOL . $lineage . "</lineage>";
    }
    //end source citation

    if ($dataequal != "") {
        $xml.="<dataequal>" . PHP_EOL . $dataequal . "</dataequal>" . PHP_EOL;
    }

    $spdoinfo = "";
    if (isset($node->field_direct_spatial_ref[$node->language][0]['value'])) {
        if (isset($node->field_direct_spatial_ref[$node->language][0]['value']))
            $spdoinfo.="<direct>" . $node->field_direct_spatial_ref[$node->language][0]['value'] . "</direct>" . PHP_EOL;
        if (isset($node->field_indirect_spatial_ref[$node->language][0]['value']))
            $spdoinfo.="<indspref>" . $node->field_indirect_spatial_ref[$node->language][0]['value'] . "</indspref>" . PHP_EOL;

        $rastinfo = "";
        if (isset($node->field_rasttype[$node->language][0]['value']))
            $rastinfo.="<rasttype>" . $node->field_rasttype[$node->language][0]['value'] . "</rasttype>" . PHP_EOL;

        if (isset($node->field_rowcount[$node->language][0]['value']))
            $rastinfo.="<rowcount>" . $node->field_rowcount[$node->language][0]['value'] . "</rowcount>" . PHP_EOL;

        if (isset($node->field_colcount[$node->language][0]['value']))
            $rastinfo.="<colcount>" . $node->field_colcount[$node->language][0]['value'] . "</colcount>" . PHP_EOL;

        if (isset($node->field_vrtcount[$node->language][0]['value']))
            $rastinfo.="<vrtcount>" . $node->field_vrtcount[$node->language][0]['value'] . "</vrtcount>" . PHP_EOL;

        if ($rastinfo != "") {
            $spdoinfo.="<rastinfo>" . PHP_EOL . $rastinfo . "</rastinfo>";
        }
        $ptvctinf = "";
        foreach ($node->field_sdtsterm[$node->language] as $address_fieldcoll) {
            $field_collection = entity_load('field_collection_item', array($address_fieldcoll['value']));
            $sdtsterm = "";
            foreach ($field_collection as $sdtsterm_entity) {
                if (isset($sdtsterm_entity->field_sdtstype[$node->language][0]['value']))
                    $sdtsterm.="<sdtstype>" . $sdtsterm_entity->field_sdtstype[$node->language][0]['value'] . "</sdtstype>" . PHP_EOL;

                if (isset($sdtsterm_entity->field_sdts_ptvctcnt[$node->language][0]['value']))
                    $sdtsterm.="<ptvctcnt>" . $sdtsterm_entity->field_sdts_ptvctcnt[$node->language][0]['value'] . "</ptvctcnt>" . PHP_EOL;
            }
            if ($sdtsterm != "") {
                $ptvctinf.= "<sdtsterm>" . $sdtsterm . "</sdtsterm>" . PHP_EOL;
            }
        }

        $vpfterm = "";
        if (isset($node->field_vpflevel[$node->language][0]['value'])) {
            $vpfterm.="<vpflevel>" . $node->field_vpflevel[$node->language][0]['value'] . "</vpflevel>" . PHP_EOL;
        }
        foreach ($node->field_vpfterm[$node->language] as $address_fieldcoll) {
            $field_collection = entity_load('field_collection_item', array($address_fieldcoll['value']));
            $vpfinfo = "";
            foreach ($field_collection as $vpfterm_entity) {
                if (isset($vpfterm_entity->field_vpftype[$node->language][0]['value']))
                    $vpfinfo.="<vpftype>" . $vpfterm_entity->field_vpftype[$node->language][0]['value'] . "</vpftype>" . PHP_EOL;

                if (isset($vpfterm_entity->field_vpf_ptvctcnt[$node->language][0]['value']))
                    $vpfinfo.="<ptvctcnt>" . $vpfterm_entity->field_vpf_ptvctcnt[$node->language][0]['value'] . "</ptvctcnt>" . PHP_EOL;
            }
            if ($vpfinfo != "") {
                $vpfterm.= "<vpfinfo>" . $vpfinfo . "</vpfinfo>" . PHP_EOL;
            }
        }

        if ($vpfterm != "") {
            $ptvctinf.= "<vpfterm>" . $vpfinfo . "</vpfterm>" . PHP_EOL;
        }

        if ($ptvctinf != "") {
            $spdoinfo.="<ptvctinf>" . PHP_EOL . $ptvctinf . "</ptvctinf>" . PHP_EOL;
        }
    }
    if ($spdoinfo != "") {
        $spdoinfo = "<spdoinfo>" . PHP_EOL . $spdoinfo . "</spdoinfo>" . PHP_EOL;
    }
    $xml.=$spdoinfo;

    $spref = "";
    $horizsys = "";
    $geograph = "";
    if (isset($node->field_latres[$node->language][0]['value']))
        $geograph.="<latres>" . $node->field_latres[$node->language][0]['value'] . "</latres>" . PHP_EOL;
    if (isset($node->field_longres[$node->language][0]['value']))
        $geograph.="<longres>" . $node->field_longres[$node->language][0]['value'] . "</longres>" . PHP_EOL;
    if (isset($node->field_geogunit[$node->language][0]['value']))
        $geograph.="<geogunit>" . $node->field_geogunit[$node->language][0]['value'] . "</geogunit>" . PHP_EOL;

    if ($geograph != "") {
        $horizsys.="<geograph>" . PHP_EOL . $geograph . "</geograph>" . PHP_EOL;
    }

    $geodetic = "";
    if (isset($node->field_horizdn[$node->language][0]['value']))
        $geodetic.="<horizdn>" . $node->field_horizdn[$node->language][0]['value'] . "</horizdn>" . PHP_EOL;
    if (isset($node->field_ellips[$node->language][0]['value']))
        $geodetic.="<ellips>" . $node->field_ellips[$node->language][0]['value'] . "</ellips>" . PHP_EOL;
    if (isset($node->field_semiaxis[$node->language][0]['value']))
        $geodetic.="<semiaxis>" . $node->field_semiaxis[$node->language][0]['value'] . "</semiaxis>" . PHP_EOL;
    if (isset($node->field_denflat[$node->language][0]['value']))
        $geodetic.="<denflat>" . $node->field_denflat[$node->language][0]['value'] . "</denflat>" . PHP_EOL;

    if ($geodetic != "") {
        $horizsys.="<geodetic>" . PHP_EOL . $geodetic . "</geodetic>" . PHP_EOL;
    }

    $local = "";
    if (isset($node->field_localdes[$node->language][0]['value']))
        $local.="<localdes>" . $node->field_localdes[$node->language][0]['value'] . "</localdes>" . PHP_EOL;

    if (isset($node->field_localgeo[$node->language][0]['value']))
        $local.="<localgeo>" . $node->field_localgeo[$node->language][0]['value'] . "</localgeo>" . PHP_EOL;

    if ($local != "") {
        $horizsys.="<local>" . PHP_EOL . $local . "</local>" . PHP_EOL;
    }

    $planar = "";

    foreach ($node->field_planar[$node->language] as $planar_field) {
        $field_collection = entity_load('field_collection_item', array($planar_field['value']));
        $planci = "";
        foreach ($field_collection as $planar_entity) {
            if (isset($planar_entity->field_plance[$node->language][0]['value']))
                $planci.="<plance>" . $planar_entity->field_plance[$node->language][0]['value'] . "</plance>" . PHP_EOL;
            if (isset($planar_entity->field_plandu[$node->language][0]['value']))
                $planci.="<plandu>" . $planar_entity->field_plandu[$node->language][0]['value'] . "</plandu>" . PHP_EOL;

            foreach ($planar_entity->field_coordrep[$node->language] as $coordrep_field) {
                $field_collection = entity_load('field_collection_item', array($coordrep_field['value']));
                $coordrep = "";
                foreach ($field_collection as $coordrep_entity) {
                    if (isset($coordrep_entity->field_absres[$node->language][0]['value']))
                        $coordrep.="<absres>" . $coordrep_entity->field_absres[$node->language][0]['value'] . "</absres>" . PHP_EOL;
                    if (isset($coordrep_entity->field_ordres[$node->language][0]['value']))
                        $coordrep.="<ordres>" . $coordrep_entity->field_ordres[$node->language][0]['value'] . "</ordres>" . PHP_EOL;
                }
                if ($coordrep != "") {
                    $planci.="<coordrep>" . PHP_EOL . $coordrep . "</coordrep>" . PHP_EOL;
                }
            }

            foreach ($planar_entity->field_distbrep[$node->language] as $distbrep_field) {
                $field_collection = entity_load('field_collection_item', array($distbrep_field['value']));
                $distbrep = "";
                foreach ($field_collection as $distbrep_entity) {
                    if (isset($distbrep_entity->field_distres[$node->language][0]['value']))
                        $distbrep.="<distres>" . $distbrep_entity->field_distres[$node->language][0]['value'] . "</distres>" . PHP_EOL;
                    if (isset($distbrep_entity->field_bearres[$node->language][0]['value']))
                        $distbrep.="<bearres>" . $distbrep_entity->field_bearres[$node->language][0]['value'] . "</bearres>" . PHP_EOL;
                    if (isset($distbrep_entity->field_bearunit[$node->language][0]['value']))
                        $distbrep.="<bearunit>" . $distbrep_entity->field_bearunit[$node->language][0]['value'] . "</bearunit>" . PHP_EOL;
                    if (isset($distbrep_entity->field_bearrefd[$node->language][0]['value']))
                        $distbrep.="<bearrefd>" . $distbrep_entity->field_bearrefd[$node->language][0]['value'] . "</bearrefd>" . PHP_EOL;
                }
                if ($distbrep != "") {
                    $planci.="<distbrep>" . PHP_EOL . $distbrep . "</distbrep>" . PHP_EOL;
                }
            }
        }
        if ($planci != "")
            $planar .= "<planci>" . PHP_EOL . $planci . "</planci>" . PHP_EOL;
    }

    if ($planar != "") {
        $horizsys.="<planar>" . PHP_EOL . $planar . "</planar>" . PHP_EOL;
    }

    if ($horizsys != "") {
        $spref.= "<horizsys>" . PHP_EOL . $horizsys . "</horizsys>" . PHP_EOL;
    }

    //vertical coordinate system
    $vertdef = "";
    $altsys = "";
    if (isset($node->field_altdatum[$node->language][0]['value']))
        $altsys.="<altdatum>" . $node->field_altdatum[$node->language][0]['value'] . "</altdatum>" . PHP_EOL;

    foreach ($node->field_altres[$node->language] as $altres_entity)
        $altsys.="<altres>" . $altres_entity['value'] . "</altres>" . PHP_EOL;

    if (isset($node->field_altunits[$node->language][0]['value']))
        $altsys.="<altunits>" . $node->field_altunits[$node->language][0]['value'] . "</altunits>" . PHP_EOL;

    if (isset($node->field_altenc[$node->language][0]['value']))
        $altsys.="<altenc>" . $node->field_altenc[$node->language][0]['value'] . "</altenc>" . PHP_EOL;

    if ($altsys != "") {
        $vertdef.="<altsys>" . $altsys . "</altsys>" . PHP_EOL;
    }

    $depthsys = "";
    if (isset($node->field_depthdn[$node->language][0]['value'])) {
        $depthsys.="<depthdn>" . $node->field_depthdn[$node->language][0]['value'] . "</depthdn>" . PHP_EOL;
    }
    foreach ($node->field_depthres[$node->language] as $depthres_entity)
        $depthsys.="<depthres>" . $depthres_entity['value'] . "</depthres>" . PHP_EOL;

    if (isset($node->field_depthdu[$node->language][0]['value']))
        $depthsys.="<depthdu>" . $node->field_depthdu[$node->language][0]['value'] . "</depthdu>" . PHP_EOL;
    if (isset($node->field_depthem[$node->language][0]['value']))
        $depthsys.="<depthem>" . $node->field_depthem[$node->language][0]['value'] . "</depthem>" . PHP_EOL;

    if ($depthsys != "") {
        $vertdef.="<depthsys>" . PHP_EOL . $depthsys . "</depthsys>" . PHP_EOL;
    }

    if ($vertdef != "") {
        $spref.= "<vertdef>" . PHP_EOL . $vertdef . "</vertdef>" . PHP_EOL;
    }

    if ($spref != "") {
        $xml.="<spref>" . PHP_EOL . $spref . "</spref>" . PHP_EOL;
    }

    $eainfo = "";
    foreach ($node->field_en_detail_desc[$node->language] as $detail_desc_field) {
        $field_collection = entity_load('field_collection_item', array($detail_desc_field['value']));
        $enttyp = "";
        $detailed = "";
        foreach ($field_collection as $detail_desc_entity) {
            if (isset($detail_desc_entity->field_enttypl[$node->language][0]['value']))
                $enttyp.="<enttypl>" . $detail_desc_entity->field_enttypl[$node->language][0]['value'] . "</enttypl>" . PHP_EOL;
            if (isset($detail_desc_entity->field_enttypd[$node->language][0]['value']))
                $enttyp.="<enttypd>" . $detail_desc_entity->field_enttypd[$node->language][0]['value'] . "</enttypd>" . PHP_EOL;
            if (isset($detail_desc_entity->field_enttypds[$node->language][0]['value']))
                $enttyp.="<enttypds>" . $detail_desc_entity->field_enttypds[$node->language][0]['value'] . "</enttypds>" . PHP_EOL;
        }
        if ($enttyp != "") {
            $detailed.="<enttyp>" . PHP_EOL . $enttyp . "</enttyp>" . PHP_EOL;
        }
        //attribute
        foreach ($detail_desc_entity->field_attr[$node->language] as $attr_field) {
            $field_collection1 = entity_load('field_collection_item', array($attr_field['value']));
            $attr = "";
            foreach ($field_collection1 as $attr_entity) {
                if (isset($attr_entity->field_attrlabl[$node->language][0]['value']))
                    $attr.="<attrlabl>" . $attr_entity->field_attrlabl[$node->language][0]['value'] . "</attrlabl>" . PHP_EOL;
                if (isset($attr_entity->field_attrdef[$node->language][0]['value']))
                    $attr.="<attrdef>" . $attr_entity->field_attrdef[$node->language][0]['value'] . "</attrdef>" . PHP_EOL;
                if (isset($attr_entity->field_attrdefs[$node->language][0]['value']))
                    $attr.="<attrdefs>" . $attr_entity->field_attrdefs[$node->language][0]['value'] . "</attrdefs>" . PHP_EOL;

                $attrvai = "";
                if (isset($attr_entity->field_attrva[$node->language][0]['value']))
                    $attrvai.="<attrva>" . $attr_entity->field_attrva[$node->language][0]['value'] . "</attrva>" . PHP_EOL;
                if (isset($attr_entity->field_attrvae[$node->language][0]['value']))
                    $attrvai.="<attrvae>" . $attr_entity->field_attrvae[$node->language][0]['value'] . "</attrvae>" . PHP_EOL;

                if ($attrvai != "") {
                    $attr.="<attrvai>" . PHP_EOL . "</attrvai>" . PHP_EOL;
                }

                if (isset($attr_entity->field_attrmfrq[$node->language][0]['value']))
                    $attr.="<attrmfrq>" . $attr_entity->field_attrmfrq[$node->language][0]['value'] . "</attrmfrq>" . PHP_EOL;

                //attr_dates
                foreach ($attr_entity->field_attr_dates[$node->language] as $attr_dates_field) {
                    $field_collection2 = entity_load('field_collection_item', array($attr_dates_field['value']));
                    foreach ($field_collection2 as $attr_dates_entity) {
                        if (isset($attr_dates_entity->field_begdatea[$node->language][0]['value']))
                            $attr.="<begdatea>" . $attr_dates_entity->field_begdatea[$node->language][0]['value'] . "</begdatea>" . PHP_EOL;
                        if (isset($attr_dates_entity->field_enddatea[$node->language][0]['value']))
                            $attr.="<enddatea>" . $attr_dates_entity->field_enddatea[$node->language][0]['value'] . "</enddatea>" . PHP_EOL;
                    }
                }

                foreach ($attr_entity->field_attrdomv[$node->language] as $attrdomv_field) {
                    $field_collection3 = entity_load('field_collection_item', array($attrdomv_field['value']));
                    $attrdomv = "";
                    foreach ($field_collection3 as $attrdomv_entity) {
                        if (isset($attrdomv_entity->field_udom[$node->language][0]['value']))
                            $attrdomv.="<udom>" . $attrdomv_entity->field_udom[$node->language][0]['value'] . "</udom>" . PHP_EOL;

                        //edom
                        foreach ($attrdomv_entity->field_edom[$node->language] as $edom_field) {
                            $field_collection4 = entity_load('field_collection_item', array($edom_field['value']));
                            $edom = "";
                            foreach ($field_collection4 as $edom_entity) {
                                if (isset($edom_entity->field_edomv[$node->language][0]['value']))
                                    $edom.="<edomv>" . $edom_entity->field_edomv[$node->language][0]['value'] . "</edomv>" . PHP_EOL;
                                if (isset($edom_entity->field_edomvd[$node->language][0]['value']))
                                    $edom.="<edomvd>" . $edom_entity->field_edomvd[$node->language][0]['value'] . "</edomvd>" . PHP_EOL;
                                if (isset($edom_entity->field_edomvds[$node->language][0]['value']))
                                    $edom.="<edomvds>" . $edom_entity->field_edomvds[$node->language][0]['value'] . "</edomvds>" . PHP_EOL;
                            }
                            if ($edom != "") {
                                $attrdomv.="<edom>" . PHP_EOL . $edom . "</edom>" . PHP_EOL;
                            }
                        }
                        //rdom
                        foreach ($attrdomv_entity->field_rdom[$node->language] as $rdom_field) {
                            $field_collection5 = entity_load('field_collection_item', array($rdom_field['value']));
                            $rdom = "";
                            foreach ($field_collection5 as $rdom_entity) {
                                if (isset($rdom_entity->field_rdommin[$node->language][0]['value']))
                                    $rdom.="<rdommin>" . $rdom_entity->field_rdommin[$node->language][0]['value'] . "</rdommin>" . PHP_EOL;
                                if (isset($rdom_entity->field_rdommax[$node->language][0]['value']))
                                    $rdom.="<rdommax>" . $rdom_entity->field_rdommax[$node->language][0]['value'] . "</rdommax>" . PHP_EOL;
                                if (isset($rdom_entity->field_attrunit[$node->language][0]['value']))
                                    $rdom.="<attrunit>" . $rdom_entity->field_attrunit[$node->language][0]['value'] . "</attrunit>" . PHP_EOL;
                                if (isset($rdom_entity->field_attrmres[$node->language][0]['value']))
                                    $rdom.="<attrmres>" . $rdom_entity->field_attrmres[$node->language][0]['value'] . "</attrmres>" . PHP_EOL;
                            }
                            if ($rdom != "") {
                                $attrdomv.="<rdom>" . PHP_EOL . $rdom . "</rdom>" . PHP_EOL;
                            }
                        }

                        //codesetd
                        foreach ($attrdomv_entity->field_codesetd[$node->language] as $rdom_field) {
                            $field_collection5 = entity_load('field_collection_item', array($rdom_field['value']));
                            $rdom = "";
                            foreach ($field_collection5 as $rdom_entity) {
                                if (isset($rdom_entity->field_codesetn[$node->language][0]['value']))
                                    $rdom.="<codesetn>" . $rdom_entity->field_codesetn[$node->language][0]['value'] . "</codesetn>" . PHP_EOL;
                                if (isset($rdom_entity->field_codesets[$node->language][0]['value']))
                                    $rdom.="<codesets>" . $rdom_entity->field_codesets[$node->language][0]['value'] . "</codesets>" . PHP_EOL;
                            }
                            if ($rdom != "") {
                                $attrdomv.="<codesetd>" . PHP_EOL . $rdom . "</codesetd>" . PHP_EOL;
                            }
                        }
                    }
                    if ($attrdomv != "") {
                        $attr.="<attrdomv>" . PHP_EOL . $attrdomv . "</attrdomv>" . PHP_EOL;
                    }
                }
            }
            if ($attr != "") {
                $detailed.="<attr>" . PHP_EOL . $attr . "</attr>" . PHP_EOL;
            }
        }

        if ($detailed != "") {
            $eainfo.= "<detailed>" . PHP_EOL . $detailed . "</detailed>" . PHP_EOL;
        }
    }

    foreach ($node->field_en_overview[$node->language] as $overview_field) {
        $field_collection = entity_load('field_collection_item', array($overview_field['value']));
        $overview = "";
        foreach ($field_collection as $overview_entity) {
            if (isset($overview_entity->field_eaover[$node->language][0]['value']))
                $overview.= "<eaover>" . $overview_entity->field_eaover[$node->language][0]['value'] . "</eaover>" . PHP_EOL;
            foreach ($overview_entity->field_eadetcit[$node->language] as $eadetcit_entity)
                $overview.= "<eadetcit>" . $eadetcit_entity['value'] . "</eadetcit>" . PHP_EOL;
        }
        if ($overview != "") {
            $eainfo.= "<overview>" . PHP_EOL . $overview . "</overview>" . PHP_EOL;
        }
    }
    if ($eainfo != "") {
        $xml.="<eainfo>" . PHP_EOL . $eainfo . "</eainfo>" . PHP_EOL;
    }

    //// Distribution
    foreach ($node->field_distribution[$node->language] as $distribution_field) {
        $field_collection = entity_load('field_collection_item', array($distribution_field['value']));
        $distinfo = "";
        foreach ($field_collection as $distribution_entity) {
            if (isset($distribution_entity->field_resdesc[$node->language][0]['value']))
                $distinfo.="<resdesc>" . $distribution_entity->field_resdesc[$node->language][0]['value'] . "</resdesc>" . PHP_EOL;
            if (isset($distribution_entity->field_distliab[$node->language][0]['value']))
                $distinfo.="<distliab>" . $distribution_entity->field_distliab[$node->language][0]['value'] . "</distliab>" . PHP_EOL;
            if (isset($distribution_entity->field_custom[$node->language][0]['value']))
                $distinfo.="<custom>" . $distribution_entity->field_custom[$node->language][0]['value'] . "</custom>" . PHP_EOL;
            if (isset($distribution_entity->field_techpreq[$node->language][0]['value']))
                $distinfo.="<techpreq>" . $distribution_entity->field_techpreq[$node->language][0]['value'] . "</techpreq>" . PHP_EOL;

            foreach ($distribution_entity->field_stdorder[$node->language] as $stdorder_field) {
                $field_collection1 = entity_load('field_collection_item', array($stdorder_field['value']));
                $stdorder = "";
                foreach ($field_collection1 as $stdorder_entity) {
                    if (isset($stdorder_entity->field_fees[$node->language][0]['value']))
                        $stdorder.="<fees>" . $stdorder_entity->field_fees[$node->language][0]['value'] . "</fees>" . PHP_EOL;
                    if (isset($stdorder_entity->field_ordering[$node->language][0]['value']))
                        $stdorder.="<ordering>" . $stdorder_entity->field_ordering[$node->language][0]['value'] . "</ordering>" . PHP_EOL;
                    if (isset($stdorder_entity->field_turnarnd[$node->language][0]['value']))
                        $stdorder.="<turnarnd>" . $stdorder_entity->field_turnarnd[$node->language][0]['value'] . "</turnarnd>" . PHP_EOL;
                    if (isset($stdorder_entity->field_nondig[$node->language][0]['value']))
                        $stdorder.="<nondig>" . $stdorder_entity->field_nondig[$node->language][0]['value'] . "</nondig>" . PHP_EOL;

                    foreach ($stdorder_entity->field_digform[$node->language] as $digform_field) {
                        $field_collection2 = entity_load('field_collection_item', array($digform_field['value']));
                        $digform = "";
                        $digtinfo = "";
                        foreach ($field_collection2 as $digform_entity) {
                            if (isset($digform_entity->field_formname[$node->language][0]['value']))
                                $digtinfo.="<formname>" . $digform_entity->field_formname[$node->language][0]['value'] . "</formname>" . PHP_EOL;
                            if (isset($digform_entity->field_formvern[$node->language][0]['value']))
                                $digtinfo.="<formvern>" . $digform_entity->field_formvern[$node->language][0]['value'] . "</formvern>" . PHP_EOL;
                            if (isset($digform_entity->field_formverd[$node->language][0]['value']))
                                $digtinfo.="<formverd>" . $digform_entity->field_formverd[$node->language][0]['value'] . "</formverd>" . PHP_EOL;

                            if (isset($digform_entity->field_formspec[$node->language][0]['value']))
                                $digtinfo.="<formspec>" . $digform_entity->field_formspec[$node->language][0]['value'] . "</formspec>" . PHP_EOL;
                            if (isset($digform_entity->field_formcont[$node->language][0]['value']))
                                $digtinfo.="<formcont>" . $digform_entity->field_formcont[$node->language][0]['value'] . "</formcont>" . PHP_EOL;
                            if (isset($digform_entity->field_filedec[$node->language][0]['value']))
                                $digtinfo.="<filedec>" . $digform_entity->field_filedec[$node->language][0]['value'] . "</filedec>" . PHP_EOL;
                            if (isset($digform_entity->field_transize[$node->language][0]['value']))
                                $digtinfo.="<transize>" . $digform_entity->field_transize[$node->language][0]['value'] . "</transize>" . PHP_EOL;

                            if ($digtinfo != "") {
                                $digform.="<digtinfo>" . PHP_EOL . $digtinfo . "</digtinfo>" . PHP_EOL;
                            }
                            $digtopt = "";
                            foreach ($digform_entity->field_onlinopt[$node->language] as $onlineopt_field) {
                                $fieldcollection3 = entity_load('field_collection_item', array($onlineopt_field['value']));
                                $onlineopt = "";
                                foreach ($fieldcollection3 as $onlineopt_entity) {
                                    if (isset($onlineopt_entity->field_accinstr[$node->language][0]['value']))
                                        $onlineopt.="<accinstr>" . $onlineopt_entity->field_accinstr[$node->language][0]['value'] . "</accinstr>" . PHP_EOL;
                                    if (isset($onlineopt_entity->field_oncomp[$node->language][0]['value']))
                                        $onlineopt.="<oncomp>" . $onlineopt_entity->field_oncomp[$node->language][0]['value'] . "</oncomp>" . PHP_EOL;

                                    foreach ($onlineopt_entity->field_computer[$node->language] as $computer_field) {
                                        $field_collection4 = entity_load('field_collection_item', array($computer_field['value']));
                                        $computer = "";
                                        foreach ($field_collection4 as $computer_entity) {
                                            $networka = "";
                                            foreach ($computer_entity->field_networkr[$node->language] as $networkr_entity) {
                                                $networka.="<networkr>" . $networkr_entity['value'] . "</networkr>" . PHP_EOL;
                                            }
                                            if ($networka != "") {
                                                $computer.="<networka>" . PHP_EOL . $networka . "</networka>" . PHP_EOL;
                                            }
                                            $dialinst = "";
                                            if (isset($computer_entity->field_lowbps[$node->language][0]['value'])) {
                                                $dialinst.="<lowbps>" . $computer_entity->field_lowbps[$node->language][0]['value'] . "</lowbps>" . PHP_EOL;
                                            }
                                            if (isset($computer_entity->field_highbps[$node->language][0]['value'])) {
                                                $dialinst.="<highbps>" . $computer_entity->field_highbps[$node->language][0]['value'] . "</highbps>" . PHP_EOL;
                                            }
                                            if (isset($computer_entity->field_numdata[$node->language][0]['value'])) {
                                                $dialinst.="<numdata>" . $computer_entity->field_numdata[$node->language][0]['value'] . "</numdata>" . PHP_EOL;
                                            }
                                            if (isset($computer_entity->field_numstop[$node->language][0]['value'])) {
                                                $dialinst.="<numstop>" . $computer_entity->field_numstop[$node->language][0]['value'] . "</numstop>" . PHP_EOL;
                                            }
                                            if (isset($computer_entity->field_parity[$node->language][0]['value'])) {
                                                $dialinst.="<parity>" . $computer_entity->field_parity[$node->language][0]['value'] . "</parity>" . PHP_EOL;
                                            }
                                            if (isset($computer_entity->field_compress[$node->language][0]['value'])) {
                                                $dialinst.="<compress>" . $computer_entity->field_compress[$node->language][0]['value'] . "</compress>" . PHP_EOL;
                                            }
                                            foreach ($computer_entity->field_dialtel as $dialtel_entity) {
                                                $dialinst.="<dialtel>" . $dialtel_entity['value'] . "</dialtel>" . PHP_EOL;
                                            }
                                            foreach ($computer_entity->field_dialfile as $dialfile_entity) {
                                                $dialinst.="<dialfile>" . $dialfile_entity['value'] . "</dialfile>" . PHP_EOL;
                                            }
                                            if ($dialinst != "") {
                                                $computer.="<dialinst>" . PHP_EOL . $dialinst . "</dialinst>" . PHP_EOL;
                                            }
                                        }

                                        if ($computer != "") {
                                            $onlineopt.="<computer>" . PHP_EOL . $computer . "</computer>" . PHP_EOL;
                                        }
                                    }
                                }
                                if ($onlineopt != "") {
                                    $digtopt.="<onlineopt>" . PHP_EOL . $onlineopt . "</onlineopt>" . PHP_EOL;
                                }
                            }
                            $offoptn = "";
                            foreach ($digform_entity->field_offoptn[$node->language] as $offoptn_field) {
                                $field_collection5 = entity_load('field_collection_item', array($offoptn_field['value']));
                                $offoptn.="";
                                foreach ($field_collection5 as $offoptn_entity) {
                                    if (isset($offoptn_entity->field_offmedia[$node->language][0]['value'])) {
                                        $offoptn.="<offmedia>" . $offoptn_entity->field_offmedia[$node->language][0]['value'] . "</offmedia>" . PHP_EOL;
                                    }
                                    $reccap = "";
                                    foreach ($offoptn_entity->field_recden[$node->language] as $recden_entity) {
                                        $reccap.="<recden>" . $recden_entity['value'] . "</recden>" . PHP_EOL;
                                    }
                                    if (isset($offoptn_entity->field_recdenu[$node->language][0]['value'])) {
                                        $reccap.="<recdenu>" . $offoptn_entity->field_recdenu[$node->language][0]['value'] . "</recdenu>" . PHP_EOL;
                                    }

                                    if ($recap != "") {
                                        $offoptn.="<reccap>" . PHP_EOL . "</reccap>" . PHP_EOL;
                                    }

                                    foreach ($offoptn_entity->field_compat[$node->language] as $compat_entity) {
                                        $offoptn.="<compat>" . $compat_entity['value'] . "</compat>" . PHP_EOL;
                                    }

                                    if (isset($offoptn_entity->field_compat[$node->language][0]['value'])) {
                                        $offoptn.="<compat>" . $offoptn_entity->field_compat[$node->language][0]['value'] . "</compat>" . PHP_EOL;
                                    }
                                }

                                if ($offoptn != "") {
                                    $digtopt.="<offoptn>" . PHP_EOL . $offoptn . "</offoptn>" . PHP_EOL;
                                }
                            }

                            if ($digtopt != "") {
                                $digform.="<digtopt>" . PHP_EOL . $digtopt . "</digtopt>" . PHP_EOL;
                            }
                        }

                        if ($digform != "") {
                            $stdorder.="<digform>" . PHP_EOL . $digform . "</digform>" . PHP_EOL;
                        }
                    }
                }
                if ($stdorder != "") {
                    $distinfo.="<stdorder>" . PHP_EOL . $stdorder . "</stdorder>" . PHP_EOL;
                }
            }
            $distrib = "";
            $distrib = contact_info($distribution_entity, $node);
            if ($distrib != "") {
                $distinfo.="<distrib>" . PHP_EOL . $distrib . "</distrib>" . PHP_EOL;
            }
            $distinfo.=time_info($distribution_entity, $node, "availabl");
        }
        if ($distinfo != "") {
            $xml.="<distinfo>" . PHP_EOL . $distinfo . "</distinfo>" . PHP_EOL;
        }
    }
    //end Distribution


    $metainfo = "";

    if (isset($node->field_metrd[$node->language][0]['value']) && $node->field_metrd[$node->language][0]['value'] != "") {
        $metainfo.="<metd>" . PHP_EOL . $node->field_metrd[$node->language][0]['value'] . "</metd>" . PHP_EOL;
    }

    if (isset($node->field_metfrd[$node->language][0]['value']) && $node->field_metfrd[$node->language][0]['value'] != "") {
        $metainfo.="<metrd>" . PHP_EOL . $node->field_metfrd[$node->language][0]['value'] . "</metrd>" . PHP_EOL;
    }

    if (isset($node->field_metac[$node->language][0]['value']) && $node->field_metac[$node->language][0]['value'] != "") {
        $metainfo.="<metfrd>" . PHP_EOL . $node->field_metac[$node->language][0]['value'] . "</metfrd>" . PHP_EOL;
    }

    if (isset($node->field_metac[$node->language][0]['value']) && $node->field_metac[$node->language][0]['value'] != "") {
        $metainfo.="<metac>" . PHP_EOL . $node->field_metac[$node->language][0]['value'] . "</metac>" . PHP_EOL;
    }
    if (isset($node->field_metuc[$node->language][0]['value']) && $node->field_metuc[$node->language][0]['value'] != "") {
        $metainfo.="<metuc>" . PHP_EOL . $node->field_metuc[$node->language][0]['value'] . "</metuc>" . PHP_EOL;
    }
    if (isset($node->field_metstdn[$node->language][0]['value']) && $node->field_metstdn[$node->language][0]['value'] != "") {
        $metainfo.="<metstdn>" . PHP_EOL . $node->field_metstdn[$node->language][0]['value'] . "</metstdn>" . PHP_EOL;
    }
    if (isset($node->field_metstdv[$node->language][0]['value']) && $node->field_metstdv[$node->language][0]['value'] != "") {
        $metainfo.="<metstdv>" . PHP_EOL . $node->field_metstdv[$node->language][0]['value'] . "</metstdv>" . PHP_EOL;
    }
    if (isset($node->field_mettc[$node->language][0]['value']) && $node->field_mettc[$node->language][0]['value'] != "") {
        $metainfo.="<mettc>" . PHP_EOL . $node->field_mettc[$node->language][0]['value'] . "</mettc>" . PHP_EOL;
    }
    $metsi = "";
    if (isset($node->field_metscs[$node->language][0]['value']) && $node->field_metscs[$node->language][0]['value'] != "") {
        $metsi.="<metscs>" . PHP_EOL . $node->field_metscs[$node->language][0]['value'] . "</metscs>" . PHP_EOL;
    }
    if (isset($node->field_metsc[$node->language][0]['value']) && $node->field_metsc[$node->language][0]['value'] != "") {
        $metsi.="<metsc>" . PHP_EOL . $node->field_metsc[$node->language][0]['value'] . "</metsc>" . PHP_EOL;
    }
    if (isset($node->field_metac[$node->language][0]['value']) && $node->field_metac[$node->language][0]['value'] != "") {
        $metsi.="<metshd>" . PHP_EOL . $node->field_metac[$node->language][0]['value'] . "</metshd>" . PHP_EOL;
    }

    if ($metsi != "") {
        $metainfo.="<metsi>" . PHP_EOL . $metsi . "</metsi>" . PHP_EOL;
    }

    foreach ($node->field_metextns[$node->language] as $metextns_field) {
        $field_collection = entity_load('field_collection_item', array($metextns_field['value']));
        $metextns = "";
        foreach ($field_collection as $metextns_entity) {
            foreach ($metextns_entity->field_onlink[$node->language] as $metext_onnlink) {
                $metextns.="<metshd>" . PHP_EOL . $metext_onnlink['url'] . "</metshd>" . PHP_EOL;
            }
            if (isset($metextns_entity->field_metprof[$node->language][0]['value']) && $metextns_entity->field_metprof[$node->language][0]['value'] != "") {
                $metextns.="<metprof>" . PHP_EOL . $metextns_entity->field_metprof[$node->language][0]['value'] . "</metprof>" . PHP_EOL;
            }
        }
        if ($metextns != "") {
            $metainfo.="<metextns>" . PHP_EOL . $metextns . "</metextns>" . PHP_EOL;
        }
    }

    $metc = "";
    $metc = contact_info($node, $node);
    if ($metc != "") {
        $metainfo.="<metc>" . PHP_EOL . $metc . "</metc>" . PHP_EOL;
    }
    if ($metainfo != "") {
        $xml.="<metainfo>" . PHP_EOL . $metainfo . "</metainfo>" . PHP_EOL;
    }

    $xml.="</metadata>";
    fwrite($fh, $xml);
    fclose($fh);
}


function exportToDataCast() {
    $nid= str_replace("node/","",$_GET["q"]);
    $nid= str_replace("/datacast","",$nid);

    $node = node_load($nid);
        writeXMLFileForDatacast($node);
    exit;
}

function writeXMLFileForDatacast($node) {

    // Creates the Document.
    $domXML = new DOMDocument('1.0', 'UTF-8');
    $domXML->formatOutput = true;

    // Creates the XML root element and appends it to the Document.
    $rss = $domXML->createElementNS('http://www.w3.org/2005/Atom', 'rss');
    $domXML->appendChild($rss);
    $rss->setAttributeNS('http://www.w3.org/2000/xmlns/' ,'xmlns:datacasting', 'http://datacasting.jpl.nasa.gov/datacasting');

    $node->language = LANGUAGE_NONE;

    $channel = $domXML->createElement('channel');
    $rss->appendChild($channel);

    foreach ($node->field_origin[$node->language] as $origin) {
        $origin = $domXML->createElement('origin', $origin['value']);
        $channel->appendChild($origin);
    }

    // Required fields are marked with *
    // *title
    $title = $domXML->createElement('title', $node->title);
    $channel->appendChild($title);

    // Publication Date
    if (isset($node->field_pubdate[$node->language])) {
        $pubdate = $domXML->createElement('pubdate', $node->field_pubdate[$node->language][0]['value']);
        $channel->appendChild($pubdate);
    }
    // *link: Online Linkage
    foreach ($node->field_onlink[$node->language] as $onlink) {
        $link = $domXML->createElement('link', $onlink['url']);
        $channel->appendChild($link);
    }
    // *description
    $description = $domXML->createElement('description');
    $channel->appendChild($description);

    if (isset($node->field_core_description[$node->language]) && $node->field_core_description[$node->language][0]['value'] != "") {
        $abstract = $domXML->createElement('abstract', $node->field_core_description[$node->language][0]['value']);
        $description->appendChild($abstract);
    }
    if (isset($node->field_purpose[$node->language]) && $node->field_purpose[$node->language][0]['value'] != "") {
        $purpose = $domXML->createElement('purpose', $node->field_purpose[$node->language][0]['value']);
        $description->appendChild($purpose);
    }
    if (isset($node->field_supplinf[$node->language]) && $node->field_supplinf[$node->language][0]['value'] != "") {
        $supplinf = $domXML->createElement('supplinf', $node->field_supplinf[$node->language][0]['value']);
        $description->appendChild($supplinf);
    }

    // datacasting: channelUID
    $channelUID = $domXML->createElement('datacasting:channelUID', $node->nid);
    $channel->appendChild($channelUID);

    echo $domXML->saveXML();
}

function contact_info($base_entity, $node) {
    $cntinfocollection = "";
    foreach ($base_entity->field_contact_info[$node->language] as $proc_contactinfo) {
        $field_collection = entity_load('field_collection_item', array($proc_contactinfo['value']));
        $cntinfo = "";
        //only one time
        foreach ($field_collection as $proc_contactinfo_entity) {
            $cntinfo = "";
            $cntorgp = "";

            if (isset($proc_contactinfo_entity->field_cont_cit_name_org[$node->language][0]['value'])) {
                $cntorgp.="<cntorg>" . $proc_contactinfo_entity->field_cont_cit_name_org[$node->language][0]['value'] . "</cntorg>" . PHP_EOL;
            }
            if (isset($proc_contactinfo_entity->field_cont_cit_name_person[$node->language][0]['value'])) {
                $cntorgp.="<cntper>" . $proc_contactinfo_entity->field_cont_cit_name_person[$node->language][0]['value'] . "</cntper>" . PHP_EOL;
            }
            if ($cntorgp != "") {
                $cntorgp = "<cntorgp>" . PHP_EOL . $cntorgp . "</cntorgp>" . PHP_EOL;
            }

            $cntaddrcollection = "";
            foreach ($proc_contactinfo_entity->field_iden_originator_add[$node->language] as $address_fieldcoll) {
                $field_collection = entity_load('field_collection_item', array($address_fieldcoll['value']));
                $cntaddr = "";
                foreach ($field_collection as $address_entity) {
                    if (isset($address_entity->field_address_type[$node->language][0]['value'])) {
                        $cntaddr .="<addrtype>" . $address_entity->field_address_type[$node->language][0]['value'] . "</addrtype>" . PHP_EOL;
                    }
                    foreach ($address_entity->field_cont_cit_street[$node->language] as $inside_address) {
                        $cntaddr.="<address>" . $inside_address['value'] . "</address>" . PHP_EOL;
                    }
                    if (isset($address_entity->field_cont_cit_city[$node->language][0]['value'])) {
                        $cntaddr .="<city>" . $address_entity->field_cont_cit_city[$node->language][0]['value'] . "</city>" . PHP_EOL;
                    }
                    if (isset($address_entity->field_cont_cit_province[$node->language][0]['value'])) {
                        $cntaddr .="<state>" . $address_entity->field_cont_cit_province[$node->language][0]['value'] . "</state>" . PHP_EOL;
                    }
                    if (isset($address_entity->field_cont_cit_postalcode[$node->language][0]['value'])) {
                        $cntaddr .="<postal>" . $address_entity->field_cont_cit_postalcode[$node->language][0]['value'] . "</postal>" . PHP_EOL;
                    }
                    if (isset($address_entity->field_cont_cit_country[$node->language][0]['value'])) {
                        $cntaddr .="<country>" . $address_entity->field_cont_cit_country[$node->language][0]['value'] . "</country>" . PHP_EOL;
                    }
                }
                if ($cntaddr != "") {
                    $cntaddr = "<cntaddr>" . PHP_EOL . $cntaddr . "</cntaddr>" . PHP_EOL;
                }
                $cntaddrcollection.=$cntaddr;
            }

            $cntinfo.=$cntorgp . $cntaddrcollection;


            if (isset($proc_contactinfo_entity->field_position[$node->language][0]['value'])) {
                $cntinfo.="<cntpos>" . $proc_contactinfo_entity->field_position[$node->language][0]['value'] . "</cntpos>" . PHP_EOL;
            }

            foreach ($proc_contactinfo_entity->field_cont_cit_phone[$node->language] as $phoneaddress) {
                $cntinfo.="<cntvoice>" . $phoneaddress['value'] . "</cntvoice>" . PHP_EOL;
            }

            foreach ($proc_contactinfo_entity->field_cnttdd[$node->language] as $phoneaddress) {
                $cntinfo.="<cnttdd>" . $phoneaddress['value'] . "</cnttdd>" . PHP_EOL;
            }

            foreach ($proc_contactinfo_entity->field_cont_cit_fax[$node->language] as $phoneaddress) {
                $cntinfo.="<cntfax>" . $phoneaddress['value'] . "</cntfax>" . PHP_EOL;
            }

            foreach ($proc_contactinfo_entity->field_cont_cit_email[$node->language] as $phoneaddress) {
                $cntinfo.="<cntemail>" . $phoneaddress['value'] . "</cntemail>" . PHP_EOL;
            }
        }
        if ($cntinfo != "") {
            $cntinfocollection .= "<cntinfo>" . PHP_EOL . $cntinfo . "</cntinfo>" . PHP_EOL;
        }
    }

    return $cntinfocollection;
}

function time_info($base_entity, $node, $collection) {
    $timeinfocollection = "";
    if (isset($base_entity->field_i_iden_timeperiod[$node->language])) {
        $field_collection = entity_load('field_collection_item', array($base_entity->field_i_iden_timeperiod[$node->language][0]['value']));
        foreach ($field_collection as $field_entity) {
            $timeperd = "";
            if (isset($field_entity->field_currentness_ref[$node->language]) && $field_entity->field_currentness_ref[$node->language][0]['value'] != "") {
                $timeperd.="<current>" . $field_entity->field_currentness_ref[$node->language][0]['value'] . "</current>" . PHP_EOL;
            }
            $timeinfo = "";
            $sngdate = "";

            if (isset($field_entity->field_calendar_date[$node->language]) && $field_entity->field_calendar_date[$node->language][0]['value'] != "") {
                $sngdate.="<caldate>" . $field_entity->field_calendar_date[$node->language][0]['value'] . "</caldate>" . PHP_EOL;
            }
            if (isset($field_entity->field_time_of_day[$node->language]) && $field_entity->field_time_of_day[$node->language][0]['value'] != "") {
                $sngdate.="<time>" . $field_entity->field_time_of_day[$node->language][0]['value'] . "</time>" . PHP_EOL;
            }
            if ($sngdate != "") {
                $sngdate = "<sngdate>" . PHP_EOL . $sngdate . "</sngdate>";
            }

            $mdattim = "";
            foreach ($field_entity->field_mul_calendar_datetime[$node->language] as $mulcalendar) {
                $field_collection1 = entity_load('field_collection_item', array($mulcalendar['value']));
                $sngdate1 = "";
                foreach ($field_collection1 as $field_entity1) {
                    $sngdate1.="<caldate>" . $field_entity1->field_calendar_date[$node->language][0]['value'] . "</caldate>" . PHP_EOL;
                    $sngdate1.="<time>" . $field_entity1->field_time_of_day[$node->language][0]['value'] . "</time>" . PHP_EOL;
                }
                if ($sngdate1 != "") {
                    $sngdate = "<sngdate>" . PHP_EOL . $sngdate1 . "</sngdate>";
                    $mdattim.=$sngdate1 . PHP_EOL;
                }
            }
            if ($mdattim != "") {
                $mdattim = "<mdattim>" . PHP_EOL . $mdattim . "</mdattim>";
            }

            $rngdates = "";
            if (isset($field_entity->field_beginning_date[$node->language]) && $field_entity->field_beginning_date[$node->language][0]['value'] != "") {
                $rngdates.="<begdate>" . $field_entity->field_beginning_date[$node->language][0]['value'] . "</begdate>" . PHP_EOL;
            }
            if (isset($field_entity->field_beginning_time[$node->language]) && $field_entity->field_beginning_time[$node->language][0]['value'] != "") {
                $rngdates.="<begtime>" . $field_entity->field_beginning_time[$node->language][0]['value'] . "</begtime>" . PHP_EOL;
            }
            if (isset($field_entity->field_ending_date[$node->language]) && $field_entity->field_ending_date[$node->language][0]['value'] != "") {
                $rngdates.="<enddate>" . $field_entity->field_ending_date[$node->language][0]['value'] . "</enddate>" . PHP_EOL;
            }
            if (isset($field_entity->field_ending_time[$node->language]) && $field_entity->field_ending_time[$node->language][0]['value'] != "") {
                $rngdates.="<endtime>" . $field_entity->field_ending_time[$node->language][0]['value'] . "</endtime>" . PHP_EOL;
            }
            if ($rngdates != "") {
                $rngdates = "<rngdates>" . PHP_EOL . $rngdates . "</rngdates>";
            }

            $timeinfo = $sngdate . PHP_EOL . $rngdates . PHP_EOL . $mdattim;

            if ($timeinfo != "") {
                $timeinfo = "<timeinfo>" . PHP_EOL . $timeinfo . PHP_EOL . "</timeinfo>";
            }
            $timeperd = $timeperd . $timeinfo;

            if ($timeperd != "") {
                $timeinfocollection .="<" . $collection . ">" . PHP_EOL . $timeperd . PHP_EOL . "</" . $collection . ">" . PHP_EOL;
            }
        }
    }
    return $timeinfocollection;
}

?>
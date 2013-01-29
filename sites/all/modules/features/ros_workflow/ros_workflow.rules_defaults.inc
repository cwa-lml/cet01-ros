<?php
/**
 * @file
 * ros_workflow.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ros_workflow_default_rules_configuration() {
  $items = array();
  $items['rules_gotopurchase'] = entity_import('rules_config', '{ "rules_gotopurchase" : {
      "LABEL" : "GotoPurchase",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "button_field", "rules" ],
      "ON" : [ "button_field_clicked" ],
      "IF" : [
        { "button_field_compare_button" : {
            "clicked_field" : [ "field" ],
            "comparison_field_name" : "field_purchedrsrc"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "ros_purchase" } } ]
    }
  }');
  $items['rules_gotowhats'] = entity_import('rules_config', '{ "rules_gotowhats" : {
      "LABEL" : "GotoWhats",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "button_field", "rules" ],
      "ON" : [ "button_field_clicked" ],
      "IF" : [
        { "button_field_compare_button" : {
            "clicked_field" : [ "field" ],
            "comparison_field_name" : "field_freesamples"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "whats-in-resource" } } ]
    }
  }');
  return $items;
}

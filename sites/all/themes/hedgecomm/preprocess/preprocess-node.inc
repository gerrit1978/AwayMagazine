<?php
function hedgecomm_alpha_preprocess_node(&$vars) {
  
  // only for events
  if ($vars['type'] == 'event') {
  
    $vars['show_map'] = FALSE;
  
    // if this node has an address field, use that
    $node = node_load($vars['vid']);
    $address = field_get_items('node', $node, 'field_address');
    if ($address) {
      $vars['show_map'] = TRUE;
      $vars['latitude'] = $address[0]['latitude'];
      $vars['longitude'] = $address[0]['longitude'];
    } else {

      // check for "venue" field
      $venue = field_get_items('node', $node, 'field_venue_organisation');
      if (isset($venue[0]['nid'])) {
        $venue_node = node_load($venue[0]['nid']);
        $venue_address = field_get_items('node', $venue_node, 'field_address');
        if ($venue_address) {
          $vars['show_map'] = TRUE;
          $vars['latitude'] = $venue_address[0]['latitude'];
          $vars['longitude'] = $venue_address[0]['longitude'];
        } 
      }
    }
    
  }

}

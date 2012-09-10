<?php

/**
 * Admin function for rendering stats
 */
function hc_ads_stats() {

  $table = array();
  $table['header'] = array('Title', 'Image', 'Link', 'Views', 'Clicks');
  $result = db_query("SELECT * FROM {hc_banner_stats};");
  foreach ($result as $row) {
    $nid = $row->nid;
    $views = $row->views;
    $clicks = $row->clicks;
    $node = node_load($nid);
    $title = $node->title;
    $link_field = field_get_items('node', $node, 'field_link');
    $link = l($link_field[0]['url'], "http://" . $link_field[0]['url']);
    $banner_field = field_get_items('node', $node, 'field_banner');
    $image_url = image_style_url('medium', $banner_field[0]['uri']);
    $image = "<img src='$image_url' />";
    $table['rows'][] = array(
      array('data' => $title, 'titel'),
      array('data' => $image, 'image'),
      array('data' => $link),
      array('data' => $views, 'views'),
      array('data' => $clicks, 'clicks'),
    );
  }

  $output = theme('table', $table);
  return $output;

}
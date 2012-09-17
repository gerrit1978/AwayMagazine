<?php
function hedgecomm_alpha_preprocess_views_view_fields(&$vars) {

	$view_name = $vars['view']->name;


	if ($view_name == 'agenda' || $view_name == 'events') {
		foreach ($vars['fields'] as $delta => $field) {
			if ($delta == "nothing") {
			  $row = $vars['row'];
				$nid = $row->nid;
				$node = node_load($nid);
				$date_field = field_get_items('node', $node, 'field_date');
				$date = $date_field[0]['value'];
				$dateOutput = "<span class='day'>" . date("d", strtotime($date)) . "</span>" . date("M", strtotime($date));
				$vars['fields'][$delta]->content = $dateOutput;
			}
		}
	}
	
	
	if ($view_name == 'magazine_articles') {
		foreach ($vars['fields'] as $delta => $field) {
			if ($delta == "nothing") {
			  $row = $vars['row'];
				$path = url('node/' . $row->nid, array('absolute' => TRUE));
				$output = '<iframe src="//www.facebook.com/plugins/like.php?href=' . $path . '&amp;send=false&amp;layout=button_count&amp;width=125&amp;show_faces=false&amp;action=like&amp;colorscheme=light&amp;font&amp;height=21&amp;appId=399433136789561" scrolling="no" frameborder="0" style="border:none; overflow:hidden; width:125px; height:21px;" allowTransparency="true"></iframe>';
				$vars['fields'][$delta]->content = $output;

			}
		}
	}	
	
	
}
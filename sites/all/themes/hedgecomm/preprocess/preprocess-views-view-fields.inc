<?php
function hedgecomm_alpha_preprocess_views_view_fields(&$vars) {

	$view_name = $vars['view']->name;


	if ($view_name == 'events') {
		foreach ($vars['fields'] as $delta => $field) {
			if ($delta == "nothing") {
			  $row = $vars['row'];
				$nid = $row->nid;
				$node = node_load($nid);
				$date_field = field_get_items('node', $node, 'field_date');
				$date = isset($date_field[0]['value2']) ? $date_field[0]['value2'] : $date_field[0]['value'];
				$dateOutput = "<span class='day'>" . date("d", strtotime($date)) . "</span>" . date("M", strtotime($date));
				$vars['fields'][$delta]->content = $dateOutput;
			}
		}
	}


	if ($view_name == 'agenda') {
		foreach ($vars['fields'] as $delta => $field) {
			if ($delta == "nothing") {
			  $row = $vars['row'];
				$nid = $row->nid;
				$node = node_load($nid);
				$date_field = field_get_items('node', $node, 'field_agenda_date');
				$date = isset($date_field[0]['value2']) ? $date_field[0]['value2'] : $date_field[0]['value'];
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
				// Add Facebook Button
				$output = '<div class="facebook"><iframe src="//www.facebook.com/plugins/like.php?href=' . $path . '&amp;send=false&amp;layout=button_count&amp;width=125&amp;show_faces=false&amp;action=like&amp;colorscheme=light&amp;font&amp;height=21&amp;appId=399433136789561" scrolling="no" frameborder="0" style="border:none; overflow:hidden; width:125px; height:21px;" allowTransparency="true"></iframe></div>';
				// Add Tweet Button
				$output .= '<div class="twitter"><a href="https://twitter.com/share" class="twitter-share-button" data-lang="en">Tweet</a>
          <script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="https://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script></div>';
				// Add Google+ Button
				$output .= '<div class="google"><g:plusone size="medium" annotation="inline" width="150"></g:plusone><script type="text/javascript">
          window.___gcfg = {lang: "en-GB"};  (function() { var po = document.createElement("script"); po.type = "text/javascript"; po.async = true; po.src = "https://apis.google.com/js/plusone.js"; var s = document.getElementsByTagName("script")[0]; s.parentNode.insertBefore(po, s);  })(); </script></div>';

				$vars['fields'][$delta]->content = $output;

			}
		}
	}	
	
}
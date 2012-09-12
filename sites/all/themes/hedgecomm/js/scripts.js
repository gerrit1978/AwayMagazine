jQuery(document).ready(function($) {
	$('.view-carrousel ul').carouFredSel({
		responsive: true,
	  items: {
	    visible : 1,
	    height: "45%"	    
	  },
	  scroll : {
	  	fx : 'crossfade'
	  },
	  auto : {
	    pauseDuration : 4500
	  },
	  pagination : '#pager'
	});
	
	
	// equal heights for content and sidebar 2 (non front)
	if ($("body").hasClass('not-front')) {
		var contentHeight = $('#region-content').height();
		var sidebarHeight = $('#region-sidebar-second').height();
		if (contentHeight < sidebarHeight) {
		  $('#region-content .region-inner').css('height', sidebarHeight);
		} else {
		  $('#region-sidebar-second .region-inner').css('height', contentHeight);		
		}
	}
	
});
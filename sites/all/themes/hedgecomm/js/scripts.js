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
});
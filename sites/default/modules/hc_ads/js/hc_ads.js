jQuery(document).ready(function($) {
  $('a.banner').click(function(e) {
    e.preventDefault();
    var $id = $(this).attr('data-id');
    var $href = $(this).attr('href');
    var $url = "/hc_ads/click/" + $id;
    $.ajax({
      url : $url,
      success: function() {
        window.location.href = $href;
      }
    });
  });
});
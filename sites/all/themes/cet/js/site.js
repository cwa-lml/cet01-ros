(function ($) {

  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {
      // if close button over overlay clicked, hide both
		jQuery('.modal .close, .modal-backdrop').click(function () {
			jQuery('.modal-backdrop, .modal').hide();
		});		
    }
  };

})(jQuery);
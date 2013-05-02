(function ($) {

  Drupal.behaviors.exampleModule = {
    attach: function (context, settings) {
      	
      	// homepage - add the cover image for the video on load

		if (jQuery('.front').length){
			function addVideoImage() {

				if (jQuery.browser.msie  && parseInt(jQuery.browser.version, 10) <= 8) {
					jQuery('.video-js img').attr('src','/sites/all/themes/cet/img/homepage-video.png').show().delay(300);
				} else {
					jQuery('.video-js img').attr('src','/sites/all/themes/cet/img/homepage-video.png').show();
				}
				//console.log('image added');
			}

			function autorun() {
			    if (jQuery(".video-js").is(":visible")){
			    	//console.log('video exists');
			        clearInterval(autoSlider);
			        setTimeout(addVideoImage, 600);
			        return false;
			    } 
				//console.log('video loading');
				autoSlider;
			}

			var autoSlider = setInterval(autorun,100);
    	}

      	// if close button over overlay clicked, hide both
		jQuery('.modal .close, .modal-backdrop').click(function () {
			jQuery('.modal-backdrop, .modal').hide();
		});	

		// Purchase the resource
		// Set the first name default text
		if(jQuery("#edit-purchaser-first-name").val() == "") {
			jQuery("#edit-purchaser-first-name").val("First name...");
		}
		jQuery("#edit-purchaser-first-name").focus(function(){
			if( jQuery(this).val() == "First name..." ){
				jQuery(this).val("");
			}
		});
		jQuery("#edit-purchaser-first-name").blur(function(){
			if( jQuery(this).val() == "" ){
				jQuery(this).val("First name...");
			}
		});		

		// Set the last name default text
		if(jQuery("#edit-purchaser-last-name").val() == "") {
			jQuery("#edit-purchaser-last-name").val("Last name...");
		}
		jQuery("#edit-purchaser-last-name").focus(function(){
			if( jQuery(this).val() == "Last name..." ){
				jQuery(this).val("");
			}
		});
		jQuery("#edit-purchaser-last-name").blur(function(){
			if( jQuery(this).val() == "" ){
				jQuery(this).val("Last name...");
			}
		});		

		// Clear the fields if the default text remains
		jQuery("#ros-purchase-page-form").submit(function(){
			if( jQuery("#edit-purchaser-first-name").val() == "First name..." ){
				jQuery("#edit-purchaser-first-name").val("");
			}
			if( jQuery("#edit-purchaser-last-name").val() == "Last name..." ){
				jQuery("#edit-purchaser-last-name").val("");
			}
		});

		// Interactive whiteboards
		// http://jsfiddle.net/e6Gt8/180/
		
		/* hover won't work on a whiteboard
		jQuery('span.glossary').popover({
			trigger: 'hover'
		});
		*/
		
		jQuery('span.glossary, span.focus, span.metaphor, span.simile').popover({
			trigger: 'manual'
		});


		// Trigger for the hiding of any open metaphor or simile popovers
		// Add a close button

		if(jQuery('span.glossary, span.focus, span.metaphor, span.simile').length){

			/*
			var closeBtn = 	jQuery('<button/>').attr({'type':'button', 'class':'close'})
								.text('x')
								.click(function(){
									jQuery('span.metaphor, span.simile').popover('hide');
								});
			*/

			jQuery('span.glossary, span.focus, span.metaphor, span.simile').each(function() {
				jQuery(this).on('click', function(e){
					e.stopPropagation();
					resetActive();
					var className = 'active';//-' + jQuery(this).attr('class');
					jQuery(this).addClass(className);
					// Create a relationship between popovers for situations where
					// highlighted text spans seperate paragraphs
					if (jQuery(this).attr('data-rel')){
						var dataRel = jQuery(this).attr('data-rel');
						//console.log(jQuery(this).attr('data-rel'));
						jQuery("span[data-rel='" + dataRel +"']").each(function(){
							jQuery(this).addClass(className);
						});
					}
					jQuery('.popover').hide();
					var popover = jQuery(this).data('popover');
					var shown = popover && popover.tip().hasClass('in');
		            if(!shown) {
		            	jQuery(this).popover('show');
	    				popoverClass(jQuery(this));
						//closeBtn.appendTo('.popover .popover-title');
					} else {
						jQuery('span.glossary, span.focus, span.metaphor, span.simile').popover('hide');
						resetActive();
					}	
				});
			});

			$('html').on('click.popover.data-api',function() {
    			jQuery('span.glossary, span.focus, span.metaphor, span.simile').popover('hide');
    			resetActive();
			});		
		}

		function popoverClass(item) {
			jQuery('.popover').removeClass('popover-focus').removeClass('popover-metaphor').removeClass('popover-simile').removeClass('popover-glossary');
			if( item.hasClass('metaphor')) {
				jQuery('.popover').addClass('popover-metaphor');
			} else if ( item.hasClass('focus')) {
				jQuery('.popover').addClass('popover-focus');
			} else if ( item.hasClass('simile')) {
				jQuery('.popover').addClass('popover-simile');
			} else {
				jQuery('.popover').addClass('popover-glossary');
			}
		}

		function resetActive(){
			jQuery('span.glossary, span.focus, span.metaphor, span.simile').each(function() {
				jQuery(this).removeClass('active');
			});
		}
	
    }
  };

})(jQuery);
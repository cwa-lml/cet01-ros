<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
  <script type="text/javascript" charset="utf-8">
	// Patch for issue with videojs in IE9/10 - if it is IE9 or IE10 - then fall back to flash
	if(navigator.userAgent.indexOf("Trident/5")>-1 || navigator.userAgent.indexOf("Trident/6")>-1){
	 _V_.options.techOrder = ["flash"];
	 _V_.options.flash.swf = "sites/all/libraries/video-js/video-js.swf";
	}
	</script>
  
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div class="clouds"></div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>

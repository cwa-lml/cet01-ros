<?php
/**
 * @file
 * Provide the HTML output of the Video.js video player.
 */

$attrs = '';
if (!empty($autoplay)) {
  $attrs .= ' autoplay="autoplay"';
}
if (!empty($poster)) {
  $attrs .= ' poster="'. check_plain($poster) .'"';
}

// CWA PATCH: Make preload=none for IE9 compatability
if (!empty($items)): ?>
<video id="<?php print $player_id; ?>-video" data-setup="{}" class="video-js vjs-default-skin" width="<?php print($width) ?>" height="<?php print($height) ?>" 
	controls="controls" preload="none"<?php echo $attrs; ?>>
<?php foreach ($items as $item): ?>
  <source src="<?php print(file_create_url($item['uri'])) ?>" type="<?php print check_plain($item['videotype']) ?>" />
<?php endforeach; ?>
</video>
<?php endif;

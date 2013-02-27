<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
      
  <div class="iwb-top-img"<?php if (!empty($content['field_upper_background_image'])): ?> style="background-image: url(<?php print render($content['field_upper_background_image']); ?>);"<?php endif; ?> >
   
    <div class="iwb-bd"<?php if (!empty($content['field_body_padding_top']) || !empty($content['field_body_padding_bottom']) || !empty($content['field_body_padding_left']) || !empty($content['field_background_image'])): ?> style="<?php if (!empty($content['field_body_padding_top']) ): ?>padding-top: <?php print render($content['field_body_padding_top']); ?>px;<?php endif; ?><?php if (!empty($content['field_body_padding_bottom']) ): ?>padding-bottom: <?php print render($content['field_body_padding_bottom']); ?>px;<?php endif; ?><?php if (!empty($content['field_body_padding_left']) ): ?>padding-left: <?php print render($content['field_body_padding_left']); ?>px;<?php endif; ?><?php if (!empty($content['field_background_image']) ): ?>background-image: url(<?php print render($content['field_background_image']); ?>);<?php endif; ?>"<?php endif; ?>>
      
      <?php print render($content['field_country']); ?>

      <?php if (!empty($content['field_title_width'])): ?>
        <div class="heading-container" style="width: <?php print render($content['field_title_width']); ?>px">
      <?php endif; ?> 
        <h1 class="page-header"><?php print $title; ?></h1>      
      <?php if (!empty($content['field_title_width'])): ?>
        </div>
      <?php endif; ?>
      
      <?php print render($content['field_author']); ?>

      <?php
        // Hide comments, tags, and links now so that we can render them later.
        hide($content['field_body_content_width']);
        hide($content['field_type']);
        hide($content['field_itemnumber']);
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_tags']);
        print render($content);
      ?>
    
    </div><!-- /.iwb-bd -->

  </div><!-- /.iwb-top-img -->

</article> <!-- /.node -->

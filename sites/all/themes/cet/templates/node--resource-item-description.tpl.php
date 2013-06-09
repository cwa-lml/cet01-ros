<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!empty($content['field_resource_image'])): ?> 
    <div class="resource-img">
      <?php print render($content['field_resource_image']); ?>
    </div>
  <?php endif; ?>
   
  <?php
    hide($content['field_download_module']);
    print render($content);
  ?>
  <?php if (!empty($content['field_download_module'])): ?> 
  <a href="<?php print render($content['field_download_module']); ?>" class="btn btn-sample">View sample</a>  
  <?php endif; ?>
  
</article> <!-- /.node -->

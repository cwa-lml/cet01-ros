<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if (!empty($content['field_resource_image'])): ?> 
    <div class="resource-img">
      <?php print render($content['field_resource_image']); ?>
    </div>
  <?php endif; ?>
   
  <?php
    hide($content['field_download_module']);
    //print_r($content['field_download_module']);exit;
    print render($content);
  ?>
  <?php if (isset($content['field_download_module']['#object']->field_download_module[LANGUAGE_NONE]) && count($content['field_download_module']['#object']->field_download_module[LANGUAGE_NONE]) > 0): ?> 
  <a href="<?php print render($content['field_download_module']); ?>" class="btn btn-sample">View sample</a>  
  <?php endif; ?>
  
</article> <!-- /.node -->

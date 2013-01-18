<div class="container">

  <header role="banner" class ="site-header">
    <?php if ($site_name): ?>
      <?php if ($is_front): ?>
        <h1 class="site-name">
          <?php print $site_name; ?>
          <?php if ( $site_slogan ): ?>
            <small class="lead"><?php print $site_slogan; ?></small>
          <?php endif; ?>
        </h1>
      <?php else: ?>      
        <h2 class="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Back to home page. '); ?>"><?php print $site_name; ?></a>
          <?php if ( $site_slogan ): ?>
            <small class="lead"><?php print $site_slogan; ?></small>
          <?php endif; ?>
        </h2>
      <?php endif; ?>
    <?php endif; ?>
    
    <?php print render($page['header']); ?>

    <img class="cet-logo" src="/sites/all/themes/cet/img/cet-logo.png" width="101" height="51" title="Commonwealth Education Trust" alt="Commonwealth Education Trust" />
  </header> <!-- /#header -->

  <header id="navbar" role="banner" class="navbar">
    <div class="navbar-inner">
      <div class="container">
        <?php if ($primary_nav || $secondary_nav || !empty($page['navigation'])): ?>
          <div class="nav-collapse">
            <nav role="navigation">
              <?php if ($primary_nav): ?>
                <?php print render($primary_nav); ?>
              <?php endif; ?>
              <?php if (!empty($page['navigation'])): ?>
                <?php print render($page['navigation']); ?>
              <?php endif; ?>
              <?php //if ($secondary_nav): ?>
                <?php //print render($secondary_nav); ?>
              <?php //endif; ?>
            </nav>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </header>
  <div class="row">

    <?php if ($is_front): ?>
      <section class="offset1 span7">  
    <?php else: ?>  
      <section class="span12 main-content">  
    <?php endif; ?>    
      <div class="main-inner">
        <?php if ($page['highlighted']): ?>
          <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
        <?php endif; ?>
        <?php if ($breadcrumb): print $breadcrumb; endif;?>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page-header"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print $messages; ?>
        <?php if ($tabs): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>
        <?php if ($page['help']): ?> 
          <div class="well"><?php print render($page['help']); ?></div>
        <?php endif; ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
      </div>
    </section>

    <?php if ($is_front): ?>
      <?php if ($page['frontpage_sidebar_second']): ?>
        <aside class="span3 sidebar-second" role="complementary">
          <?php print render($page['frontpage_sidebar_second']); ?>
        </aside>  <!-- /#sidebar-second -->
      <?php endif; ?>
    <?php else: ?>      
      <?php if ($page['sidebar_second']): ?>
        <aside class="span4" role="complementary">
          <?php print render($page['sidebar_second']); ?>
        </aside>  <!-- /#sidebar-second -->
      <?php endif; ?>
    <?php endif; ?>

  </div>
  <footer class="footer container">
    <?php print render($page['footer']); ?>
  </footer>
</div>

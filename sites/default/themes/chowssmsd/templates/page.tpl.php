  <div id="page-wrapper">
    <div id="page">
    <div id="header">
      <div class="section clearfix">

        <div id="logo-wrap">
    	    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"></a>
        </div>
        <?php print render($page['header']); ?>
      </div>
    </div> <!-- /.section, /#header -->

    <?php print $messages; ?>

    <?php print render($page['highlighted']) ?>

    <div id="main-wrapper">
      <div id="main" class="clearfix">
    	  <?php if (isset($page['sidebar_left']) && $page['sidebar_left']): ?>
    	    <div id="sidebar-left" class="column sidebar">
            <div class="section">
    	      <?php print render($page['sidebar_left']); ?>
    	      </div>
          </div> <!-- /.section, /#sidebar-left -->
        <?php endif; ?>

        <div id="content" class="column">
          <div class="section">
          <?php print render($page['content']); ?>
          </div>
        </div> <!-- /.section, /#content -->
        <?php if (isset($page['sidebar_right']) && $page['sidebar_right']): ?>
  		    <?php print render($page['sidebar_right']); ?> <!-- /.section, /#sidebar-right -->
        <?php endif; ?>
      </div>
    </div> <!-- /#main, /#main-wrapper -->

    <div id="footer">
      <div class="section">
      <?php print render($page['footer']); ?>
      </div>
    </div> <!-- /.section, /#footer -->

  </div>
</div> <!-- /#page, /#page-wrapper -->

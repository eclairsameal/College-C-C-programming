
  <link rel="stylesheet" href="css/jquery-ui.css">
  <script src="js/jquery-1.9.1.js"></script>
  <script src="js/jquery-ui.js"></script>
  <script>
  $(function() {
    $( "#tabs" ).tabs({
      event: "mousedown"
    });
  });
 </script>

  <?php
    if ($_SESSION['GML']=='G') {
      include 'G_userContent.php';
    }
    else if ($_SESSION['GML']=='M') {
      include 'M_userContent.php';
    }
    else{
      include 'L_userContent.php';
    }
    

  ?>

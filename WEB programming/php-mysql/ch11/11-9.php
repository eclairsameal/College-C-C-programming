<html>
<title>SWITCH</title>
<body>
<?php
  For ($A=1; $A<=5; $A++){
    echo "\$A = $A <br>" ;
    switch ($A) {
      case 1 :
          echo "Hello  " ;
          break;
      case 2 :
          echo "My friend." ;
          break ;
      case 3:
          echo "PHP is a good solution." ;
          break ;
      default :
          echo "Error! You got a invalid number" ;
    }
    echo "<hr width=300 align=left><p>" ;
  }
?>
</body>
 </html>
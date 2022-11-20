<html>
<title>SWITCH</title>
<body>
<?php
 $A=2;
 echo "\$A = $A <br>" ;
 switch ($A) {
    case 1 :
         echo "A=1" ;
          break;
    case 2 :
          echo "A=2" ;
          break ;
    case 3:
          echo "A=3" ;
          break ;
    default :
          echo "A不是介於1到3之間" ;
 }
?>
</body>
</html>
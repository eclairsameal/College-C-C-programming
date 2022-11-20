<html>
<title>位元運算子</title>
<body>
<?php
  $A = 12 ;           //12=00001100
  $B = 9 ;            //9=00001001
  $C = 3 ;            //2=00000010
  echo "\$A = $A <br> \$B = $B <br> \$C = $C " ;
  echo "<P>\$A & \$B = " ;
  echo $A & $B ;      // 00001100 and 00001001 
  echo "<P>\$A | \$B = " ;
  echo $A | $B ;      // 00001100 or 00001001
  echo "<P>\$A << \$C = " ;
  echo $A << $C ;     // 00001100 向左移2位元
?>
</body>
</html>
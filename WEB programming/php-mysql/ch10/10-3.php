<html>
<title>assign by address</title>
<body>
<?php
  $A = 10 ;
  $B = $A ;        //$A和$B為二個實體
  $C = &$A ;       //$A和$C指向同一個實體
  echo "計算前 ：<br>" ;
  echo "\$A = $A <br> \$B = $B <br> \$C = $C <p>" ;
  $B += 10 ;
  echo "計算\$B + 10 後 ：<br>" ;
  echo "\$A = $A <br> \$B = $B <br> \$C = $C <p>" ;
  $C += 5 ;
  echo "計算\$C + 5 後 ：<br>" ;
  echo "\$A = $A <br> \$B = $B <br> \$C = $C <p>" ;
?>
</body>
</html>
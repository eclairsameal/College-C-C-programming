<html>
<title>assign by address</title>
<body>
<?php
  $A = 10 ;
  $B = $A ;        //$A�M$B���G�ӹ���
  $C = &$A ;       //$A�M$C���V�P�@�ӹ���
  echo "�p��e �G<br>" ;
  echo "\$A = $A <br> \$B = $B <br> \$C = $C <p>" ;
  $B += 10 ;
  echo "�p��\$B + 10 �� �G<br>" ;
  echo "\$A = $A <br> \$B = $B <br> \$C = $C <p>" ;
  $C += 5 ;
  echo "�p��\$C + 5 �� �G<br>" ;
  echo "\$A = $A <br> \$B = $B <br> \$C = $C <p>" ;
?>
</body>
</html>
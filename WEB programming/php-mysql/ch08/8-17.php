<html>
<title>資料型態的轉換</title>
<body>
<?php
   $A=12.345 ;
   $B=(int)$A ;
   $C=(double)123 ;
   $D="100" ;
   $E=(int)$D ;
   echo "\$A = $A Type is ".gettype($A)."<br>" ;
   echo "\$B = $B Type is ".gettype($B)."<br>" ;
   echo "\$C = $C Type is ".gettype($C)."<br>" ;
   echo "\$D = $D Type is ".gettype($D)."<br>" ;
   echo "\$E = $E Type is ".gettype($E)."<br>" ;
?>
</body>
</html>
<html>
<title>遞增減運算</title>
<body>
<?php
   $A = 10 ;
   $B = 5 ;
   echo " \$A = " . $A ."<br>" ;
   echo " ++\$A = " . ++$A ." 先加再顯示<br>" ;
   echo " \$A = " . $A ."<hr align=left width=200>";
   echo " \$A = " . $A ."<br>";
   echo " \$A++ = " . $A++ ." 先顯示再加<br>";
   echo " \$A = " . $A ."<hr align=left width=200>";
   echo " \$A = " . $A ."<br>";
   echo " --\$A = " . --$A ." 先減再顯示<br>";
   echo " \$A = " . $A ."<hr align=left width=200>";
   echo " \$A = " . $A ."<br>";
   echo "\$A-- = " . $A-- ." 先顯示再減<br>";
   echo " \$A = " . $A ."<hr align=left width=200>";
   echo "\$A = $A , \$B = $B <br>";
   $C=$A-($B++) ;
   echo "\$A-(\$B++) = " . $C ."<hr align=left width=200>";
   echo "\$A = $A , \$B= $B  <br>";
   $C=$A-(++$B) ;
   echo "\$A-(++\$B) = " . $C ."<br>";
?>
</body>
</html>
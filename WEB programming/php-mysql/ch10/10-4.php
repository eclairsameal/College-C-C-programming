<html>
<title>���W��B��</title>
<body>
<?php
   $A = 10 ;
   $B = 5 ;
   echo " \$A = " . $A ."<br>" ;
   echo " ++\$A = " . ++$A ." ���[�A���<br>" ;
   echo " \$A = " . $A ."<hr align=left width=200>";
   echo " \$A = " . $A ."<br>";
   echo " \$A++ = " . $A++ ." ����ܦA�[<br>";
   echo " \$A = " . $A ."<hr align=left width=200>";
   echo " \$A = " . $A ."<br>";
   echo " --\$A = " . --$A ." ����A���<br>";
   echo " \$A = " . $A ."<hr align=left width=200>";
   echo " \$A = " . $A ."<br>";
   echo "\$A-- = " . $A-- ." ����ܦA��<br>";
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
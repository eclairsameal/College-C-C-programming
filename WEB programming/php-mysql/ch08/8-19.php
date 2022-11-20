<html>
<title>資料型態的轉換</title>
<body>
<?php
    $A=12.345 ;
    settype($A,integer) ;
    $B=100 ;
    settype($B,string) ;
    $B=$B."abc";
    echo "\$A = $A Type is ".gettype($A)."<br>" ;
    echo "\$B = $B Type is ".gettype($B)."<br>" ;
?>
</body>
</html>
<html>
<title>Break</title>
<body>
<?php
echo "======= break ======= <br>\n" ;
for ($A=1; $A<=3; $A++) {                  //第一層迴圈
    for ($B=1; $B<=10 ; $B++) {             //第二層迴圈
       echo "A = $A   B=$B <br>\n" ;
       if ($B==3) break ;
    } 
    echo "--------------- <br>" ;
}
echo "<p>";
echo "====== break 2 ====== <br>\n" ;
for ($A=1; $A<=3; $A++) {                  //第一層迴圈
    for ($B=1; $B<=10 ; $B++) {             //第二層迴圈
       echo "A = $A   B=$B <br>\n" ;
       if ($B==3) break 2 ;
    }  
}
?>
</body>
</html>


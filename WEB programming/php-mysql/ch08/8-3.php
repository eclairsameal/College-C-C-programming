<html>
<title>變數值設定</title>
<body>
<?php
$A = 10 ;                    // $A的值為10
$B = $A ;         		    // $A的值複製給$B
$C = &$A ;                   // $A的記憶體位置給$C
echo "執行計算前 <br>";
echo "A=$A <br>" ;
echo "B=$B <br>";
echo "C=$C <p>";
$B=$B+10 ;                   // $B的值加10
$C=$C+20 ;                   // $C的值加20
echo "執行計算後:<br>" ;
echo "A=$A <br>";  // 顯示$A，$B，$C的值
echo "B=$B <br>" ;
echo "C=$C ";
?>
</body>
</html>

<html>
<title>�ܼƭȳ]�w</title>
<body>
<?php
$A = 10 ;                    // $A���Ȭ�10
$B = $A ;         		    // $A���Ƚƻs��$B
$C = &$A ;                   // $A���O�����m��$C
echo "����p��e <br>";
echo "A=$A <br>" ;
echo "B=$B <br>";
echo "C=$C <p>";
$B=$B+10 ;                   // $B���ȥ[10
$C=$C+20 ;                   // $C���ȥ[20
echo "����p���:<br>" ;
echo "A=$A <br>";  // ���$A�A$B�A$C����
echo "B=$B <br>" ;
echo "C=$C ";
?>
</body>
</html>

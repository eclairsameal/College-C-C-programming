<html>
<title>�� �G ��</title>
<body>
<b>�� �G ��</b> <p>
<?php
$fp=fopen("board.txt","r");
$i=0 ;
echo "<table width=200 border=0><caption>���i���e</caption>";
while (!feof($fp)){
  $str=fgets($fp) ;
  $i++;
  $i%2==0 ? $color="ffffc2" : $color="d2ffff";
  echo "<tr bgcolor=$color><td width=20>$i</td><td>$str</td></tr>" ;
}
echo "</table><p>";
echo "�@ $i �����i�ƶ�";
fclose($fp) ;
?>
</body>
</html>

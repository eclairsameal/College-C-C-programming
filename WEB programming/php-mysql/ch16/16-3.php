<html>
<title>公 佈 欄</title>
<body>
<b>公 佈 欄</b> <p>
<?php
$fp=fopen("board.txt","r");
$i=0 ;
echo "<table width=200 border=0><caption>公告內容</caption>";
while (!feof($fp)){
  $str=fgets($fp) ;
  $i++;
  $i%2==0 ? $color="ffffc2" : $color="d2ffff";
  echo "<tr bgcolor=$color><td width=20>$i</td><td>$str</td></tr>" ;
}
echo "</table><p>";
echo "共 $i 筆公告事項";
fclose($fp) ;
?>
</body>
</html>

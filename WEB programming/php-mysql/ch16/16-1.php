<html>
<title>寫入檔案</title>
<body>
寫入1..9 。<p>
<?php
if (!$fp=fopen("number.txt","w")){
       echo "檔案無法開啟";
       exit;
}
for ($i=1; $i<=9; $i++){
	$len=fputs($fp,$i) ;
	echo "寫入$i ==> 寫入長度 : $len<br>" ;
}
fclose($fp) ;
?>
寫入成功。
</body>
</html>

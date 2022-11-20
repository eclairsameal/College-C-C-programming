<html>
<title>讀取檔案</title>
<body>
讀取檔案 <p>
<?php
$f=fopen("number.txt","r") ;
$s=fgets($f) ;
echo "讀取內容 : $s <p>" ;
fclose($f) ;
?>
讀取完畢
</body>
</html>

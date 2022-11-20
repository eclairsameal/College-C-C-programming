<?php
if (file_exists("count.txt")){
	$ff=fopen("count.txt","r") ;
	$c=fgets($ff) ;
	$c++;
	fclose($ff) ;
}else{
	$c=1 ;
}
$ff=fopen("count.txt","w");
fputs($ff,$c) ;
fclose($ff) ;		
?>
<html>
<title>文字版計數器</title>
<body>
<center>
歡迎您光臨本站，您是第 <?php echo $c ; ?> 位訪客
</center>
</body>
</html>

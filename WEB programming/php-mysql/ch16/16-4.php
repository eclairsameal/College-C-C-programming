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
<title>��r���p�ƾ�</title>
<body>
<center>
�w��z���{�����A�z�O�� <?php echo $c ; ?> ��X��
</center>
</body>
</html>

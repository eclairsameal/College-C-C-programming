<html>
<title>�g�J�ɮ�</title>
<body>
�g�J1..9 �C<p>
<?php
if (!$fp=fopen("number.txt","w")){
       echo "�ɮ׵L�k�}��";
       exit;
}
for ($i=1; $i<=9; $i++){
	$len=fputs($fp,$i) ;
	echo "�g�J$i ==> �g�J���� : $len<br>" ;
}
fclose($fp) ;
?>
�g�J���\�C
</body>
</html>

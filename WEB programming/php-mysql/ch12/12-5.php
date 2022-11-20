<html>
<title>統計表</title>
<body>
<?php
	$s = array (0,15,10,20,17,3,8) ;
	echo "銷售量統計表<p>" ;
	for ($A=1 ; $A<=6; $A++){
	     echo "星期 $A : " ;
	     $s[0]+=$s[$A] ;
	     for ($I=1 ; $I<= $s[$A]; $I++)
 	     	   echo "*" ;
	     echo " $s[$A]<br>" ;
	}
	echo "<p>總量 : $s[0]" ;
?>
</body>
</html>

<html>
<title>�έp��</title>
<body>
<?php
	$s = array (0,15,10,20,17,3,8) ;
	echo "�P��q�έp��<p>" ;
	for ($A=1 ; $A<=6; $A++){
	     echo "�P�� $A : " ;
	     $s[0]+=$s[$A] ;
	     for ($I=1 ; $I<= $s[$A]; $I++)
 	     	   echo "*" ;
	     echo " $s[$A]<br>" ;
	}
	echo "<p>�`�q : $s[0]" ;
?>
</body>
</html>

<?php
	Function MyFunction() {
		$GLOBALS["C"]=$GLOBALS["A"]+$GLOBALS["B"] ;
	}
?>
<html>
<title>GLOBALS°}¦C</title>
<body>
<?php
	$A=1 ;
	$B=2 ;
	$C=0 ;
	MyFunction() ;
	echo "\$A=$A , \$B=$B , \$C=$C" ;
?>
</body>
</html>

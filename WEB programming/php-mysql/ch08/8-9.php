<?php
	Function MyFunction() {
		$GLOBALS["A"]=$B+10 ;
	}
?>
<html>
<title>GLOBALS°}¦C</title>
<body>
<?php
	$A=1 ;
	$B=2 ;
	MyFunction() ;
	echo "\$A=$A , \$B=$B"
?>
</body>
</html>
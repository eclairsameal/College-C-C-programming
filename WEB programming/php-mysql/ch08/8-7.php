<?php
        Function SUM(){
		global $A,$B,$C ;
		$C = $A+$B ;
		echo "在 SUM() 中 \$C = $C <p>" ;
	}
	Function AVG() {
		global $C ;
		$C = $C/2 ;
		echo "在 AVG() 中 \$C = $C";
	}
?>
<html>
<title>全域變數</title>
<body>
<?php
	$A=1 ;
	$B=2 ;
	$C=0 ;
	SUM() ;
	AVG() ;
?>
</body>
</html>



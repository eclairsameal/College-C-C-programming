<?php
        Function SUM(){
		global $A,$B,$C ;
		$C = $A+$B ;
		echo "�b SUM() �� \$C = $C <p>" ;
	}
	Function AVG() {
		global $C ;
		$C = $C/2 ;
		echo "�b AVG() �� \$C = $C";
	}
?>
<html>
<title>�����ܼ�</title>
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



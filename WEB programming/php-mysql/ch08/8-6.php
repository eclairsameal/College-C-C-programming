<?php
	Function MyFunction() {
		global $A,$B ;
		$A=$A+10;
                $B=$B+10;
	}
?>
<html>
<title>�����ܼ�</title>
<body>
<?php
	$A=1 ;
	$B=2 ;
	echo "�I�s��ƫe :<br>" ;
	echo "A = $A <br>" ;
	echo "B = $B <hr width=200 align=left>" ;
	MyFunction() ;
	echo "�I�s��ƫ� :<br>" ;
	echo "A = $A <br>" ;
	echo "B = $B <p>" ;
?>
</body>
</html>


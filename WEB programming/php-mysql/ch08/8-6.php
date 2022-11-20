<?php
	Function MyFunction() {
		global $A,$B ;
		$A=$A+10;
                $B=$B+10;
	}
?>
<html>
<title>办跑计</title>
<body>
<?php
	$A=1 ;
	$B=2 ;
	echo "㊣ㄧ计玡 :<br>" ;
	echo "A = $A <br>" ;
	echo "B = $B <hr width=200 align=left>" ;
	MyFunction() ;
	echo "㊣ㄧ计 :<br>" ;
	echo "A = $A <br>" ;
	echo "B = $B <p>" ;
?>
</body>
</html>


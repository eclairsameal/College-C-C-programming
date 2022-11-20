<?php
       Function addone() {
		$I=0 ;
		$I=$I+1 ;
		echo "\$I = $I<br>" ;
        }
?>
<html>
<title>區段變數生命週期</title>
<body>
<?php 
	addone() ;
	addone() ;
	addone() ;
?>
</body>
</html>

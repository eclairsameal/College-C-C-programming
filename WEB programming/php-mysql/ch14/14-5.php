<?php
	Function Pay($Price, $Amount, &$Total) {
      		echo "=========== in Function Pay ========== <br>" ;
      		echo "Price : $Price <br> Amount : $Amount <br>\n";
      		$Total=$Price * $Amount ;
      		echo "Total in Function Pay : $Total  <p>\n" ;
	}
?>
<html>
<title>¶Ç§}©I¥s</title>
<body>
<?php
	$Price=90 ;
	$Amount=100 ;
 	$Total=0 ;
	Pay($Price, $Amount, $Total) ;
	echo "============== in Main ==============<br>" ;
	echo "Price : $Price <br> Amount : $Amount <br>\n";
	echo "Total in main       : $Total<br>" ;
?>
</body>
</html>
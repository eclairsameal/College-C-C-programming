<?php
     Function Pay($price, $amount, $total) {
      	echo "Price : $price   Amount : $amount <br>\n";
	$total=$price * $amount ;
	echo "Total in Function Pay : $total  <br>\n" ;
	echo "<p>\n" ;
     }
?>
<html>
<title>��ܶǻ��覡</title>
<body>
<?php
	$Price=90 ;
 	$Amount=100 ;
	$Total=0 ;
	Pay($Price, $Amount, $Total) ;
	echo "Total in main : $Total  <== �ǭȩI�s<hr><p>\n" ;
	Pay($Price, $Amount, &$Total) ;
	echo "Total in main : $Total  <== �ǧ}�I�s<hr>" ;
?>
</body>
</html>
<?php
     Function Pay($price, $amount, $total) {
      	echo "Price : $price   Amount : $amount <br>\n";
	$total=$price * $amount ;
	echo "Total in Function Pay : $total  <br>\n" ;
	echo "<p>\n" ;
     }
?>
<html>
<title>選擇傳遞方式</title>
<body>
<?php
	$Price=90 ;
 	$Amount=100 ;
	$Total=0 ;
	Pay($Price, $Amount, $Total) ;
	echo "Total in main : $Total  <== 傳值呼叫<hr><p>\n" ;
	Pay($Price, $Amount, &$Total) ;
	echo "Total in main : $Total  <== 傳址呼叫<hr>" ;
?>
</body>
</html>
<?php
	function Pay($price, $amount, $discount=0.8) {
		echo "基 : $price じ<br>" ;
		echo "计秖 : $amount <br>" ;
		$showcnt=$discount*10 ;
		echo "чΙ : $showcnt ч<br> " ;
		return $price*$amount*$discount ;
	}
?>
<html>
<title>箇砞把计</title>
<body>
<?php
	$Price=100 ;
	$Amount=8 ;
	echo "疭чΙ<br>" ;
	$Discount=0.5 ;
	$cost=Pay($Price, $Amount, $Discount) ;  //肚$Discount把计
	echo "羆基 : $cost じ<p>\n" ;
	echo "чΙ<br>" ;
	$cost=Pay($Price, $Amount) ;    //ゼ肚$Discount, 箇砞盿
	echo "羆基 : $cost じ" ;
?>
</body>
</html>
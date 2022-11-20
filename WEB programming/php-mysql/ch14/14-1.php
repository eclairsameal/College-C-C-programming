<?php
  Function Pay($price,$amount) {
    echo "基 : $price   <br> 计秖 : $amount <br>\n";
    echo "肂: ".$price * $amount."<p>" ;
  }
?>
<html>
<title>﹚ㄧ计</title>
<body>
<?php
	$Price=90 ;
	$Amount=100 ;
 	Pay($Price, $Amount) ;     //材Ω㊣ㄧ计
	$Price=60 ;
	$Amount=50 ;
	Pay($Price, $Amount) ;      //材Ω㊣ㄧ计
?>
</body>
</html>
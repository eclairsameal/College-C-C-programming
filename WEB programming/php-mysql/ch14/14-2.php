<?php
   Function Pay($price,$amount) {
     echo "基 : $price   <br> 计秖 : $amount <br>\n";
     $S=$price * $amount ;
     return $S ;
   }
?>
<html>
<title>﹚ㄧ计</title>
<body>
<?php
 	$Price=90 ;
 	$Amount=100 ;
 	$total1= Pay($Price, $Amount) ;     //材Ω㊣ㄧ计
 	echo "肂 : $total1 <p>" ;
 	$Price=60 ;
 	$Amount=50 ;
 	$total2 = Pay($Price, $Amount) ;      //材Ω㊣ㄧ计
 	echo "肂 : $total2<p>" ;
        $total2+=$total1;
        echo "羆肂 : $total2" ;
?>
</body>
</html>
<?php
   Function Pay($price,$amount) {
     echo "���� : $price   <br> �ƶq : $amount <br>\n";
     $S=$price * $amount ;
     return $S ;
   }
?>
<html>
<title>�۩w���</title>
<body>
<?php
 	$Price=90 ;
 	$Amount=100 ;
 	$total1= Pay($Price, $Amount) ;     //�Ĥ@���I�s���
 	echo "���B : $total1 <p>" ;
 	$Price=60 ;
 	$Amount=50 ;
 	$total2 = Pay($Price, $Amount) ;      //�ĤG���I�s���
 	echo "���B : $total2<p>" ;
        $total2+=$total1;
        echo "�`���B : $total2" ;
?>
</body>
</html>
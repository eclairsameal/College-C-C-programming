<?php
  Function Pay($price,$amount) {
    echo "���� : $price   <br> �ƶq : $amount <br>\n";
    echo "���B: ".$price * $amount."<p>" ;
  }
?>
<html>
<title>�۩w���</title>
<body>
<?php
	$Price=90 ;
	$Amount=100 ;
 	Pay($Price, $Amount) ;     //�Ĥ@���I�s���
	$Price=60 ;
	$Amount=50 ;
	Pay($Price, $Amount) ;      //�ĤG���I�s���
?>
</body>
</html>
<?php
	function Pay($price, $amount, $discount=0.8) {
		echo "���� : $price ��<br>" ;
		echo "�ƶq : $amount ��<br>" ;
		$showcnt=$discount*10 ;
		echo "�馩 : $showcnt ��<br> " ;
		return $price*$amount*$discount ;
	}
?>
<html>
<title>�w�]�Ѽ�</title>
<body>
<?php
	$Price=100 ;
	$Amount=8 ;
	echo "�S�O�馩�G<br>" ;
	$Discount=0.5 ;
	$cost=Pay($Price, $Amount, $Discount) ;  //�ǤJ$Discount�Ѽ�
	echo "�`�� : $cost ��<p>\n" ;
	echo "�@��馩�G<br>" ;
	$cost=Pay($Price, $Amount) ;    //���ǤJ$Discount, �H�w�]�ȱa�J
	echo "�`�� : $cost ��" ;
?>
</body>
</html>
<html>
<title>判斷敘述</title>
<body>
<?php
        $Chinese = 90 ;
	$English = 80 ;
	echo "國文成績是 $Chinese 分<br>" ;
	echo "英文成績是 $English 分<br>" ;
        $Avg=($Chinese + $English)/2 ;
        echo "平均 = $Avg 分 ";
	if ($Avg >=60) {
	   echo " 成績及格" ;
	} else {
	   echo " 成績不及格" ;
	}
?>
</body>
</html>
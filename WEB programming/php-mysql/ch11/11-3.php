<html>
<title>判斷敘述</title>
<body>
<?php
    $order = 50000 ;
    echo "您訂購的金額是 $order <br>";
    if ($order >=10000) {
        $order=$order*0.8 ;
        echo "您折扣後的金額是 $order <br>";
        if ($order >=20000){   
            echo "本公司免費提供送貨服務" ;
        }
    }
?>
</body>
</html>
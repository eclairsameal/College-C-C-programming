<html>
<title>�P�_�ԭz</title>
<body>
<?php
    $order = 50000 ;
    echo "�z�q�ʪ����B�O $order <br>";
    if ($order >=10000) {
        $order=$order*0.8 ;
        echo "�z�馩�᪺���B�O $order <br>";
        if ($order >=20000){   
            echo "�����q�K�O���Ѱe�f�A��" ;
        }
    }
?>
</body>
</html>
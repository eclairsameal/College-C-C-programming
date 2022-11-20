<html>
<title>取得外部變數</title>
<body>
<?php
    echo $_GET['company'] ."您好: <p>" ;
    echo "感謝貴公司訂購本公司產品". $_GET['amount'] ."個," ;
    echo "貨款共".($_GET['amount']*100)."元整.<p>" ;
    echo "貨品將於三日內送達".$_GET['address']."<p>" ;
    echo "再次感謝您的愛護.<p>" ;
    echo "凱文瑞克公司 敬上" ;
?>
</body>
</html>
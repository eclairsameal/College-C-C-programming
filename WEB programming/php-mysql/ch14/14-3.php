<?php
    function message() {
         echo "函數回傳三個數值.<p>";
         return array("Hello", "My", "friend");
    }
?>
<html>
<title>多個回傳值</title>
<body>
<?php
    list($msg1, $msg2, $msg3)=message();
    echo "主程式接收多個訊息如下<br>";
    echo "$msg1 $msg2 $msg3";
?>
</body>
</html>
<html>
<title>判斷敘述</title>
<body>
<?php
    if (preg_match("/MSIE/",$_SERVER["HTTP_USER_AGENT"])){
	echo "你的瀏覽器是 IE" ;
    }else{
        echo "你的瀏覽器不是 IE" ;
    }
?>
</body>
</html>
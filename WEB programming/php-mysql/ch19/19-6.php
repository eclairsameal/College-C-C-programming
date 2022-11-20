<?php
  if (empty($_SERVER['PHP_AUTH_USER'])) {
    header("Content-type: text/html; charset=big5");
    header('WWW-Authenticate: Basic realm=" Authentication "');
    header('HTTP/1.0 401 Unauthorized');
    echo '請輸入正確的帳號及密碼, 不可以取消!';
    exit;
  } else {
    echo "您登入的帳號是 ".$_SERVER['PHP_AUTH_USER']."<br>";
    echo "您使用的密碼是 ".$_SERVER['PHP_AUTH_PW']."<p>";
    $correctName="john";
    $correctpwd="1234" ;
     if (($_SERVER['PHP_AUTH_USER'] != $correctName) or 
            ($_SERVER['PHP_AUTH_PW'] !=$correctpwd)){
        echo "登入失敗, 請開啟新的瀏覽器重新登入";
     }else{
     echo "登入成功.....";
     }
  }
?>

<?php
  if (empty($_SERVER['PHP_AUTH_USER'])) {
    header("Content-type: text/html; charset=big5");
    header('WWW-Authenticate: Basic realm=" Authentication "');
    header('HTTP/1.0 401 Unauthorized');
    echo '�п�J���T���b���αK�X, ���i�H����!';
    exit;
  } else {
    echo "�z�n�J���b���O ".$_SERVER['PHP_AUTH_USER']."<br>";
    echo "�z�ϥΪ��K�X�O ".$_SERVER['PHP_AUTH_PW']."<p>";
    $correctName="john";
    $correctpwd="1234" ;
     if (($_SERVER['PHP_AUTH_USER'] != $correctName) or 
            ($_SERVER['PHP_AUTH_PW'] !=$correctpwd)){
        echo "�n�J����, �ж}�ҷs���s�������s�n�J";
     }else{
     echo "�n�J���\.....";
     }
  }
?>

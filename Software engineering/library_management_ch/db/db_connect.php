<?php
//資料庫設定
//資料庫位置
$db_server = "localhost";
//資料庫名稱
$db_name = "library_management";
//資料庫管理者帳號
$db_user = "root";
//資料庫管理者密碼
$db_passwd = "ail12345";

/*
//對資料庫連線
if(!@mysqli_connect($db_server, $db_user, $db_passwd))
        die("無法對資料庫連線");

//選擇資料庫
if(!@mysqli_select_db($db_name))
        die("無法使用資料庫");*/
$conn = new mysqli($db_server, $db_user, $db_passwd, $db_name);

if ($conn->connect_error) {
    die('資料庫連線錯誤：' . $conn->connect_error);
}  
?>
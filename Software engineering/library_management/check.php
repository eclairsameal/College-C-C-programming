<?php session_start(); ?>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php
//連接資料庫
//只要此頁面上有用到連接MySQL就要include它
include("db/db_connect.php");

$id = $_POST['id'];
$pw = $_POST['pw'];
//搜尋資料庫資料
$sql = "SELECT user_id,pw,user_name,GML FROM user where user_id = '".$id."'";
$result = mysql_query($sql);
$row = mysql_fetch_row($result);
//判斷帳號與密碼是否為空白
//以及MySQL資料庫裡是否有這個會員
if($id != null && $pw != null && $row[0] == $id && $row[1] == $pw)
{
	//將帳號寫入session，方便驗證使用者身份
	$_SESSION['user_id'] = $id;
	$_SESSION['GML'] = $row[3];
	$url = "main.php";
	echo "<script type='text/javascript'>";
	echo "window.location.href='$url'";
	echo "</script>";
}
else
{
	echo"<script type='text/javascript'>alert('登入失敗！');</script>";
  	$url = "index.php";
	echo "<script type='text/javascript'>";
	echo "window.location.href='$url'";
	echo "</script>"; 
}

?>

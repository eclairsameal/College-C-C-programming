<meta http-equiv="Content-Type" content="text/html; charset=utf8">
<?php
	if(!isset($_SESSION)){
		session_start();
	}
	include("db/connect_check.php");
	include("db/db_connect.php");
	include("class.php");
?>
<?php
	$id=$_SESSION['user_id'];
	$sql = "SELECT * FROM user where user_id = '".$id."'";
	$result = mysql_query($sql);
	$row = mysql_fetch_row($result);
	$dbmer = new DBMer($row[0],$row[1],$row[2],$row[3]);
?>
<?php
	$user_id=$_POST['user_id'];
	$user_name=$_POST['user_name'];
	$GML=$_POST['GML'];
	$pw=$_POST['pw'];
	$sql=$dbmer->modifyUser($user_id,$user_name,$GML,$pw);
	$result = mysql_query($sql) or die('MySQL query error');
	$url = "main.php";
	echo "<script type='text/javascript'>";
	echo "window.location.href='$url'";
	echo "</script>";
?>
<html xmlns = "http://www.w3.org/1999/xhtml" >
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
	$result = mysqli_query($conn,$sql);
	$row = mysql_fetch_row($result);
	$dbmer = new DBMer($row[0],$row[1],$row[2],$row[3]);
?>
<?php
	$book_id=$_POST['book_id'];
	$book_name=$_POST['book_name'];
	$publishing_house=$_POST['publishing_house'];
	$author=$_POST['author'];
	$date=$_POST['date'];
	$sql=$dbmer->modifyBook($book_id,$book_name,$publishing_house,$author,$date);
	$result = mysqli_query($conn,$sql) or die('MySQL query error');
	$url = "main.php";
	echo "<script type='text/javascript'>";
	echo "window.location.href='$url'";
	echo "</script>";
?>
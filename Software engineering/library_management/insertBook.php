<meta http-equiv="Content-Type" content="text/html; charset=utf8"><?php
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
	$book_id=$_POST['book_id'];
	$book_name=$_POST['book_name'];
	$publishing_house=$_POST['publishing_house'];
	$author=$_POST['author'];
	$date=$_POST['date'];
	$sql="SELECT count(book_id) FROM book WHERE book_id='$book_id'";
	$result = mysql_query($sql) or die('MySQL query error');
	$row = mysql_fetch_array($result);
	if($row[0]==0){
		$sql=$dbmer->addBook($book_id,$book_name,$publishing_house,$author,$date);
		$result = mysql_query($sql) or die('MySQL query error');
		$url = "main.php";
		echo "<script type='text/javascript'>";
		echo "window.location.href='$url'";
		echo "</script>";
	}
	else{
			$url = "main.php";
			echo "<script type='text/javascript'>";
			echo"alert('重複書籍ID!');";
			echo "window.location.href='$url'";
			echo "</script>";
	}


?>
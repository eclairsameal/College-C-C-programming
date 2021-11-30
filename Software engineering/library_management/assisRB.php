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
	$librarian = new Librarian($row[0],$row[1],$row[2],$row[3]);
?>
<?php
	$book_id=$_POST['book_id'];
	$sql=$librarian->checkBook($book_id);
	$result = mysql_query($sql);
	$row = mysql_fetch_row($result);
	if($row[0]==0){
		$url = "main.php";
		echo "<script type='text/javascript'>";
		echo"alert('書籍不存在!');";
		echo "window.location.href='$url'";
		echo "</script>";
	}
	else{
		$sql=$librarian->checkBookState($book_id);
		$result = mysql_query($sql);
		$row = mysql_fetch_row($result);
		if($row[0]==0){
			$url = "main.php";
			echo "<script type='text/javascript'>";
			echo"alert('此書尚未被借閱!');";
			echo "window.location.href='$url'";
			echo "</script>";
		}
		else{
			$sql=$librarian->returnBook($book_id);
			$result = mysql_query($sql);
			$sql=$librarian->changeBookStato0($book_id);
			$result = mysql_query($sql);
			$url = "main.php";
			echo "<script type='text/javascript'>";
			echo"alert('歸還成功!');";
			echo "window.location.href='$url'";
			echo "</script>";
		}
	}
?>
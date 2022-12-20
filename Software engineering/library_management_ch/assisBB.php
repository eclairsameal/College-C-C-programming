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
	$librarian = new Librarian($row[0],$row[1],$row[2],$row[3]);
?>
<?php
	$user_id=$_POST['user_id'];
	$book_id=$_POST['book_id'];
	$sql=$librarian->checkUser($user_id);
	$result = mysqli_query($conn,$sql);
	$row = mysql_fetch_row($result);
	if($row[0]==0){
		$url = "main.php";
		echo "<script type='text/javascript'>";
		echo"alert('使用者不存在!');";
		echo "window.location.href='$url'";
		echo "</script>";
	}
	else{
		$sql=$librarian->checkBook($book_id);
		$result = mysqli_query($conn,$sql);
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
			$result = mysqli_query($conn,$sql);
			$row = mysql_fetch_row($result);
			if($row[0]==1){
				$url = "main.php";
				echo "<script type='text/javascript'>";
				echo"alert('此書已被借閱!');";
				echo "window.location.href='$url'";
				echo "</script>";
			}
			else{
				$date = date_create(date("Y-m-d"));
				date_add($date, date_interval_create_from_date_string('30 days'));
				$sql=$librarian->assisBorrow($user_id,$book_id,date("Y-m-d"),date_format($date, 'Y-m-d'));
				$result = mysqli_query($conn,$sql);
				$sql=$librarian->changeBookStato1($book_id);
				$result = mysqli_query($conn,$sql);
				$url = "main.php";
				echo "<script type='text/javascript'>";
				echo"alert('成功借閱!');";
				echo "window.location.href='$url'";
				echo "</script>";
			}
		}
	}
?>
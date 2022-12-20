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
<html xmlns = "http://www.w3.org/1999/xhtml" > 
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf8">
		<title>中華大學::圖書館管理系統</title>
		<link rel=stylesheet type="text/css" href="css/style.css">
	</head>
	<body>
		<div class="header">
			header
		</div>
		<div class="main-body">
<?php
			$book_id=$_POST['book_id'];
			$sql = "SELECT * FROM book where book_id = '".$book_id."'";
			$result = mysqli_query($conn,$sql);
			$row = mysql_fetch_row($result);
			$book = new Book($row[0],$row[1],$row[2],$row[3],$row[4],$row[5]);
?>			
			<center>
				<form action="updateBook.php" method="POST">
					<table>
						<tr>
							<td>書籍ID：<input type="hidden" value="<?php echo $book->getBookID();?>" name="book_id"></td>
							<td><?php echo $book->getBookID();?></td>
						</tr>
						<tr>
							<td>書籍名稱：</td>
							<td><input type="text" value="<?php echo $book->getBookName();?>" name="book_name"></td>
						</tr>
						<tr>
							<td>出版社：</td>
							<td><input type="text" name="publishing_house" value="<?php echo $book->getPublishingHouse();?>"></td>
						</tr>
						<tr>
							<td>作者：</td>
							<td><input type="text" name="author" value="<?php echo $book->getAuthor();?>"></td>
						</tr>
						<tr>
							<td>出版日期：</td>
							<td><input type="date" name="date" value="<?php echo $book->getDate();?>"></td>
						</tr>
					</table>
					<input type="submit" value="確認">
					<input type='submit' formaction='main.php' value='取消'>
				</form>
			</center>
		</div>
		<div class="footer">
			footer
		</div>
	</body>
</html>


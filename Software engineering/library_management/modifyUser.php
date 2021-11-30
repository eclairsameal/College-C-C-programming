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
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf8">
		<title>中華大學::圖書館管理系統</title>
		<link rel=stylesheet type="text/css" href="css/style.css">
	</head>
	<body>
		<div class="header">
			<?php include 'include/header.php'; ?>
		</div>
		<div class="main-body">
<?php
			$user_id=$_POST['user_id'];
			$sql = "SELECT * FROM user where user_id = '".$user_id."'";
			$result = mysql_query($sql);
			$row = mysql_fetch_row($result);
			$user = new User($row[0],$row[1],$row[2],$row[3]);
?>			
			<center>
				<form action="updateUser.php" method="POST">
					<table>
						<tr>
							<td>使用者ID：<input type="hidden" value="<?php echo $user->getUserID();?>" name="user_id"></td>
							<td><?php echo $user->getUserID();?></td>
						</tr>
						<tr>
							<td>使用者姓名：</td>
							<td><input type="text" value="<?php echo $user->getUserName();?>" name="user_name"></td>
						</tr>
						<tr>
							<td>使用者身分</td>
							<td>
								<select name="GML">
<?php
								if($user->getGML()=="G"){
?>
										<option value="G" selected >一般使用者</option>
										<option value="M">資料庫管理員</option>
										<option value="L">圖書館館員</option>
<?php
									}
									else if($user->getGML()=="M"){
?>
										<option value="G">一般使用者</option>
										<option value="M" selected>資料庫管理員</option>
										<option value="L">圖書館館員</option>							
<?php
									}
									else{
?>
										<option value="G">一般使用者</option>
										<option value="M">資料庫管理員</option>
										<option value="L" selected>圖書館館員</option>	
<?php
								}
?>
								</select>
							</td>
						</tr>
						<tr>
							<td>密碼：</td>
							<td><input type="password" name="pw" value="<?php echo $user->getPW();?>"></td>
						</tr>
					</table>
					<input type="submit" value="確認">
					<input type='submit' formaction='main.php' value='取消'>
				</form>
			</center>
		</div>
		<div class="footer">
			<?php include 'include/footer.php'; ?>
		</div>
	</body>
</html>


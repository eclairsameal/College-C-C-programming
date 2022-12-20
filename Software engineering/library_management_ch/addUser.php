<?php
	if(!isset($_SESSION)){
		session_start();
	}
	include("db/connect_check.php");
	include("db/db_connect.php");
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf8">
		<title>中華大學::圖書館管理系統</title>
		<link rel=stylesheet type="text/css" href="css/style.css">
		<script type="text/javascript">
 			function sub(){
    	 		submit.submit();
		  	}
		</script>
	</head>
	<body>
		<div class="header">
			<?php include 'include/header.php'; ?>
		</div>
		<div class="main-body">	
			<center>
				<form name="submit" action="insertUser.php" method="POST">
					<table>
						<tr>
							<td>使用者ID：</td>
							<td><input type="text" name="user_id"></td>
						</tr>
						<tr>
							<td>密碼：</td>
							<td><input type="password" name="pw"></td>
						</tr>
						<tr>
							<td>使用者姓名：</td>
							<td><input type="text" name="user_name"></td>
						</tr>
						<tr>
							<td>使用者身分：</td>
							<td>
								<select name="GML">
									<option value="G" selected >一般使用者</option>
									<option value="M">資料庫管理員</option>
									<option value="L">圖書館館員</option>
								</select>
							</td>
						</tr>
					</table>
					<input type="button" onClick="sub()" value="確認">
					<input type='button' onclick="self.location.href='main.php'" value='取消'>
				</form>
			</center>
		</div>
		<div class="footer">
			<?php include 'include/footer.php'; ?>
		</div>
	</body>
</html>


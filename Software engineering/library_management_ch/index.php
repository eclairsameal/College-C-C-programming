<?php
	session_unset();
	if(!isset($_SESSION)){
		session_start();
	}
	
?>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=utf8">
		<title>中華大學::圖書館管理系統</title>
		<link rel=stylesheet type="text/css" href="css/style.css">
		<script type="text/javascript">
			function check_data(){
				if(document.login.id.value.length==0){
					alert("帳號欄位尚未填寫！");
				}
				else if(document.login.pw.value.length==0){
					alert("密碼欄位尚未填寫！");
				}
				else{
					login.submit();
				}
			}
		</script>
	</head>
	<body>
		<div class="header">
			<?php include 'include/header.php'; ?>
		</div>
		<div class="login-body">
			<br><br><br><br><br>
			<center>
				<form action="check.php" method="POST" name="login" >
					<fieldset style="width:300px;">
						<legend>使用者登入</legend>
						<table align="center">

							<tr>
								<td>帳號：</td><td><input type="text" name="id" size="20"></td>
							</tr>
							<tr>
								<td>密碼：</td><td><input type="password" name="pw" size="20"></td>
							</tr>
							<tr>
								<td colspan=3><center><input type="button" value="登入" onClick="check_data()"></center></td>
							</tr>
						</table>
					</fieldset>
				</form>
			</center>
			
		</div>
		<div class="footer">
			<?php include 'include/footer.php'; ?>
		</div>
	</body>
</html>
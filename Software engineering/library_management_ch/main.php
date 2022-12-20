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
	$row = mysqli_fetch_row($result);
	$_SESSION['GML']=$row[2];
	//判別身分 G:一般使用者 L:館員 M:資料庫管理者
	if($_SESSION['GML']=="G"){
		$user = new User($row[0],$row[1],$row[2],$row[3]);
	}
	else if($_SESSION['GML']=="L"){
		$librarian = new Librarian($row[0],$row[1],$row[2],$row[3]);
	}
	else{
		$dbmer = new DBMer($row[0],$row[1],$row[2],$row[3]);
	}
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
			<div class="main-menu">
				<div class="menu-detail">
					<div class="menu-detail-head">
						會員資訊
					</div>
					<div class="menu-detail-body">
						<!--會員資訊-->
						<?php
							if($_SESSION['GML']=="G"){
								echo "使用者編號：".$user->getUserID()."<br>使用者姓名：".$user->getUserName()."<br>使用者身分："."一般使用者";
							}
							else if($_SESSION['GML']=="L"){
								echo "使用者編號：".$librarian->getUserID()."<br>使用者姓名：".$librarian->getUserName()."<br>使用者身分："."圖書館館員";
							}
							else{
								echo "使用者編號：".$dbmer->getUserID()."<br>使用者姓名：".$dbmer->getUserName()."<br>使用者身分："."資料庫管理員";
							}
						?>
					</div>
				</div>
				<div class="menu-connect">
					<div class="menu-connect-head">
						相關連結
					</div>
					<div class="menu-connect-body">
						<?php
							include 'link.php';
						?>
						
						
					</div>
					
				</div>

			</div>
			<div class="main-content">
				<?php
					include 'content.php';
				?>
			</div>
		</div>
		<div class="footer">
			<?php include 'include/footer.php'; ?>
		</div>

	</body>
</html>
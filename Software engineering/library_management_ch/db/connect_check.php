<?php
	if(!isset($_SESSION)){
		session_start();
	}
?>
	
<?php
	
	
	if($_SESSION['user_id'] == null)
	{
	       //echo "<script type='text/javascript'>alert('您無權限觀看此頁面!');</script>";
	       $url = "index.php";
			echo "<script type='text/javascript'>";
			echo "window.location.href='$url'";
			echo "</script>"; 
	}
		
?> 
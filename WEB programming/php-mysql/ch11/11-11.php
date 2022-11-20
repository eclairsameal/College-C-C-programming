<html>
<title>興趣選項</title>
<body>
<?php
	if (empty($_GET['score'])):
?>	
	<form action=<?php echo $_SERVER['PHP_SELF'] ?> method=get>
	姓名 <input type=text value="請輸入姓名" name=user><p>
        請選出你所喜歡的運動 <br>
	<input type=radio value=1 name=score>慢跑<br>
	<input type=radio value=2 name=score>游泳<br>
	<input type=radio value=3 name=score>籃球<br>
	<input type=submit value="送出">
	<input type=reset value="重寫"></form>
<?php
 	else :
		echo "Hi, ".$_GET['user']." <br> 你最喜歡的運動是" ;
		switch ($_GET['score']){
			case 1:
			    echo "慢跑" ;
			    break ;
			case 2 :
	         	echo "游泳" ;
			    break ;
			case 3 :
			    echo "籃球" ;
			    break ;
			default:
			    echo "沒有選擇" ;
		}
	endif
?>
</body>
</html>

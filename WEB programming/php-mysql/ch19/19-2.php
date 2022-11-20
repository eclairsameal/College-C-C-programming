<?php
  if (empty($_GET['choose'])):
?>
  <html>
  <title>多向轉址</title>
  <body>
  您喜歡瀏覽的運動相關訊息是:<br>
  <form action=<?php echo $_SERVER['PHP_SELF'] ?> method=get>
  <input type=radio name=choose value=1>游泳<br>
  <input type=radio name=choose value=2>健行<br>
  <input type=radio name=choose value=3>登山<br>
  <input type=submit value=" 選好了 ">
  </form>
  </body>
  </html>
<?php
  else:
  $hostname=$_SERVER['HTTP_HOST'];
  $abs_path=dirname($_SERVER['PHP_SELF']);
  $filename=$_GET['choose'].".htm";
  header("Location: http://".$hostname.$abs_path."/".$filename);
  exit;
  endif
?>
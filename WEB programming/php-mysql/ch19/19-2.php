<?php
  if (empty($_GET['choose'])):
?>
  <html>
  <title>�h�V��}</title>
  <body>
  �z���w�s�����B�ʬ����T���O:<br>
  <form action=<?php echo $_SERVER['PHP_SELF'] ?> method=get>
  <input type=radio name=choose value=1>��a<br>
  <input type=radio name=choose value=2>����<br>
  <input type=radio name=choose value=3>�n�s<br>
  <input type=submit value=" ��n�F ">
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
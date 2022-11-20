<?php
  header("Refresh: 5");
?>
<html>
<title>更新網頁</title>
<body>
<?php
  $msg[0]="學如逆水行舟, 不盡則退.";
  $msg[1]="今日事, 今日畢.";
  $msg[2]="登高必自卑, 行遠必自邇";
  $msg[3]="天下無難事, 只怕有心人";
  $msg[4]="失敗為成功之母";
  $msg[5]="微笑, 是最好的國際語言";
  $i=rand()% 6;
  echo "今日小語 : $msg[$i]";
?>
</body>
</html>
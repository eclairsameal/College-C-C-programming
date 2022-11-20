<?php
  session_start();
  if (!session_is_registered('A')) {
      session_register('A');
      $_SESSION['A'] = 1;
  }else{
      $_SESSION['A']++;
  }
  echo "Session id = ".session_id()."<p>";
  echo "變數值 = ".$_SESSION['A']."<p>"; 
  echo "<A HREF=\"./18-6.php\"?SID  TARGET=newwin>開新視窗</A>";
?>


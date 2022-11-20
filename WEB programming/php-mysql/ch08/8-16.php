<?php
  echo "目前執行的檔案名稱 ". $_SERVER['PHP_SELF']. "<br>";
  echo "伺服器使用的軟體 ". $_SERVER['SERVER_SOFTWARE']. "<br>";
  echo "文件的根目錄 ". $_SERVER['DOCUMENT_ROOT']. "<br>"; 
  echo "使用者相關資訊 ". $_SERVER['HTTP_USER_AGENT']. "<br>";
  echo "遠端使用者的位址 ". $_SERVER['REMOTE_ADDR']. "<br>";
  echo "遠端使用者的連線埠 ". $_SERVER['REMOTE_PORT']. "<br>";
?>
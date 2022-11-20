<?
        setcookie("password",$password);
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

          echo "<form method='post' action='sadd_a2.php'>";
          echo "代號：<input type = 'text'  name='id' ><br>\n";   
          echo "單位：<input type = 'text'  name='name' ><br>\n"; 
          echo "密碼：<input type = 'text'  name='password' ><br>\n";
          echo "項目表代號：<input type = 'text'  name='list' ><br>\n";
          echo "<input type = 'submit' value = '輸入確定' name=F1><input type = 'reset' value = '取消' name ='F2'>";
          echo "</form></html>";
?>
<?
        setcookie("password",$password);

        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

        $query="select *  from users where id='$unit_no'";
        $result=mysql_query($query);

        // 驗證單位密碼及查出單位代碼

          if ($my_row = mysql_fetch_array($result)) {
          echo "<form method='post' action='smod_a3.php'>";
          echo "<input type = 'hidden' value = $unit_no name='unit_no'>";
          echo "代號：<input type = 'text'  name='uid' value=$my_row[0]><br>\n";   
          echo "單位：<input type = 'text'  name='uname' value=$my_row[1]><br>\n"; 
          echo "密碼：<input type = 'text'  name='upassword' value=$my_row[2]><br>\n";
          echo "項目表代號：<input type = 'text'  name='ulist' value=$my_row[3]><br>\n";
          echo "<input type = 'submit' value = '輸入確定' name=F1><input type = 'reset' value = '取消' name ='F2'>";
          echo "</form></html>";
        } else {
          echo "密碼錯誤";
        }
?>
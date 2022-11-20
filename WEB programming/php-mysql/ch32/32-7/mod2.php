<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

        $query="select *  from bbs where $selected_id=id";
        $result=mysql_query($query);
        
        //顯示舊資料及編輯畫面
          $my_row = mysql_fetch_array($result);

          echo "<form method='post' action='mod3.php'>";
          echo "<input type = 'hidden'  name='selected_id' value=$selected_id>";     
          echo "日期：".$my_row[1]."\n";
          echo "<input type = 'hidden'  name='rdate' value='$my_row[1]'>";   
          echo "<input type = 'hidden'  name='unit' value='$my_row[2]'>";
          echo "<br>單位：".$my_row[2]."\n";
          echo "<br>主題：<input type = 'text'  name='topic' size='60' value='$my_row[3]'>\n";
          echo "<br>位址：".$my_row[4]."\n";
          echo "<input type = 'hidden'  name='ip' value='$my_row[4]'>\n";
          $my_row[5]=ereg_replace('<br>',chr(13),$my_row[5]); 
          echo "<br>說明：<TEXTAREA name=content rows=10 cols=70 wrap=virtual>";
          echo "$my_row[5] </TEXTAREA><BR>";
          echo "<input type = 'hidden'  name='ldate' value='$my_row[6]'>";
          echo "<input type = 'submit' value = '輸入確定' name=F1><input type = 'reset' value = '取消' name ='F2'>";
          echo "</form></html>";
?>
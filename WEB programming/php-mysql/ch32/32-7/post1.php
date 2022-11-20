<?
        setcookie("password",$password);
        setcookie("list",$list);         
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");
        $query="select *  from users where (password='$password') and (id='$list')";

        $result=mysql_query($query);

        // 驗證單位密碼及查出單位代碼
        
          if ($my_row = mysql_fetch_array($result)) {

          echo "<form method='post' action='post2.php'>";
 
       // 得到今天的日期

          echo "<input type = 'hidden'  name='unit' value=$my_row[1]>";
          echo "<br>公告單位：".$my_row[1]."\n";
?>
<br>截止時間：
<select size=1 name=limit onChange='ChangePage()'>
<option value=1>一週後</option>
<option value=2>兩週後</option>
<option value=3>三週後</option>
<option value=4 selected >四周後</option>
<option value=5>五週後</option>
<option value=6>六週後</option>
<option value=7>七週後</option>
<option value=8>二個月後</option>
<option value=9>三個月後</option>
</select><-自動刪除公告,此功能尚未啟用,不必設定
<?
          echo "<br>公告主題：<input type = 'text'  name='topic' size='60'>\n";
          echo "<br>公告內容：<TEXTAREA name=content rows=10 cols=70 wrap=virtual>";
          echo "</TEXTAREA><BR>";
          echo "<input type = 'submit' value = '輸入確定' name=F1><input type = 'reset' value = '取消' name ='F2'>";
          echo "</form></html>";
        } else {
          echo "密碼錯誤";
        }
?>
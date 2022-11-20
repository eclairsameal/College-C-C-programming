<?
        setcookie("password",$password);
        setcookie("list",$list);
        
        //連接資料庫
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理人員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理人員");

        $query="select *  from users where (password='$password') and (id='$list')";
        $result=mysql_query($query);
        // 驗證單位密碼及查出單位代碼
        $my_row = mysql_fetch_array($result);
        //顯示資料庫中的資料,反序顯示 
        
        $query="select * from bbs where trim(unit)='$my_row[1]' order by 1 desc";
        $result=mysql_query($query);

        echo "<table border=1 cellspacing=1>";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>選擇</td><td>日期</td><td>重要事項</td></tr>\n";
        while ($my_row = mysql_fetch_array($result)) { 
        //修改的按鈕
        echo "<tr><td><form method='post' action='mod2.php'>";
        echo "<input type = 'hidden'  value = $my_row[0] name='selected_id' ><input type = 'submit' value = '修改'></form></center></td>";
        
        echo "<td>".$my_row[1]."</td>";        
        echo "<td>".$my_row[3]."[".$my_row[2]."]"."</td>"; 
        echo "</tr>\n"; 
        }
echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p2.php'><input type = 'submit' value = '顯示選單'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '顯示公告'></form></td></tr></table>";
        echo "</html>";
        mysql_free_result($result); 
?>
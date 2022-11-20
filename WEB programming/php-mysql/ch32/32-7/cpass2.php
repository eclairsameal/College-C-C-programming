<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

        // 更新密碼資料

        $query="update users set password='$pass' where id='$unit_no' ";

        $result=mysql_query($query);
        echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p2.php'><input type = 'submit' value = '顯示選單'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '顯示公告'></form></td></tr></table>";
        echo "</html>";
?>
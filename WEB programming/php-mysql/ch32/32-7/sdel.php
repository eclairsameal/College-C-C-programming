<?
        setcookie("password",$password);

        //連接資料庫
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理人員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理人員");

        //刪除被選擇的資料
        if ($selected_id) {
        echo "<center><font color='#FFFF00'> 刪除資料完成,請繼續刪除!</center>";
        $query="delete from bbs where $selected_id=id";
        $result=mysql_query($query);
        }     


        //顯示資料庫中的資料 
        
        $query="select * from bbs order by 1 desc";
        $result=mysql_query($query);

        echo "<table border=1 cellspacing=1>";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>選擇</td><td>日期</td><td>重要事項</td></tr>";
        while ($my_row = mysql_fetch_array($result)) { 
        //刪除的按鈕
        echo "<tr><td><form method='post' action='sdel.php'>";
        echo "<input type = 'hidden' value = $my_row[0] name='selected_id'><input type = 'submit' value = '刪除'></form></center></td>";
        
        echo "<td>".$my_row[1]."</td>";        
        echo "<td>".$my_row[3]."[".$my_row[2]."]"."</td>"; 
        echo "</tr>"; 
        }

        echo "</html>";
        mysql_free_result($result); 
?>
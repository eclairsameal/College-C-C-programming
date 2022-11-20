<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        //連接資料庫
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理人員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理人員");
        $query="select *  from users where (password='$password') and (id=$list)";
        $result=mysql_query($query);
           $match_unit = mysql_fetch_array($result);
           
        //刪除被選擇的資料
        if ($selected_id) { 
                  $query="delete from bbs where ($selected_id=id) and ('$match_unit[1]'=trim(unit))";
                  $result=mysql_query($query);
                  $select_id='';
                  echo "<center><font color='#FFFF00'> 刪除資料完成,請繼續刪除!</center>";   
        }     

        //顯示資料庫中的資料         

        $query="select * from bbs where '$match_unit[1]'=trim(unit) order by 1 desc";
        $result=mysql_query($query);
        echo "<table border=1 cellspacing=1>";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>選擇</td><td>日期</td><td>重要事項</td></tr>";
        while ($my_row = mysql_fetch_array($result)) { 
        //刪除的按鈕
        echo "<tr><td width=4%><form method='post' action='del1.php'>";
        echo "<input type = 'hidden' value = $my_row[0] name='selected_id'><input type = 'submit' value = '刪除'></form></center></td>";
        
        echo "<td>".$my_row[1]."</td>";        
        echo "<td>".$my_row[3]."[".$my_row[2]."]"."</td>"; 
        echo "</tr>"; 
        }
        echo "</table>";
echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p2.php'><input type = 'submit' value = '顯示選單'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '顯示公告'></form></td></tr></table>";
        echo "</html>";
        mysql_free_result($result); 
?>
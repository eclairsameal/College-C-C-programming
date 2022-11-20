<?
        setcookie("password",$password);
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

        //顯示 users 資料庫中的資料 
        
        $query="select * from users order by 1 desc";
        $result=mysql_query($query);

        echo "<table border=1 cellspacing=1 >";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>選擇</td><td>代碼</td><td>單位</td><td>密碼</td><td>項目表代號</td></tr>";
        while ($my_row = mysql_fetch_array($result)) { 
      
        echo "<tr>";
        echo "<td width=4%><form method='post' action='smod_a2.php'>";
        echo "<input type = 'hidden' value = $my_row[0] name='unit_no'><input type = 'submit' value = '修改'></form></center></td>";
        
        echo "<td>".$my_row[0]."</td>";        
        echo "<td>".$my_row[1]."</td>"; 
        echo "<td>".$my_row[2]."</td>"; 
        echo "<td>".$my_row[3]."</td>";                 
        echo "</tr>"; 
        }
        echo "</html>";
        mysql_free_result($result); 
?>
<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        //連接資料庫
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理人員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理人員");

        //顯示 users 資料庫中的資料
        
        $query="select *  from users where (password='$password') and (id='$list ')";
        $result=mysql_query($query);
        
        echo "<form method='post' action='cpass2.php'>";        
        echo "<table border=1 cellspacing=1>";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>單位</td><td>密碼</td></tr>\n";
        while ($my_row = mysql_fetch_array($result)) { 

        //修改畫面

        echo "<tr>";
        echo "<input type = 'hidden'  value = $my_row[0] name='unit_no' >";
        echo "<td>".$my_row[1]."</td>";    
        echo "<td><input type = 'text' size=10 name='pass' value = '$my_row[2]'>";
        echo "</td></tr><tr><td colspan=2>";
        echo "<center><input type = 'submit' value ='確定' name='F1'></center></td>";
        echo "</form>\n"; 
        }
        echo "</html>";
        mysql_free_result($result); 
?>
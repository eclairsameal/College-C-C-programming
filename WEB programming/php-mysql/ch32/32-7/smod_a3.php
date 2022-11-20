<?
        setcookie("password",$password);
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

        // 更新
        $query="update users set id='$uid ',name='$uname ',password='$upassword ',list='$ulist ' where $unit_no=id ";
        $query=str_replace("\"","”",$query); 
        $result=mysql_query($query);
        $password="";
        echo "<form method='post' action='display.php'><input type = 'submit' value = '顯示公告'></form>";
        echo "</html>";
?>
<?
        setcookie("password",$password);
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");
        // 新增更新資料
        $query="insert into users values('$id ','$name ','$password ','$list ')";
        $query=str_replace("\"","”",$query); 
        $result=mysql_query($query);
        echo "</html>";
?>
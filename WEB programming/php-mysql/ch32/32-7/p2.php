<?
        setcookie("password",$password);
        setcookie("list",$list); 

        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

echo "<html>";

// 查詢 users 資料庫,密碼是否存在
        $query="select *  from users where (password='$password') and (id='$list')";
        $result=mysql_query($query);
// 驗證單位密碼及查出單位代碼
if ($my_row = mysql_fetch_array($result)) {
echo "<table border=0 cellspacing=1>";
echo "<body bgcolor='#FFFFFF'>";          
// 依據密碼選擇顯示的權限       
  if ($my_row[1] <> '管理者') {         
//使用者權限
    echo "<tr><td><form method='post' action='post1.php'>";
    echo "<input type = 'submit' value = '張貼公告' name ='F1'></form></td>";
    echo "<td><form method='post' action='mod1.php'>";
    echo "<input type = 'submit' value = '修改公告' name ='F2'></form></td>";
    echo "<td><form method='post' action='del1.php'>";
    echo "<input type = 'submit' value = '刪除公告' name ='F3'></form></td>";
    echo "<td><form method='post' action='cpass1.php'>";
    echo "<input type = 'submit' value = '更改密碼' name ='F4'></form></td>";
    echo "<td><form method='post' action='display.php'>";
    echo "<input type = 'submit' value = '顯示公告' name ='F5'></form></td></tr>";    
    
   } else {
//管理者權限
    echo "<tr><td><form method='post' action='sdel.php'>";
    echo "<input type = 'submit' value = '刪除公告' name ='F6'></form></td>";
    echo "<td><form method='post' action='sadd_a1.php'>";
    echo "<input type = 'submit' value = '新增帳號' name ='F7'></form></td>";
    echo "<td><form method='post' action='smod_a1.php'>";
    echo "<input type = 'submit' value = '修改帳號' name ='F8'></form></td>";
    echo "<td><form method='post' action='sdel_a1.php'>";
    echo "<input type = 'submit' value = '刪除帳號' name ='F9'></form></td>";
    echo "<td><form method='post' action='display.php'>";
    echo "<input type = 'submit' value = '顯示公告' name ='F9'></form></td></tr>";    
   }
} else {
echo "<center>密碼錯誤";
$password="";
echo "<table border='0'  cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p1.php'><input type = 'submit' value = '重新輸入密碼'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '顯示公告'></form></td></tr></table>";    

}
echo "</body></table></html>";
?>
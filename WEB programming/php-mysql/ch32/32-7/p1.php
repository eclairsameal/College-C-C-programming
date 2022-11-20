<?
setcookie("password",'');     
setcookie("list",''); 
     
echo "<html>";
echo "<BODY bgcolor='#aeac94'><center>";     

        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

        $query="select *  from users ";
        $result=mysql_query($query);
echo "<form method='post' action='p2.php'>";
        
        echo "單位：<select size=1 name=list onChange='ChangePage()'>\n";         
        while ($my_row = mysql_fetch_array($result)) {
        echo "<option value=".$my_row[0].">".$my_row[1]."</option>\n";
        } 
        echo "</select>\n";  

echo "密碼:<input type = 'password'  name='password' size='10'>";
echo "<input type = 'submit' value ='確定' name='F1'>";
echo "<input type = 'reset' value = '取消' name ='F2'>";
echo "</form></center>";
echo "</body>";
echo "</html>";            
?>
<?
        setcookie("password",$password);
        setcookie("list",$list); 

        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");


        //顯示資料庫中的資料 
        
        $query="select * from bbs order by 1 desc";
        $result=mysql_query($query);
        echo "<html><body bgcolor='#ECECEC'>\n";
        echo "<table border='0' width='580' cellpadding='0' cellpadding='0'>\n";        
        echo "<tr><td width='35' bgcolor='#AACC99'><center><font size='2'>日期</td><td width='540' bgcolor='#AACC99'><font size='2'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;公&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;告&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;標&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;題";
        
        echo "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='p1.php'>[管理]</a>&nbsp;<a href='help.html'>[說明]</a>";       
        echo "</td></tr>\n";
        while ($my_row = mysql_fetch_array($result)) { 
        echo "<tr><td width='35' bgcolor='#AACCFF'><center><font size='2'>".substr($my_row[1],5,5)."</center></td>\n";        
        echo "<td width='540' bgcolor='#AACCFF'><a href=display2.php?id=$my_row[0]><font size='2'>".$my_row[3]."</a>[".$my_row[2]."]"."</td>\n"; 
        echo "</tr>\n"; 
        }

        echo "</table></html>";

?>
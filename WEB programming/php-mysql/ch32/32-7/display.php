<?
        setcookie("password",$password);
        setcookie("list",$list); 

        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");


        //��ܸ�Ʈw������� 
        
        $query="select * from bbs order by 1 desc";
        $result=mysql_query($query);
        echo "<html><body bgcolor='#ECECEC'>\n";
        echo "<table border='0' width='580' cellpadding='0' cellpadding='0'>\n";        
        echo "<tr><td width='35' bgcolor='#AACC99'><center><font size='2'>���</td><td width='540' bgcolor='#AACC99'><font size='2'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;��&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;�i&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;��&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;�D";
        
        echo "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='p1.php'>[�޲z]</a>&nbsp;<a href='help.html'>[����]</a>";       
        echo "</td></tr>\n";
        while ($my_row = mysql_fetch_array($result)) { 
        echo "<tr><td width='35' bgcolor='#AACCFF'><center><font size='2'>".substr($my_row[1],5,5)."</center></td>\n";        
        echo "<td width='540' bgcolor='#AACCFF'><a href=display2.php?id=$my_row[0]><font size='2'>".$my_row[3]."</a>[".$my_row[2]."]"."</td>\n"; 
        echo "</tr>\n"; 
        }

        echo "</table></html>";

?>
<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

        // ��s���
        
        $content=ereg_replace(chr(13),'<br>',$content); 
        $query="update bbs set r_date='$rdate ',unit='$unit ',topic='$topic ',ip='$ip ',content='$content ',l_date='$ldate ' where $selected_id=id ";
        $query=str_replace("\"","��",$query); 
        $result=mysql_query($query);
echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p2.php'><input type = 'submit' value = '��ܿ��'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '��ܤ��i'></form></td></tr></table>";
        echo "</html>";
?>
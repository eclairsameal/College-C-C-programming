<?
        setcookie("password",$password);
        setcookie("list",$list);
        
        //�s����Ʈw
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z�H��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z�H��");

        $query="select *  from users where (password='$password') and (id='$list')";
        $result=mysql_query($query);
        // ���ҳ��K�X�άd�X���N�X
        $my_row = mysql_fetch_array($result);
        //��ܸ�Ʈw�������,�ϧ���� 
        
        $query="select * from bbs where trim(unit)='$my_row[1]' order by 1 desc";
        $result=mysql_query($query);

        echo "<table border=1 cellspacing=1>";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>���</td><td>���</td><td>���n�ƶ�</td></tr>\n";
        while ($my_row = mysql_fetch_array($result)) { 
        //�ק諸���s
        echo "<tr><td><form method='post' action='mod2.php'>";
        echo "<input type = 'hidden'  value = $my_row[0] name='selected_id' ><input type = 'submit' value = '�ק�'></form></center></td>";
        
        echo "<td>".$my_row[1]."</td>";        
        echo "<td>".$my_row[3]."[".$my_row[2]."]"."</td>"; 
        echo "</tr>\n"; 
        }
echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p2.php'><input type = 'submit' value = '��ܿ��'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '��ܤ��i'></form></td></tr></table>";
        echo "</html>";
        mysql_free_result($result); 
?>
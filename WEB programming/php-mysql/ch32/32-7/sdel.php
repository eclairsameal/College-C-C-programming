<?
        setcookie("password",$password);

        //�s����Ʈw
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z�H��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z�H��");

        //�R���Q��ܪ����
        if ($selected_id) {
        echo "<center><font color='#FFFF00'> �R����Ƨ���,���~��R��!</center>";
        $query="delete from bbs where $selected_id=id";
        $result=mysql_query($query);
        }     


        //��ܸ�Ʈw������� 
        
        $query="select * from bbs order by 1 desc";
        $result=mysql_query($query);

        echo "<table border=1 cellspacing=1>";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>���</td><td>���</td><td>���n�ƶ�</td></tr>";
        while ($my_row = mysql_fetch_array($result)) { 
        //�R�������s
        echo "<tr><td><form method='post' action='sdel.php'>";
        echo "<input type = 'hidden' value = $my_row[0] name='selected_id'><input type = 'submit' value = '�R��'></form></center></td>";
        
        echo "<td>".$my_row[1]."</td>";        
        echo "<td>".$my_row[3]."[".$my_row[2]."]"."</td>"; 
        echo "</tr>"; 
        }

        echo "</html>";
        mysql_free_result($result); 
?>
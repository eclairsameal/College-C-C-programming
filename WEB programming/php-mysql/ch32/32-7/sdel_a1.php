<?
        setcookie("password",$password);
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

        //�R���Q��ܪ����
        if ($unit_no) { 
                  $query="delete from users where $unit_no=id";
                  $result=mysql_query($query);
                  echo "<center><font color='#FFFF00'> �R����Ƨ���,���~��R��!</center>";   
        }     

        //��� users ��Ʈw������� 
        
        $query="select * from users order by 1 desc";
        $result=mysql_query($query);

        echo "<table border=1 cellspacing=1 >";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>���</td><td>�N�X</td><td>���</td><td>�K�X</td><td>���ت�N��</td></tr>";
        while ($my_row = mysql_fetch_array($result)) { 
      
        echo "<tr>";
        echo "<td width=4%><form method='post' action='sdel_a1.php'>";
        echo "<input type = 'hidden' value = $my_row[0] name='unit_no'><input type = 'submit' value = '�R��'></form></center></td>";
        
        echo "<td>".$my_row[0]."</td>";        
        echo "<td>".$my_row[1]."</td>"; 
        echo "<td>".$my_row[2]."</td>"; 
        echo "<td>".$my_row[3]."</td>";                 
        echo "</tr>"; 
        }

        echo "</html>";
        mysql_free_result($result); 
?>
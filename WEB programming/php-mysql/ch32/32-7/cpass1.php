<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        //�s����Ʈw
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z�H��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z�H��");

        //��� users ��Ʈw�������
        
        $query="select *  from users where (password='$password') and (id='$list ')";
        $result=mysql_query($query);
        
        echo "<form method='post' action='cpass2.php'>";        
        echo "<table border=1 cellspacing=1>";
        echo "<body bgcolor='#FFFFFF'>";
        echo "<tr><td>���</td><td>�K�X</td></tr>\n";
        while ($my_row = mysql_fetch_array($result)) { 

        //�ק�e��

        echo "<tr>";
        echo "<input type = 'hidden'  value = $my_row[0] name='unit_no' >";
        echo "<td>".$my_row[1]."</td>";    
        echo "<td><input type = 'text' size=10 name='pass' value = '$my_row[2]'>";
        echo "</td></tr><tr><td colspan=2>";
        echo "<center><input type = 'submit' value ='�T�w' name='F1'></center></td>";
        echo "</form>\n"; 
        }
        echo "</html>";
        mysql_free_result($result); 
?>
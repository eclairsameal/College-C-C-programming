<?
        setcookie("password",$password);
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

        // ��s
        $query="update users set id='$uid ',name='$uname ',password='$upassword ',list='$ulist ' where $unit_no=id ";
        $query=str_replace("\"","��",$query); 
        $result=mysql_query($query);
        $password="";
        echo "<form method='post' action='display.php'><input type = 'submit' value = '��ܤ��i'></form>";
        echo "</html>";
?>
<?
        setcookie("password",$password);
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");
        // �s�W��s���
        $query="insert into users values('$id ','$name ','$password ','$list ')";
        $query=str_replace("\"","��",$query); 
        $result=mysql_query($query);
        echo "</html>";
?>
<?
        setcookie("password",$password);
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

          echo "<form method='post' action='sadd_a2.php'>";
          echo "�N���G<input type = 'text'  name='id' ><br>\n";   
          echo "���G<input type = 'text'  name='name' ><br>\n"; 
          echo "�K�X�G<input type = 'text'  name='password' ><br>\n";
          echo "���ت�N���G<input type = 'text'  name='list' ><br>\n";
          echo "<input type = 'submit' value = '��J�T�w' name=F1><input type = 'reset' value = '����' name ='F2'>";
          echo "</form></html>";
?>
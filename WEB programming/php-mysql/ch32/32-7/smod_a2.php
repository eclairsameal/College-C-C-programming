<?
        setcookie("password",$password);

        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

        $query="select *  from users where id='$unit_no'";
        $result=mysql_query($query);

        // ���ҳ��K�X�άd�X���N�X

          if ($my_row = mysql_fetch_array($result)) {
          echo "<form method='post' action='smod_a3.php'>";
          echo "<input type = 'hidden' value = $unit_no name='unit_no'>";
          echo "�N���G<input type = 'text'  name='uid' value=$my_row[0]><br>\n";   
          echo "���G<input type = 'text'  name='uname' value=$my_row[1]><br>\n"; 
          echo "�K�X�G<input type = 'text'  name='upassword' value=$my_row[2]><br>\n";
          echo "���ت�N���G<input type = 'text'  name='ulist' value=$my_row[3]><br>\n";
          echo "<input type = 'submit' value = '��J�T�w' name=F1><input type = 'reset' value = '����' name ='F2'>";
          echo "</form></html>";
        } else {
          echo "�K�X���~";
        }
?>
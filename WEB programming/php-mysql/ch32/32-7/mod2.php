<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

        $query="select *  from bbs where $selected_id=id";
        $result=mysql_query($query);
        
        //����¸�Ƥνs��e��
          $my_row = mysql_fetch_array($result);

          echo "<form method='post' action='mod3.php'>";
          echo "<input type = 'hidden'  name='selected_id' value=$selected_id>";     
          echo "����G".$my_row[1]."\n";
          echo "<input type = 'hidden'  name='rdate' value='$my_row[1]'>";   
          echo "<input type = 'hidden'  name='unit' value='$my_row[2]'>";
          echo "<br>���G".$my_row[2]."\n";
          echo "<br>�D�D�G<input type = 'text'  name='topic' size='60' value='$my_row[3]'>\n";
          echo "<br>��}�G".$my_row[4]."\n";
          echo "<input type = 'hidden'  name='ip' value='$my_row[4]'>\n";
          $my_row[5]=ereg_replace('<br>',chr(13),$my_row[5]); 
          echo "<br>�����G<TEXTAREA name=content rows=10 cols=70 wrap=virtual>";
          echo "$my_row[5] </TEXTAREA><BR>";
          echo "<input type = 'hidden'  name='ldate' value='$my_row[6]'>";
          echo "<input type = 'submit' value = '��J�T�w' name=F1><input type = 'reset' value = '����' name ='F2'>";
          echo "</form></html>";
?>
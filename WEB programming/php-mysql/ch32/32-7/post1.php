<?
        setcookie("password",$password);
        setcookie("list",$list);         
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");
        $query="select *  from users where (password='$password') and (id='$list')";

        $result=mysql_query($query);

        // ���ҳ��K�X�άd�X���N�X
        
          if ($my_row = mysql_fetch_array($result)) {

          echo "<form method='post' action='post2.php'>";
 
       // �o�줵�Ѫ����

          echo "<input type = 'hidden'  name='unit' value=$my_row[1]>";
          echo "<br>���i���G".$my_row[1]."\n";
?>
<br>�I��ɶ��G
<select size=1 name=limit onChange='ChangePage()'>
<option value=1>�@�g��</option>
<option value=2>��g��</option>
<option value=3>�T�g��</option>
<option value=4 selected >�|�P��</option>
<option value=5>���g��</option>
<option value=6>���g��</option>
<option value=7>�C�g��</option>
<option value=8>�G�Ӥ��</option>
<option value=9>�T�Ӥ��</option>
</select><-�۰ʧR�����i,���\��|���ҥ�,�����]�w
<?
          echo "<br>���i�D�D�G<input type = 'text'  name='topic' size='60'>\n";
          echo "<br>���i���e�G<TEXTAREA name=content rows=10 cols=70 wrap=virtual>";
          echo "</TEXTAREA><BR>";
          echo "<input type = 'submit' value = '��J�T�w' name=F1><input type = 'reset' value = '����' name ='F2'>";
          echo "</form></html>";
        } else {
          echo "�K�X���~";
        }
?>
<?
        setcookie("password",$password);
        setcookie("list",$list); 

        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

echo "<html>";

// �d�� users ��Ʈw,�K�X�O�_�s�b
        $query="select *  from users where (password='$password') and (id='$list')";
        $result=mysql_query($query);
// ���ҳ��K�X�άd�X���N�X
if ($my_row = mysql_fetch_array($result)) {
echo "<table border=0 cellspacing=1>";
echo "<body bgcolor='#FFFFFF'>";          
// �̾ڱK�X�����ܪ��v��       
  if ($my_row[1] <> '�޲z��') {         
//�ϥΪ��v��
    echo "<tr><td><form method='post' action='post1.php'>";
    echo "<input type = 'submit' value = '�i�K���i' name ='F1'></form></td>";
    echo "<td><form method='post' action='mod1.php'>";
    echo "<input type = 'submit' value = '�ק綠�i' name ='F2'></form></td>";
    echo "<td><form method='post' action='del1.php'>";
    echo "<input type = 'submit' value = '�R�����i' name ='F3'></form></td>";
    echo "<td><form method='post' action='cpass1.php'>";
    echo "<input type = 'submit' value = '���K�X' name ='F4'></form></td>";
    echo "<td><form method='post' action='display.php'>";
    echo "<input type = 'submit' value = '��ܤ��i' name ='F5'></form></td></tr>";    
    
   } else {
//�޲z���v��
    echo "<tr><td><form method='post' action='sdel.php'>";
    echo "<input type = 'submit' value = '�R�����i' name ='F6'></form></td>";
    echo "<td><form method='post' action='sadd_a1.php'>";
    echo "<input type = 'submit' value = '�s�W�b��' name ='F7'></form></td>";
    echo "<td><form method='post' action='smod_a1.php'>";
    echo "<input type = 'submit' value = '�ק�b��' name ='F8'></form></td>";
    echo "<td><form method='post' action='sdel_a1.php'>";
    echo "<input type = 'submit' value = '�R���b��' name ='F9'></form></td>";
    echo "<td><form method='post' action='display.php'>";
    echo "<input type = 'submit' value = '��ܤ��i' name ='F9'></form></td></tr>";    
   }
} else {
echo "<center>�K�X���~";
$password="";
echo "<table border='0'  cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p1.php'><input type = 'submit' value = '���s��J�K�X'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '��ܤ��i'></form></td></tr></table>";    

}
echo "</body></table></html>";
?>
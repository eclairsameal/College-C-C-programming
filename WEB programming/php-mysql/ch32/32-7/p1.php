<?
setcookie("password",'');     
setcookie("list",''); 
     
echo "<html>";
echo "<BODY bgcolor='#aeac94'><center>";     

        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

        $query="select *  from users ";
        $result=mysql_query($query);
echo "<form method='post' action='p2.php'>";
        
        echo "���G<select size=1 name=list onChange='ChangePage()'>\n";         
        while ($my_row = mysql_fetch_array($result)) {
        echo "<option value=".$my_row[0].">".$my_row[1]."</option>\n";
        } 
        echo "</select>\n";  

echo "�K�X:<input type = 'password'  name='password' size='10'>";
echo "<input type = 'submit' value ='�T�w' name='F1'>";
echo "<input type = 'reset' value = '����' name ='F2'>";
echo "</form></center>";
echo "</body>";
echo "</html>";            
?>
<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        mysql_connect("localhost","","") or die ("�L�k�s����Ʈw,�гq���t�κ޲z��");
        mysql_select_db("member") or die ("�L�k�}�Ҹ�Ʈw,�гq���t�κ޲z��");

if ($topic) {        
           $rdate=date ("y-m-d H:i:s");

//���i�����ഫ

        switch ($limit) {
        case '1':   
                 $limit_day='interval 7 day';
                 break;
        case '2':
                 $limit_day='interval 14 day';
                 break;
        case '3':
                 $limit_day='interval 21 day';
                 break;
        case '4':
                 $limit_day='interval 1 month';
                 break;
        case '5':
                 $limit_day='interval 35 day';
                 break;
        case '6':
                 $limit_day='interval 42 day';
                 break;
        case '7':
                 $limit_day='interval 49 day';
                 break;
        case '8':
                 $limit_day='interval 2 month';
                 break;
        case '9':
                 $limit_day='interval 3 month';
                 break;
        default:
                 $limit_day='interval 4 month';
                 break;
        }

           $ldate='date_add(\''.$rdate.'\','.$limit_day.')';

           $content=ereg_replace(chr(13),'<br>',$content); 
           $query='insert into bbs values (\'null\','.'\''.$rdate.'\',\' '.' '.$unit.'\',\''.' '.'  '.$topic.'  \',\''.$REMOTE_ADDR.'\',\''.' '.' '.$content.' '.'\','.$ldate.')';
           $query=str_replace("\"","��",$query);
           echo $query;
           $result=mysql_query($query);

         //�N�d�ߥy���b�Ϊ� " �Ÿ����������� ���@�Ÿ�,�H�K�y���d�ߥy���~
} else {
echo "�S���D�D<br>";
}
echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p2.php'><input type = 'submit' value = '��ܿ��'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '��ܤ��i'></form></td></tr></table>";

?>
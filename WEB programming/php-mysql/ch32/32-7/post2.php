<?
        setcookie("password",$password);
        setcookie("list",$list); 
        
        mysql_connect("localhost","","") or die ("無法連接資料庫,請通知系統管理員");
        mysql_select_db("member") or die ("無法開啟資料庫,請通知系統管理員");

if ($topic) {        
           $rdate=date ("y-m-d H:i:s");

//公告期限轉換

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
           $query=str_replace("\"","”",$query);
           echo $query;
           $result=mysql_query($query);

         //將查詢句中半形的 " 符號換成全型的 ”　符號,以免造成查詢句錯誤
} else {
echo "沒有主題<br>";
}
echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr><td align=right>\n";
echo "<form method='post' action='p2.php'><input type = 'submit' value = '顯示選單'></form></td><td>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '顯示公告'></form></td></tr></table>";

?>
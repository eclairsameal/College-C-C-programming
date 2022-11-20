<?
setcookie('password',$password);
setcookie("list",$list); 

mysql_connect('localhost','','') or die ('無法連接資料庫,請通知系統管理員');
mysql_select_db('member') or die ('無法開啟資料庫,請通知系統管理員');

//取得資料庫中的資料         

$query="select * from bbs where id='$id' ";
$result=mysql_query($query);
$my_row = mysql_fetch_array($result);

// 顯示資料

echo "<HEAD>\n";
echo "<link rel='stylesheet' href='document.css' type='text/css'>\n";
echo "</HEAD>\n";
echo "<BODY bgcolor='#AACC99'> \n";
echo "<div align='left'>\n";

echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr>\n";
echo "<td><center>";
//echo "<form method='post' action='display.php'><input type = 'submit' value = '顯示公告'></form></td></tr></table>";

echo "<table border='0' width='580' cellpadding='0' cellpadding='0'>\n";
echo "<td style='border-style: solid; border-width: 1'>\n";
echo "<table border='0' width='580' cellpadding='0' cellpadding='0'>\n";
echo "<tr>\n";
echo "<td width='500' align='left' valign='top' bgcolor='#ECECEC' ><font size='2'>\n";
echo "公告日期:$my_row[1],登錄位址:$my_row[4] \n";
echo ",截止日期:$my_row[6]</td></tr>\n"; 

echo "<tr>\n";  
echo "<td bgcolor='#AACC99'><font size='2' color='#0000FF'>\n"; 
echo "$my_row[5]\n";     
echo "</td>\n"; 
echo "</tr>\n"; 

echo "<tr>\n";  
echo "<td width=100% bgcolor='#AACC99' align='right'>\n"; 
echo "<font size='2'>$my_row[2]\n";     
echo "</td>\n"; 
echo "</tr>\n"; 

echo "</td>\n"; 
echo "</table>\n";
echo "</table>\n";
echo "</div>\n"; 
echo "<table border='0' width='580' cellpadding='0' cellpadding='0'><tr>\n";
echo "<td><center>";
echo "<form method='post' action='display.php'><input type = 'submit' value = '顯示公告'></form></td></tr></table>";
echo "</BODY>"; 
echo "</HTML>"; 


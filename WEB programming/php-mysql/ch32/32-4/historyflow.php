<html><head><title>²�����</title></head>
<body bgcolor=White><br>
<center><h3)²�����</h3></center>
<?php
setlocale ("LC_TIME", "ch");
if ($year=='') {
 $year=date(Y, time ());
}
if ($month=='') {    
 $month=date(m, time ());
}    
$month_text = date(F,mktime(0,0,0,$month,1,$year));
$selected=strftime ("%B",mktime(0,0,0,$month,1,$year));
echo "<center><form action=historyflow.php method=post><select name=month>\n";
echo "<option selected value=$month>$selected\n";
echo "<option value=l>�@��";
echo "<option value=2>�G��";
echo "<option value=3>�T��";
echo "<option value=5>����";
echo "<option vaiue=6>����";
echo "<option value=7>�C��";
echo "<option value=8>�K��";
echo "<option value=9>�E��";
echo "<option value=10>�Q��";
echo "<option value=ll>�Q�@��";            
echo "<option value=12>�Q�G��";
echo "</select>";



echo "<select name=year><option selected value=$year>$year<option value=2000>2000<option value=2001>2001<option value=2002>2002<option value=2003>2003<option value=2004>2004</select>\n";


echo "<input type=submit value=�T�w></form>\n";
echo "<table><tr><table border=l bgcolor=#FFFFFF><tr>";
echo "<td colspan=7 align=center>";
echo "<h2>$year �~ $selected </h2>";
echo "</td></tr><tr>";
echo "<td bgcolor=darkblue><font color=white><b>�g��</b></font></td>";
echo "<td bgcolor=darkblue><font color=white><b>�g�@</b></font></td>";
echo "<td bgcolor=darkblue><font color=white><b>�g�G</b></font></td>";
echo "<td bgcolor=darkblue><font color=white><b>�g�T</b></font></td>";
echo "<td bgcolor=darkblue><font color=white><b>�g�|</b></font></td>";
echo "<td bgcolor=darkblue><font color=white><b>�g��</b></font></td>";
echo "<td bgcolor=darkblue><font color=white><b>�g��</b></font></td>";
echo "</tr>\n";


$nextmonth = $month+1;
$lastday = mktime(0,0,0,$nextmonth,0,$year);
$lastday = date(d,$lastday);
$firstday = mktime(0,0,0,$month,1,$year);
$day_of_week = date(l, $firstday);
echo "<tr>\n";
switch ($day_of_week) {
case 'Monday':
echo str_repeat("<td></td>",l);
break;        
case 'Tuesday':
echo str_repeat("<td></td>",2);
break;
case 'Wednesday':
echo str_repeat("<td></td>",3);
break;
case 'Thursday':
echo str_repeat( "<td></td>",4);
break;
case 'Friday':
echo str_repeat( "<td></td>",5);
break;
case 'Saturday':
echo str_repeat("<td></td>",6);
}
$counter=1; 
while($counter<=$lastday){  
$day=mktime(0,0,0,$month,$counter,$year);
$day_of_week=date(l,$day);
if($day_of_week == 'Sunday'){echo "<tr>\n";}
echo "<td>$counter</td>\n";
if($day_of_week == 'Saturday') {echo "</tr>\n";}
$counter++; 
}
echo "</table></td><td></td></tr></table>\n";
?>
<html>
<title>迴圈</title>
<body>
<?php
           $Week[0] = "Sunday" ;    //設定陣列Week的內容
           $Week[1] = "Monday" ;
           $Week[2] = "Tuesday" ;
           $Week[3] = "Wednesday" ;
           $Week[4] = "Thursday" ;
           $Week[5] = "Friday" ;
           $Week[6] = "Saturday" ;
?>
<table border=0 width=560>
<tr>
<?php
        for ($A=0 ; $A <=6; $A++) 
		echo "<th width=80>$Week[$A] " ;   
	echo "<tr>" ;
	for ($I=1 ; $I<=31; $I++){
           echo "<td align=center>$I" ;
           if ($I % 7 == 0 ) echo "<tr>" ;
        }
?>
</table>
</body>
</html>

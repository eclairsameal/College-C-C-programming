<html>
<title>迴圈應用</title>
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
<table border=5 width=560>
<tr>
<?php
        for ($A=0 ; $A <=6; $A++) 
		echo "<td width=80>$Week[$A]</td> " ;

?>
</tr>
</table>
</body>
</html>

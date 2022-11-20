<?php
   $s=array( array(62,22,35,58,90),
             array(73,6,94,12,15),
             array(25,17,75,20,25));
  $b=array(10,20,30);
?>
<html>
<title>¤Gºû°}¦C</title>
<body>
<table border=1 width=300 >
<?php
   for ($i=0; $i<=2; $i++){
   echo "<tr align=center>";
   foreach($s[$i] as $v)
      echo "<td> $v </td>";
   echo "<td bgcolor=#ffffd2>".array_sum($s[$i])."</td>";
   }
?>
</table>
</body>
</html>
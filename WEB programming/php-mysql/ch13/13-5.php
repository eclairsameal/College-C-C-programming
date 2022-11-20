<html>
<title>統計表</title>
<body>
<?php
   $s = array (0,15,10,20,17,3,8,10,15,12) ;
   echo "銷售員業績統計表<p>" ;
   $cnt=count($s);
   for ($A=1 ; $A<$cnt; $A++){
      echo "編號 $A 銷售員 : " ;
      $s[0]+=$s[$A] ;
      $p=$s[$A]*20;
      echo "<img src=line.jpg width=$p height=10>";
      echo " $s[$A]<br>" ;
   }
      echo "<p>總量總量 : $s[0]" ;
?>
</body>
</html>

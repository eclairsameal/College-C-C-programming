<html>
<title>�έp��</title>
<body>
<?php
   $s = array (0,15,10,20,17,3,8,10,15,12) ;
   echo "�P����~�Z�έp��<p>" ;
   $cnt=count($s);
   for ($A=1 ; $A<$cnt; $A++){
      echo "�s�� $A �P��� : " ;
      $s[0]+=$s[$A] ;
      $p=$s[$A]*20;
      echo "<img src=line.jpg width=$p height=10>";
      echo " $s[$A]<br>" ;
   }
      echo "<p>�`�q�`�q : $s[0]" ;
?>
</body>
</html>

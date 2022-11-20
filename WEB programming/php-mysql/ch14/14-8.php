<?php
   function var_len(){
     $n=func_num_args();
     echo "羆肚".$n."把计<br>";
     echo "把计ず甧<br>";
     $op=func_get_args();
     for ($i=0; $i<$n; $i++){
       echo "- $op[$i] <br>";
     }
  }
?>
<html>
<title>跑把计</title>
<body>
<?php
  echo "2把计 <br>";
  var_len(10,20);
  echo "<p>";
  echo "3把计 <br>";
  var_len("Hello","My","Friend");
?>
</body>
</html>
<?php
   function var_len(){
     $n=func_num_args();
     echo "�`�@�ǤJ".$n."�ӰѼ�<br>";
     echo "�ѼƤ��e�p�U<br>";
     $op=func_get_args();
     for ($i=0; $i<$n; $i++){
       echo "- $op[$i] <br>";
     }
  }
?>
<html>
<title>�i�ܪ��װѼ�</title>
<body>
<?php
  echo "2�ӰѼ� <br>";
  var_len(10,20);
  echo "<p>";
  echo "3�ӰѼ� <br>";
  var_len("Hello","My","Friend");
?>
</body>
</html>
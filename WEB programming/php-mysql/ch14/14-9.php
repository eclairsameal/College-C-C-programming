<?php
    function old_sum($op1,$op2){
      return $op1+$op2;
   }
   function var_sum(){
      $n=func_num_args();
      $op=func_get_args();
      for ($i=0; $i<$n; $i++){
         $sum+=sum+$op[$i];
      }
      return $sum;
   }
?>
<html>
<title>�i�ܪ��װѼ�</title>
<body>
<?php
  echo "�T�w�ѼƭӼƪ��[�k : ".old_sum(10,20);
  echo "<p>";
  $t1=var_sum(10,20);
  echo "�i�ܪ��װѼƪ��[�k(2�ӰѼ�) : $t1 <p>";
  $t2=var_sum(10,20,30);
  echo "�i�ܪ��װѼƪ��[�k(3�ӰѼ�) : $t2 <p>";
?>
</body>
</html>
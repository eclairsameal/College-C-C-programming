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
<title>跑把计</title>
<body>
<?php
  echo "㏕﹚把计计猭 : ".old_sum(10,20);
  echo "<p>";
  $t1=var_sum(10,20);
  echo "跑把计猭(2把计) : $t1 <p>";
  $t2=var_sum(10,20,30);
  echo "跑把计猭(3把计) : $t2 <p>";
?>
</body>
</html>
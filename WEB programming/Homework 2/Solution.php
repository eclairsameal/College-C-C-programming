<html>
<head>
  <title>Solution</title>
</head>
<body>
<?php
  $ia = $_POST['a'];
  $ib = $_POST['b'];
  $ic = $_POST['c'];
  $d = ($ib*$ib)-(4*$ia*$ic);
  if($d>0){
    $Xa = (-1*$ib-sqrt($d))/(2*$ia);
    $Xb = (-1*$ib+sqrt($d))/(2*$ia);
    echo "X1 = $Xa, ";
    echo "X2 = $Xb";
  }
  if($d==0){
    $x = ((-1*$ib)/2*$ia);
    echo "X = $x";
  }
  if($d<0){
    echo "no solution";
  }

?>
</body>
</html>

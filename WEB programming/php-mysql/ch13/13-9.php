<?php
  $a=array('this', 'is', 'a', 'book','that','is', 'a','pen');
  $pos=array_search('book',$a);
  echo "$a[$pos]的位置在陣列中第 $pos 位<p>";
  $p=array_keys($a,'is');
  foreach ($p as $k => $v)
     echo "第[ $k ]個 is 出現在陣列第 $v 個位置<br>";
  echo "總共有 ".
count($p)." 個 is 在陣列中 <br>";
?>
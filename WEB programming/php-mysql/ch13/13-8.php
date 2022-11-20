<?php
     function show_array($a){
       foreach ($a as $v)
          echo "[$v]  ";
       echo "<p>";
     }

     $p=array(1,3,5,2,4,6);
     $k=array('this', 'is', 'a', 'book','that','pen');
     echo "原陣列順序:<br>";
     show_array($p);
     sort($p);
     echo "sort()排序後順序:<br>";
     show_array($p); 
     rsort($p);
     echo "rsort()排序後順序:<br>";
     show_array($p);
     echo "<hr width=300 align=left>";
     echo "原陣列順序:<br>";
     show_array($k);
     array_multisort($k);
     echo "排序後順序:<br>";
     show_array($k); 
     array_multisort($k,SORT_DESC);
     echo "DESC排序後順序:<br>";
     show_array($k); 
     array_multisort($p,$k);
     echo "同時排序:<br>";
     show_array($p);
     show_array($k);
?>
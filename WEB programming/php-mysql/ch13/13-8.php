<?php
     function show_array($a){
       foreach ($a as $v)
          echo "[$v]  ";
       echo "<p>";
     }

     $p=array(1,3,5,2,4,6);
     $k=array('this', 'is', 'a', 'book','that','pen');
     echo "��}�C����:<br>";
     show_array($p);
     sort($p);
     echo "sort()�Ƨǫᶶ��:<br>";
     show_array($p); 
     rsort($p);
     echo "rsort()�Ƨǫᶶ��:<br>";
     show_array($p);
     echo "<hr width=300 align=left>";
     echo "��}�C����:<br>";
     show_array($k);
     array_multisort($k);
     echo "�Ƨǫᶶ��:<br>";
     show_array($k); 
     array_multisort($k,SORT_DESC);
     echo "DESC�Ƨǫᶶ��:<br>";
     show_array($k); 
     array_multisort($p,$k);
     echo "�P�ɱƧ�:<br>";
     show_array($p);
     show_array($k);
?>
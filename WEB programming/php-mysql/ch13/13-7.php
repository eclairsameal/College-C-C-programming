<?php
   $tableA=array('I01'=> 21, 'I03'=> 32, 'I06'=> 16);
   $tableB=array('I01'=> 31, 'I02'=> 16, 'I06'=> 22);
   foreach($tableA as $k => $v){
       if (isset($tableB[$k])){
         $tableA[$k]=$tableB[$k]+$v;
         unset($tableB[$k]);
       }
   }
   foreach($tableB as $k => $v)
         if (isset($tableB[$k]))
             $tableA[$k]=$tableB[$k];
   echo "½s¸¹  ¼Æ¶q<br>";
   foreach($tableA as $k => $v)
         echo "[ $k ] : ".$tableA[$k]."<br>";
?>
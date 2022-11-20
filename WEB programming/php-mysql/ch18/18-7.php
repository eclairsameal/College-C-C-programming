<?php
   function show(){
   echo "session_id = ".session_id()."<br>";
   echo "A = ".$_SESSION['A']."<br>";
   echo "B = ".$_SESSION['B']."<br>";
   echo "C = ".$_SESSION['C']."<p>";      
   }
   session_start();
   session_register("A");
   session_register("B");
   session_register("C");
   $_SESSION['A']=10;
   $_SESSION['B']=20;
   $_SESSION['C']=30;
   show();
   session_unregister("A");
   show();
   session_unset();
   show();
   session_destroy();
   show();
?>
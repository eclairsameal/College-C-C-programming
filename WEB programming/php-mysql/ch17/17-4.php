<?php
    class test {
          private $val;
          function __construct() {
                 $this->val=10;
                 echo "物件產生 <p>";
          }
          public function get_val(){
                 return $this->val;
          }
          function __destruct(){
                 echo "<p>刪除物件 <p>";
                 echo "<hr width=50% align=left>";
          }
     }

     $a=new test;
     echo $a->get_val();
?>
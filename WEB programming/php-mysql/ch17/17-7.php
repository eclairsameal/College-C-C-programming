<?php
   abstract class car { 
        protected $color ;
        abstract function get_color(); 
        abstract function set_color($n);
   }
   class mycar extends car {
        private $weight=1500;
        function get_color(){
             return $this->color;
        }
        function set_color($newcolor){
             $this->color=$newcolor ;
        }
        function get_weight(){ 
             return $this->weight;
        }
   }
   $a=new mycar ;
   $a->set_color("����") ;
   echo "�����O".$a->get_color()."<p>";
   echo "�����O".$a->get_weight()."����<p>";
?> 
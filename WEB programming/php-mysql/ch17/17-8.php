<?php
    interface width {
         public function get_width();
         public function set_width($w);
    }
    interface area {
         public function get_area();
         public function get_around();
    }
    class squareA implements width {
         private $w;
         public function get_width(){
              return $this->w;
         }
         public function set_width($newW){
              $this->w=$newW ;
         }
    }
    class squareB implements width, area {
         private $w;
         public function get_width(){
              return $this->w;
         }
         public function set_width($newW){
              $this->w=$newW ;
         }
         public function get_area(){
              return $this->w * $this->w;
         }
         public function get_around(){
              return 4*$this->w;
         }
    }
    $a=new squareA;
    $a->set_width(10);
    echo "��� A ����O ". $a->get_width()."<p>";
    $b=new squareB;
    $b->set_width(30);
    echo "��� B ����O ". $b->get_width()."<br>";
    echo "��� B ���n�O ". $b->get_area()."<br>";
    echo "��� B �P���O ". $b->get_around()."<br>";
?>
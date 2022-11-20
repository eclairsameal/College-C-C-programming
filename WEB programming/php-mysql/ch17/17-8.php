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
    echo "方形 A 邊長是 ". $a->get_width()."<p>";
    $b=new squareB;
    $b->set_width(30);
    echo "方形 B 邊長是 ". $b->get_width()."<br>";
    echo "方形 B 面積是 ". $b->get_area()."<br>";
    echo "方形 B 周長是 ". $b->get_around()."<br>";
?>
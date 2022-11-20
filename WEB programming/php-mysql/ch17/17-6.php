 <?php
   class A {
     function __construct(){
          echo "我是類別A的建構子 <p>";
     }
  }
   class B extends A{
     function noop(){
          echo "我是類別B的成員函數 <p>";
     }
  }
  class C extends B{
      function noop(){
          echo "我是類別C的成員函數 <p>";
      }
 }
  $i=new A;
  $j=new B;
  $k=new C;
?>
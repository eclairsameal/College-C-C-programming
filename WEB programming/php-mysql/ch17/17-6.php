 <?php
   class A {
     function __construct(){
          echo "�ڬO���OA���غc�l <p>";
     }
  }
   class B extends A{
     function noop(){
          echo "�ڬO���OB��������� <p>";
     }
  }
  class C extends B{
      function noop(){
          echo "�ڬO���OC��������� <p>";
      }
 }
  $i=new A;
  $j=new B;
  $k=new C;
?>
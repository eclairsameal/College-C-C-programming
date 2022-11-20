<?php
    class cart {
        var $item ;
        var $total ;
        function AddOneItem($name,$cost){
           $this->item[]=$name ;
           $this->item[]=$cost;
        }
        function GetItem(){
           $c=count($this->item);
           for ($i=0; $i<$c; $i+=2){
              echo "項目 : ".$this->item[$i];
              echo " => 金額 : ".$this->item[$i+1]." 元<br>";
           }
        }
        function sum() {
           $c=count($this->item);
           $s=0;
           for ($i=1; $i<$c; $i+=2){
              $s+=(integer)$this->item[$i];
           }
           return $s;
	}
    }
?>
<html>
<title>物件應用</title>
<body>
<?php
          $customer1=new cart ;
          $customer2=new cart ;
          $customer1->AddOneItem("主機板","3000") ;
          $customer1->AddOneItem("顯示卡","800") ;
          $customer1->AddOneItem("記憶體","1800") ;
          $customer2->AddOneItem("PC遊戲","2500") ;
          $customer2->AddOneItem("滑鼠","100") ;
          $customer2->AddOneItem("無線網路卡","2500") ;
          $customer2->AddOneItem("LCD顯示器","8000") ;
	  echo "第一位顧客採購內容: <br>";
          $customer1->GetItem();
          echo "<hr>" ;
          echo "第二位顧客採購內容: <br>";
          $customer2->GetItem(); 
          echo "<hr>";
          $total=$customer1->sum()+$customer2->sum();
          echo "今日營業額 $total 元";   
?>
</body>
</html>

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
              echo "���� : ".$this->item[$i];
              echo " => ���B : ".$this->item[$i+1]." ��<br>";
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
<title>��������</title>
<body>
<?php
          $customer1=new cart ;
          $customer2=new cart ;
          $customer1->AddOneItem("�D���O","3000") ;
          $customer1->AddOneItem("��ܥd","800") ;
          $customer1->AddOneItem("�O����","1800") ;
          $customer2->AddOneItem("PC�C��","2500") ;
          $customer2->AddOneItem("�ƹ�","100") ;
          $customer2->AddOneItem("�L�u�����d","2500") ;
          $customer2->AddOneItem("LCD��ܾ�","8000") ;
	  echo "�Ĥ@���U�ȱ��ʤ��e: <br>";
          $customer1->GetItem();
          echo "<hr>" ;
          echo "�ĤG���U�ȱ��ʤ��e: <br>";
          $customer2->GetItem(); 
          echo "<hr>";
          $total=$customer1->sum()+$customer2->sum();
          echo "������~�B $total ��";   
?>
</body>
</html>

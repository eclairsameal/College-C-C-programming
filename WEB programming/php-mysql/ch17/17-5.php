 <?php
	class car {
		var $color ;
		function car() {	
			$this->color="����" ;
		}
		function set_color($c){
			$this->color=$c ;
		}
		function get_color(){
			return $this->color ;
		}
	} 
	class RV extends car {
		function show_drive($n){
			echo $n." ���X��" ;
		}
	}
 ?>
 <html>
 <title>�����~��</title>
 <body>
 <?php
	$JohnCar=new car ;
	$JohnCar->set_color("�_�Ŧ�") ;
	echo "John���l���C��O ".$JohnCar->get_color()."<p>" ;
	$MaryCar=new RV ;
	echo "Mary���l�O " ;
        $MaryCar->show_drive(4) ;
        echo ",�C��O".$MaryCar->get_color() ;
 ?>
 </body>
 </html>
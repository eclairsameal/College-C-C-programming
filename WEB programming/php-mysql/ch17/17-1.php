 <?php
 	class car {
		var $color ;
		function set_color($c){
			$this->color=$c ;
		}
		function get_color(){
			return $this->color ;
		}
	} 
 ?>
 <html>
 <title>����</title>
 <body>
 <?php
	$MyCar=new car ;                
 	$MyCar->set_color("�_�Ŧ�") ;
	echo "���l���C��O" . $MyCar->get_color() ;
 ?>
 </body>
 </html>
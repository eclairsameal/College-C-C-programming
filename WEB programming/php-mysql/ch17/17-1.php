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
 <title>物件</title>
 <body>
 <?php
	$MyCar=new car ;                
 	$MyCar->set_color("寶藍色") ;
	echo "車子的顏色是" . $MyCar->get_color() ;
 ?>
 </body>
 </html>
 <?php
	class car {
		var $color ;
		function car() {	
			$this->color="紅色" ;
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
			echo $n." 輪驅動" ;
		}
	}
 ?>
 <html>
 <title>物件的繼承</title>
 <body>
 <?php
	$JohnCar=new car ;
	$JohnCar->set_color("寶藍色") ;
	echo "John車子的顏色是 ".$JohnCar->get_color()."<p>" ;
	$MaryCar=new RV ;
	echo "Mary車子是 " ;
        $MaryCar->show_drive(4) ;
        echo ",顏色是".$MaryCar->get_color() ;
 ?>
 </body>
 </html>
 <?php
	class car {
		var $color ;
		function __construct() {	            
			$this->color="紅色" ;
		}
		function set_color($c){
			$this->color=$c ;
		}
		function get_color(){
			return $this->color ;
		}
	} 
 ?>
 <html>
 <title>物件的建構子</title>
 <body>
 <?php
	$ACar=new car ;
	$ACar->set_color("寶藍色") ;
	echo "A車顏色是".$ACar->get_color()."<p>" ;
	$BCar=new car ;
	echo "B車顏色是".$BCar->get_color() ; ;
 ?>
 </body>
 </html>
 <?php
	class car {
		var $color ;
		function __construct() {	            
			$this->color="����" ;
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
 <title>���󪺫غc�l</title>
 <body>
 <?php
	$ACar=new car ;
	$ACar->set_color("�_�Ŧ�") ;
	echo "A���C��O".$ACar->get_color()."<p>" ;
	$BCar=new car ;
	echo "B���C��O".$BCar->get_color() ; ;
 ?>
 </body>
 </html>
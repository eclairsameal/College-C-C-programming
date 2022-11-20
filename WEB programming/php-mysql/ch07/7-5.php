<?php
   class table {
     var $color ;
     function set_color($new_color){
         $this->color=$new_color ; }
     function show_color() {
         echo $this->color;
         echo "<br>\n" ; }
   }
?>
<html>   		
<title>клеє</title>	    		
<body>		    	
<?php    	      
   $T=new table() ;
   $D=new table() ;
   $T->set_color("Red") ;
   $D->set_color("Blue") ;
   echo "T table color is " ;
   $T->show_color() ;
   echo "D table coloe is " ;
   $D->show_color() ;
?>
</body>
</html>
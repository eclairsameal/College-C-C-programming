<html>
<title>variable_variable2</title>
<body>
<?php
        $name="A" ;
        $A[0]="Sunday" ;
        $A[1]="Monday" ;

        $Sunday="Holiday" ;
        $Monday="Busy day" ;

        echo ${$name}[0]."<br>\n" ;
        echo $${$name}[0]."<br>\n" ;
        echo ${${$name}[0]} ;
?>
</body>
</html>


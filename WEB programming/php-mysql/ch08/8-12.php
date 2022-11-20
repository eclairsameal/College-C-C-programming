<html>
<title>動態變數</title>
<body>
<?php 
    $name="John" ;
    $$name="Lee" ;
    echo "\$name= ".$name."<br>";
    echo '$$name= '.$$name."<br>" ;
    $name="Mary" ;
    $$name="Wang" ;
    echo "\$name= ".$name."<br>";
    echo '$$name= '.${$name}."<p>" ;
    $name="John" ;
    echo '$name 重新設為 John <br> $$name內容為' ; 
    echo $$name."<p>" ;
    echo "三個變數分別為: <br>";
    echo "\$name = $name <br>" ;
    echo "\$John = $John <br>" ;
    echo "\$Mary = $Mary " ;
?>
</body>
</html>
<html>
<title>�ʺA�ܼ�</title>
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
    echo '$name ���s�]�� John <br> $$name���e��' ; 
    echo $$name."<p>" ;
    echo "�T���ܼƤ��O��: <br>";
    echo "\$name = $name <br>" ;
    echo "\$John = $John <br>" ;
    echo "\$Mary = $Mary " ;
?>
</body>
</html>
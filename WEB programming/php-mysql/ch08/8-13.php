<html>
<title>�ʺA�ܼƼg�k</title>
<body>
<?php 
	$name="John" ;
	$$name="Lee" ;
    echo "1. $$name <br>" ;
	echo "2. ${$name} <br>" ;
    echo "3. ".$$name."<br>" ;
	echo "4. ".${$name} ;
?>
</body>
</html>

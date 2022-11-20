<?php
    session_start();
    session_register("A");
    session_register("B");
    $_SESSION['A']=10;
    $_SESSION['B']="Hello My ";
?>
<html>
<title>Session測試</title>
<body>
<?php
    echo "Session ID = ".session_id()."<p>";
    echo "運算前 <br>";
    echo "A = ".$_SESSION['A']."<br>";
    echo "B = ".$_SESSION['B']."<p>";
    $_SESSION['A']++;
    $_SESSION['B'].="Friend.";
    echo "運算後 <br>";
    echo "A = ".$_SESSION['A']."<br>";
    echo "B = ".$_SESSION['B'];
?>
</body>
</html>
<?php
    session_start();
    session_register("A");
    session_register("B");
    $_SESSION['A']=10;
    $_SESSION['B']="Hello My ";
?>
<html>
<title>Session����</title>
<body>
<?php
    echo "Session ID = ".session_id()."<p>";
    echo "�B��e <br>";
    echo "A = ".$_SESSION['A']."<br>";
    echo "B = ".$_SESSION['B']."<p>";
    $_SESSION['A']++;
    $_SESSION['B'].="Friend.";
    echo "�B��� <br>";
    echo "A = ".$_SESSION['A']."<br>";
    echo "B = ".$_SESSION['B'];
?>
</body>
</html>
<?php
    function message() {
         echo "��Ʀ^�ǤT�Ӽƭ�.<p>";
         return array("Hello", "My", "friend");
    }
?>
<html>
<title>�h�Ӧ^�ǭ�</title>
<body>
<?php
    list($msg1, $msg2, $msg3)=message();
    echo "�D�{�������h�ӰT���p�U<br>";
    echo "$msg1 $msg2 $msg3";
?>
</body>
</html>
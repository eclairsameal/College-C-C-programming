<?php
    Function MyFunction(){
	    echo "<< �b��Ƥ� >> <br>" ;
            echo "�]�w�e: <br>";
	    echo "A = $A <br>" ;
	    echo "B = $B <p>" ;
            $A=10 ;              // �ϰ��ܼ�
            $B=20 ;
            echo "�]�w��: <br>";
            echo "A = $A <br>" ;
            echo "B = $B <p>" ;
     }
?>
<html>
<title>�ϰ��ܼ�</title>
<body>
<?php
    $A = 1 ;                      // �����ܼ�
    $B = 2 ;                      // �����ܼ�
    MyFunction() ;
    echo "<< �b��ƥ~ >> <br> ";
    echo "A = $A <br>" ;
    echo "B = $B <p>" ;
?>
</body>
</html>

<html>
<title>����ﶵ</title>
<body>
<?php
	if (empty($_GET['score'])):
?>	
	<form action=<?php echo $_SERVER['PHP_SELF'] ?> method=get>
	�m�W <input type=text value="�п�J�m�W" name=user><p>
        �п�X�A�ҳ��w���B�� <br>
	<input type=radio value=1 name=score>�C�]<br>
	<input type=radio value=2 name=score>��a<br>
	<input type=radio value=3 name=score>�x�y<br>
	<input type=submit value="�e�X">
	<input type=reset value="���g"></form>
<?php
 	else :
		echo "Hi, ".$_GET['user']." <br> �A�̳��w���B�ʬO" ;
		switch ($_GET['score']){
			case 1:
			    echo "�C�]" ;
			    break ;
			case 2 :
	         	echo "��a" ;
			    break ;
			case 3 :
			    echo "�x�y" ;
			    break ;
			default:
			    echo "�S�����" ;
		}
	endif
?>
</body>
</html>

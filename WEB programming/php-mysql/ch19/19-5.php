<?php
   if (($_POST['name'] != "john") or ($_POST['passwd'] != "1234")):
?>
   <html>
   <title>�n�J�e��</title>
   <body>
   <B>����J�b���αK�X, �αb��,�K�X�����T </B><p>
   <form action=<?php echo $_SERVER['PHP_SELF'] ?> method=post>
   �b�� <input type=text name=name value="�п�J�b��" size=10><p>
   �K�X <input type=password name=passwd size=10><p>
   <input type=submit value=" �n�J ">
   <input type=reset  value=" �M�� ">
   </form>
   </body>
   </html>
<?php
   else:
     echo "�n�J���\ .....<p>";
     echo "�z�n�J���b���O ".$_POST['name']."<br>";
     echo "�z�ϥΪ��K�X�O ".$_POST['passwd'];
   endif
?>

<html>
<title>�P�_��</title>
<body>
<?php 
     if (empty($_GET["sex"])) {
?>
   <form action=<?php echo $_SERVER["PHP_SELF"] ?> method="get">
   �m�W:<input type=text name=n><br>
   �ʧO:<br>
   <input type=radio name=sex value=1>�k<br>
   <input type=radio name=sex value=2>�k<br>
   <input type=submit value="�e�X">
   <input type=reset  value="����">
   </form>
<?php
   }else{
      echo $_GET["n"];
      if ($_GET["sex"]==1){
          echo "���ͱz�n";
      }else{
          echo "�p�j�z�n";
      }
   }
?>
</body>
</html>
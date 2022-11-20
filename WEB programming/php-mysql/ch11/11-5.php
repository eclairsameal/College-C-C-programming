<html>
<title>判斷式</title>
<body>
<?php 
     if (empty($_GET["sex"])) {
?>
   <form action=<?php echo $_SERVER["PHP_SELF"] ?> method="get">
   姓名:<input type=text name=n><br>
   性別:<br>
   <input type=radio name=sex value=1>男<br>
   <input type=radio name=sex value=2>女<br>
   <input type=submit value="送出">
   <input type=reset  value="重填">
   </form>
<?php
   }else{
      echo $_GET["n"];
      if ($_GET["sex"]==1){
          echo "先生您好";
      }else{
          echo "小姐您好";
      }
   }
?>
</body>
</html>
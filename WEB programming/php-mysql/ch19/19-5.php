<?php
   if (($_POST['name'] != "john") or ($_POST['passwd'] != "1234")):
?>
   <html>
   <title>登入畫面</title>
   <body>
   <B>未輸入帳號或密碼, 或帳號,密碼不正確 </B><p>
   <form action=<?php echo $_SERVER['PHP_SELF'] ?> method=post>
   帳號 <input type=text name=name value="請輸入帳號" size=10><p>
   密碼 <input type=password name=passwd size=10><p>
   <input type=submit value=" 登入 ">
   <input type=reset  value=" 清除 ">
   </form>
   </body>
   </html>
<?php
   else:
     echo "登入成功 .....<p>";
     echo "您登入的帳號是 ".$_POST['name']."<br>";
     echo "您使用的密碼是 ".$_POST['passwd'];
   endif
?>

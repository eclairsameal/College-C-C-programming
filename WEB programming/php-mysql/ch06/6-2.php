<html>
<title>PHP標籤</title>
<body>
 PHP的四種寫法<p>
 <?php
     echo "利用< ?php   ? >的PHP寫法" ;
 ?>
 <hr><p>
 <script language="php">
     echo "利用Script的寫法" ;
 </script>
 <hr><p>
 <?
    echo "利用< ? ? >的PHP寫法" ; 
    echo "這種寫法必須將php.ini中的short_open_tags設定為On才可以使用" ;
 ?>
 <hr><p>
 <%
    echo "利用< % % >的PHP寫法<BR>" ;
    echo "這種寫法必須將php.ini中的asp_tags設定為On才可以使用" ;
 %>
</body>
</html>
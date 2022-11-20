<html>
<title>引入檔載入</title>
<body>
<?php
echo "引入檔案前 <p>";
require("NotExist.inc");
echo "引入檔案後";
?>
</body>
</html>

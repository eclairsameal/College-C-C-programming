
<div id="tabs" style="height:795px;overflow-y:auto;">
  <ul>
    <li><a href="#tabs-1">查詢所有書籍資訊</a></li>
    <li><a href="#tabs-2">查詢個人借書資訊</a></li>
    <li><a href="#tabs-3">更動使用者資料</a></li>
    <li><a href="#tabs-4">更動書籍資料</a></li>
  </ul>
  <div  id="tabs-1">
<?php
    include 'showQueryBook.php';
?>
</div>
<div id="tabs-2">
<?php
    include 'showMyBook.php';
?>
</div>
<div id="tabs-3">
<?php
    include 'userDB.php';
?>
</div>
<div id="tabs-4">
<?php
    include 'bookDB.php';
?>
</div>
</div>

 <div id="tabs" style="height:795px;overflow-y:auto;">
  <ul>
    <li><a href="#tabs-1">查詢所有書籍資訊</a></li>
    <li><a href="#tabs-2">查詢個人借書資訊</a></li>
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
</div>
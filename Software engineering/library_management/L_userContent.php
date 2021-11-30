
 <div id="tabs" style="height:795px;overflow-y:auto;">
  <ul>
    <li><a href="#tabs-1">查詢所有書籍資訊</a></li>
    <li><a href="#tabs-2">查詢個人借書資訊</a></li>
    <li><a href="#tabs-3">搜尋借書資訊</a></li>
    <li><a href="#tabs-4">協助借書</a></li>
    <li><a href="#tabs-5">協助還書</a></li>
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
    include 'seachBorrowedBook.php';
?>
  </div>
  <div id="tabs-4">
<?php
    include 'assisBorrowBook.php';
?>
  </div>
  <div id="tabs-5">
<?php
    include 'assisReturnBook.php';
?>
  </div>

</div>
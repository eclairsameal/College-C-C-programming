<?php
  if (isset($_POST['keyQueryBook'])) {
    $keyQueryBook=$_POST['keyQueryBook'];
    if($keyQueryBook==NULL)
      $keyQueryBook="";
  }
  else{
    $keyQueryBook="";
  }
?>
<form action="main.php" method="POST">
  <input type="text" name="keyQueryBook" value="<?php echo $keyQueryBook;?>" >
  <input type="submit" value="查詢">
</form>
<?php

	if($_SESSION['GML']=="G"){
    $sql = $user->searchAllBookInfo($keyQueryBook);
  }
  elseif ($_SESSION['GML']=="M") {
    $sql = $dbmer->searchAllBookInfo($keyQueryBook);
  }
  else{
    $sql = $librarian->searchAllBookInfo($keyQueryBook);
  }
	$result = mysqli_query($conn,$sql) or die('MySQL query error');
	if(mysqli_num_rows($result)==0){
		echo "無資料顯示";
	}
	else{
?>
  <center>
    <table class="table" width="90%">
      <th width="22%">書籍編號</th>
      <th width="34%">名稱</th>
      <th width="15%">出版社</th>
      <th width="12%">作者</th>
      <th width="9%">出版日期</th>
      <th width="8%">狀態</th>
<?php
    $j=0;
		while($row = mysqli_fetch_array($result)){
      $book = new Book($row[0],$row[1],$row[2],$row[3],$row[4],$row[5]);
      $j++;

?>
<?php
      if($j%2==0){
?>       
        <tr style="background-color:#CECDFF;">
<?php     
      }
      else{
?>          
       <tr  style="background-color:#EBEBFF;">
<?php
}
?>
          <td><?php echo $book->getBookID()?></td>
          <td><?php echo $book->getBookName()?></td>
          <td><?php echo $book->getPublishingHouse()?></td>
          <td><?php echo $book->getAuthor()?></td>
          <td><?php echo $book->getDate()?></td>
<?php 
      if($book->getState()==0){
?>        
          <td>未借出</td>
           
<?php
      }
      else{
          ?><td>已借出</td>     
<?php        
      }   
      
?>				
      </tr>
<?php
    }
?>
    </table>	
  </center>
<?php	
  }
?>

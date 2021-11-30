<?php
  if (isset($_POST['keyMyBook'])) {
    $keyMyBook=$_POST['keyMyBook'];
    if($keyMyBook==NULL)
      $keyMyBook="";
  }
  else{
    $keyMyBook="";
  }
?>
<form action="main.php" method="POST">
  <input type="text" name="keyMyBook" value="<?php echo $keyMyBook;?>" >
  <input type="submit" value="查詢">
</form>
<?php
  if($_SESSION['GML']=="G"){
    $sql = $user->seachAllBookMyself($keyMyBook);
  }
  elseif ($_SESSION['GML']=="M") {
    
    $sql = $dbmer->seachAllBookMyself($keyMyBook);
  }
  else{
    $sql = $librarian->seachAllBookMyself($keyMyBook);
  }
	$result = mysql_query($sql) or die('MySQL query error');
	if(mysql_num_rows($result)==0){
		echo "無資料顯示";
	}
	else{
?>
  <center>
    <table width="90%">
      <th width="15%">書籍編號</th>
      <th width="35%">名稱</th>
      <th width="16%">出版社</th>
      <th width="14%">作者</th>
      <th width="20%">出版日期</th>
<?php
    $j=0;
    while($row = mysql_fetch_array($result)){
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
      </tr>
<?php
    }
?>
    </table>  
  </center>
<?php 
  }
?>
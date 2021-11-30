<?php
  if (isset($_POST['keyBorrowedBook'])) {
    $keyBorrowedBook=$_POST['keyBorrowedBook'];
    if($keyBorrowedBook==NULL)
      $keyBorrowedBook="";
  }
  else{
    $keyBorrowedBook="";
  }
?>
<form action="main.php" method="POST">
  <input type="text" name="keyBorrowedBook" value="<?php echo $keyBorrowedBook;?>" >
  <input type="submit" value="查詢">
</form>

<?php
	$sql=$librarian->searchAllBorrowedBook($keyBorrowedBook);
	$result = mysql_query($sql) or die('MySQL query error');
	if(mysql_num_rows($result)==0){
		echo "無資料顯示";
	}
	else{
?>
  <center>
    <table class="table" width="90%">
      <th>使用者</th>
      <th>借閱書籍</th>
      <th>借閱時間</th>
      <th>歸還期限</th>
<?php
    $j=0;
	while($row = mysql_fetch_array($result)){
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
      if(strtotime(date("Y-m-d"))>strtotime($row[3])){
?>
          <td style="color:#FA0300;"><?php echo $row[1]?></td>
          <td style="color:#FA0300;"><?php echo $row[0]?></td>
          <td style="color:#FA0300;"><?php echo $row[2]?></td>
          <td style="color:#FA0300;"><?php echo $row[3]?></td>  
<?php        
      }
      else{
?>
		      <td><?php echo $row[1]?></td>
          <td><?php echo $row[0]?></td>
          <td><?php echo $row[2]?></td>
          <td><?php echo $row[3]?></td>   
<?php
      }
    }
?>
    </table>	
  </center>
<?php	
}
?>
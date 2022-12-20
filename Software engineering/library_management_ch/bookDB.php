<?php
  if (isset($_POST['keyAllBook'])) {
    $keyAllBook=$_POST['keyAllBook'];
    if($keyAllBook==NULL)
      $keyAllBook="";
  }
  else{
    $keyAllBook="";
  }
?>
<form action="main.php" method="POST">
  <input type="text" name="keyAllBook" value="<?php echo $keyAllBook;?>" >
  <input type="submit" value="查詢">
</form>
<button type="button" onclick="self.location.href='addBook.php'">新增書籍</button>
<?php
  $sql = $dbmer->seachAllBook($keyAllBook);

	$result = mysqli_query($conn,$sql) or die('MySQL query error');
	if(mysqli_num_rows($result)==0){
		echo "無資料顯示";
?>
    
<?php
	}
	else{
?>
    <center>
      <table width="90%">
        <th width="10%">書籍ID</th>
        <th width="35%">書籍名稱</th>
        <th width="15%">出版社</th>
        <th width="15%">作者</th>
        <th width="15%">出版日期</th>
        <th width="5%">修改</th>
        <th width="5%">刪除</th>
<?php
      $j=0;
      while($row = mysqli_fetch_array($result)){
        $book = new Book($row[0],$row[1],$row[2],$row[3],$row[4],$row[5]);
        $j++;
?>
        <form action="deleteBook.php" method="POST">
        
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
            <td><?php echo $book->getBookID()?><input type="hidden" name="book_id" value="<?php echo $book->getBookID();?>"></td>
            <td><?php echo $book->getBookName()?></td>   
            <td><?php echo $book->getPublishingHouse();?></td>
            <td><?php echo $book->getAuthor();?></td>
            <td><?php echo $book->getDate();?></td>
            <td><input class="button" type='submit' formaction='modifyBook.php' value='修改'></td> 
            <td><input class="button" type='submit' value='刪除'></td> 
          </tr>
        </form>
<?php
      }
?>
      </table>  
    </center>
<?php 
    }
?>

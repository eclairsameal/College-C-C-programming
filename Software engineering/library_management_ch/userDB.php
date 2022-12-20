<?php
  if (isset($_POST['keyAllUser'])) {
    $keyAllUser=$_POST['keyAllUser'];
    if($keyAllUser==NULL)
      $keyAllUser="";
  }
  else{
    $keyAllUser="";
  }
?>
<form action="main.php" method="POST">
  <input type="text" name="keyAllUser" value="<?php echo $keyAllUser;?>" >
  <input type="submit" value="查詢">
</form>
<button type="button" onclick="self.location.href='addUser.php'">新增使用者</button>
<?php
  $sql = $dbmer->seachAllUser($keyAllUser);

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
        <th width="15%">使用者ID</th>
        <th width="15%">使用者名稱</th>
        <th width="20%">身分</th>
        <th width="20%">密碼</th>
        <th width="10%">修改</th>
        <th width="10%">刪除</th>
<?php
      $j=0;
      while($row = mysqli_fetch_array($result)){
        $user = new User($row[0],$row[1],$row[2],$row[3]);
        $j++;
?>
        <form action="deleteUser.php" method="POST">
        
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
            <td><?php echo $user->getUserID()?><input type="hidden" name="user_id" value="<?php echo $user->getUserID();?>"></td>
            <td><?php echo $user->getUserName()?></td>
<?php
            if($user->getGML()=="G"){
?>
              <td>一般使用者</td>
<?php
            }
            else if($user->getGML()=="M"){
?>
              <td>資料庫管理員</td>
<?php
            }
            else{
?>
              <td>圖書館館員</td>
<?php
            }
?>            
            <td><?php echo $user->getPW();?></td>
            <td><input class="button" type='submit' formaction='modifyUser.php' value='修改'></td> 
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

<html>
<head>
  <title> Online Store </title>
  <meta charset="UTF-8">
</head>
<body>
<?php
  $link = mysql_connect("localhost", "root", "mysql123");
  if (!$link) {
    print "Error - Could not connect to MySQL";
    exit;
  } // 建立連線
  $db = mysql_select_db("business");
  if (!$db) {
    print "Error - Could not select the web_design database";
    exit;
  } // 選擇 database

  $name = $_POST['name'];
  $address = $_POST['address'];
  $city = $_POST['city'];
  $p_n = $_POST['p_n'];
  $product0 = $_POST['product0'];
  $product1 = $_POST['product1'];
  $product2 = $_POST['product2'];
  $product3 = $_POST['product3'];
  $product4 = $_POST['product4'];
  $payment = $_POST['payment'];   
  if ($product0 == "") {$product0 = 0;}
  if ($product1 == "") {$product1 = 0;}
  if ($product2 == "") {$product2 = 0;}
  if ($product3 == "") {$product3 = 0;}
  if ($product4 == "") {$product4 = 0;}
  $product_array = array($product0, $product1, $product2, $product3, $product4);

  if ($name != "" && $address != "" && $city != "" && $p_n != ""){
    // 新增 customer 資料
    $customer_query = "insert into customer values ('$name', '$address', '$city', '$p_n')";
    $result = mysql_query($customer_query); // 執行 SQL 指令(insert datd)
    
    $query = "select * from porder";
    $result = mysql_query($query); // 執行 SQL 指令(select)
    $allrow = mysql_num_rows($result); // database 訂單數
    $allrow++;
    $totalcost = 0; // 總價
    for ($i=0; $i < 5; $i++) { 
      switch ($i) {
        case '0': {
          $totalcost += ($product_array[$i] * 1390);
          break;
        }   
        case '1': {
          $totalcost += ($product_array[$i] * 1390);
          break;
        } 
        case '2': {
          $totalcost += ($product_array[$i] * 1790); 
          break;
        } 
        case '3': {
          $totalcost += ($product_array[$i] * 1890);
          break;
        } 
        case '4': {
          $totalcost += ($product_array[$i] * 1590);
          break;
        } 
      }
    }
    // 新增 porder 資料
    $porder_query = "insert into porder values ('p-$allrow', '$totalcost', '$name', '$payment')";
    $result = mysql_query($porder_query); // 執行 SQL 指令(insert datd)
    // 新增 product 資料
    $product_query = "insert into product values ('p-$allrow', '$product_array[0]', '$product_array[1]', '$product_array[2]','$product_array[3]','$product_array[4]')";
    $result = mysql_query($product_query); // 執行 SQL 指令(insert datd)
  }
  
    //$query = "select * from porder,product where porder_number=product_ordernumber AND porder_number='p-$allrow'";
    //$result = mysql_query($query); // 執行 SQL 指令(select)
    
    print"<table>
      <tr><td><h1>Order Form </h1></td></tr>
      <tr><td>Order Number: p-$allrow </td></tr>
      <tr><td>Name: $name </td></tr>
      <tr><td>Total: $totalcost </td></tr>
      <tr><td>Payment: $payment </td></tr>
    </table>";

    print"<table border = \"3\">
     <tr align = \"center\">
        <td><b>Product</b></td> <td><b>Price</b></td> <td><b>Quantity</b></td>
      </tr>
      <tr>
        <td>LIGHTNING RETURNS FINAL FANTASY XIII</td> <td>NT $1390 </td> <td>$product_array[0]</td>  
      </tr>
      <tr>
        <td>Assassin's Creed IV: Black Flag</td> <td>NT $1390 </td> <td>$product_array[1]</td>
      </tr>
      <tr>
        <td>Call of Duty: Ghosts</td> <td>NT $1790 </td> <td>$product_array[2]</td>
      </tr>
      <tr>
        <td>Dead or Alive 5</td> <td>NT $1890 </td> <td>$product_array[3]</td> 
      </tr>
      <tr>
        <td>Far Cry 3</td> <td>NT $1590 </td> <td>$product_array[4]</td>
      </tr>
    </table>";
    print"<h1>Thank Order</h1>";

?>
</body>
</html>
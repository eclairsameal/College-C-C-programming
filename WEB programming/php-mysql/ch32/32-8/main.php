<?php

/*mysql --user=root --password=your_password */


include("shoppingcart.php"); 
$cart = new Cart;
$table="shopping";

/* 查詢並顯示所有存貨資料表中的資訊 */
    $query = "SELECT * FROM inventory";
    $invResult = mysql_query($query); 
    if (!($invResult)) { 
       echo "查詢失敗<br>";
       exit;
    } 
    echo "以下產品可供訂購︰";
    echo "<table border=0>";
    echo "<tr><td bgcolor=#AACCFF>產品編號</td><td bgcolor=#AACCFF>產品名稱</td><td bgcolor=#AACCFF>單價</td>";
    echo "<td bgcolor=#AACCFF>剩餘數量</td><td bgcolor=#AACCFF>產品描述</td><td bgcolor=#AACCFF>放入購物車</td></tr>";
    while($row_inventory = mysql_fetch_object($invResult)) {
    echo "<tr><td bgcolor=#AACCFF>".$row_inventory->id."</td>"; 
    echo "<td bgcolor=#AACCFF>".$row_inventory->product."</td>"; 
    echo "<td bgcolor=#AACCFF>".$row_inventory->price."</td>"; 
    echo "<td bgcolor=#AACCFF>".$row_inventory->quantity."</td>"; 
    echo "<td bgcolor=#AACCFF>".$row_inventory->description."</td>";
    echo "<td bgcolor=#AACCFF><a href='additem.php?product=".$row_inventory->product."'><img border='0' src='cart.gif' width='81' height='17'></a></td></tr>"; 
    }
    echo "</table>";
    echo "<BR>購物車中貨品的數量︰".$cart->quant_items($table, $session);
    echo "<br><br><a href='clearcart.php'><img border='0' src='car.gif'></a>清空購物車";
?>
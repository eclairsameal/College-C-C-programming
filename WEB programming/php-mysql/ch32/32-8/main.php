<?php

/*mysql --user=root --password=your_password */


include("shoppingcart.php"); 
$cart = new Cart;
$table="shopping";

/* �d�ߨ���ܩҦ��s�f��ƪ�����T */
    $query = "SELECT * FROM inventory";
    $invResult = mysql_query($query); 
    if (!($invResult)) { 
       echo "�d�ߥ���<br>";
       exit;
    } 
    echo "�H�U���~�i�ѭq�ʡJ";
    echo "<table border=0>";
    echo "<tr><td bgcolor=#AACCFF>���~�s��</td><td bgcolor=#AACCFF>���~�W��</td><td bgcolor=#AACCFF>���</td>";
    echo "<td bgcolor=#AACCFF>�Ѿl�ƶq</td><td bgcolor=#AACCFF>���~�y�z</td><td bgcolor=#AACCFF>��J�ʪ���</td></tr>";
    while($row_inventory = mysql_fetch_object($invResult)) {
    echo "<tr><td bgcolor=#AACCFF>".$row_inventory->id."</td>"; 
    echo "<td bgcolor=#AACCFF>".$row_inventory->product."</td>"; 
    echo "<td bgcolor=#AACCFF>".$row_inventory->price."</td>"; 
    echo "<td bgcolor=#AACCFF>".$row_inventory->quantity."</td>"; 
    echo "<td bgcolor=#AACCFF>".$row_inventory->description."</td>";
    echo "<td bgcolor=#AACCFF><a href='additem.php?product=".$row_inventory->product."'><img border='0' src='cart.gif' width='81' height='17'></a></td></tr>"; 
    }
    echo "</table>";
    echo "<BR>�ʪ������f�~���ƶq�J".$cart->quant_items($table, $session);
    echo "<br><br><a href='clearcart.php'><img border='0' src='car.gif'></a>�M���ʪ���";
?>
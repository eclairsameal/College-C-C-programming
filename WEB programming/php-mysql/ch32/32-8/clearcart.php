<?php
include("shoppingcart.php");
$cart = new Cart;
$table="shopping";
$cart->clear_cart($table, $session);
echo "購物車中貨品的數量︰".$cart->num_items($table, $session);
echo "<form action='main.php'>";
echo "<input type=submit value='繼續購物'>";
echo "</form>";
?>
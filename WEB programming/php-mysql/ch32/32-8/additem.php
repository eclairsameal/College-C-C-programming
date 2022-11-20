<?php
include("shoppingcart.php");
$cart = new Cart;
$table="shopping";
echo "您的購物清單︰<br>";
$cart->add_item($table,$session,$product,'1');
$cart->display_contents($table, $session);
echo "<br>您的購物總金額︰".$cart->cart_total($table, $session);
echo "<br><form action='main.php'>";
echo "<input type=submit value='繼續購物'>";
echo "</form>";
?>
<?php
include("shoppingcart.php");
$cart = new Cart;
$table="shopping";
$cart->clear_cart($table, $session);
echo "�ʪ������f�~���ƶq�J".$cart->num_items($table, $session);
echo "<form action='main.php'>";
echo "<input type=submit value='�~���ʪ�'>";
echo "</form>";
?>
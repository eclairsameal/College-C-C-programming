<?php
include("shoppingcart.php");
$cart = new Cart;
$table="shopping";
echo "�z���ʪ��M��J<br>";
$cart->add_item($table,$session,$product,'1');
$cart->display_contents($table, $session);
echo "<br>�z���ʪ��`���B�J".$cart->cart_total($table, $session);
echo "<br><form action='main.php'>";
echo "<input type=submit value='�~���ʪ�'>";
echo "</form>";
?>
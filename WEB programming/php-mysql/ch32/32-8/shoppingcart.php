<?php
    if (!$session && !$s) { 
        $s = md5(uniqid(rand())); 
        SetCookie("session", "$s", time() + 14400); 
    }

/* �ˬd�O�_�� seesion, �p�G�S�����ͤ@�� MD5 ���ߤ@ id, �çQ�� cookie �s�J $s ���C
�åB�]�w��s�b�ɶ��� 14400 sec �]�N�O 4 �p�� */ 


    $mysql_link = mysql_connect("127.0.0.1", "root", "test"); 
    if (!($mysql_link)) { 
       echo "�s����Ʈw����<br>";
       exit;
    } 
    $mysql_select=mysql_select_db("shopper", $mysql_link);
    if (!($mysql_select)) { 
       echo "�}�Ҹ�Ʈw����<br>";
       exit;
    }  

/* �ʪ��� Class */
    
    class Cart { 
        function check_item($table, $session, $product) { 
            $query = "SELECT * FROM $table WHERE session='$session' AND product='$product' "; 
            $result = mysql_query($query); 
             
            if(!$result) { 
                return 0; 
            } 
            $numRows = mysql_num_rows($result); 
            if($numRows == 0) { 
                return 0; 
            } else { 
                $row = mysql_fetch_object($result); 
                return $row->quantity; 
            } 
        } 

        function add_item($table, $session, $product, $quantity) { 
            $qty = $this->check_item($table, $session, $product); 
            if($qty == 0) { 
                $query = "INSERT INTO $table (session, product, quantity) VALUES "; 
                $query .= "('$session', '$product', '$quantity') "; 
                mysql_query($query); 
            } else { 
                $quantity += $qty; 
                $query = "UPDATE $table SET quantity='$quantity' WHERE session='$session' AND "; 
                $query .= "product='$product' "; 
                mysql_query($query);
            } 
        } 
         
        function delete_item($table, $session, $product) { 
            $query = "DELETE FROM $table WHERE session='$session' AND product='$product' "; 
            mysql_query($query); 
        } 
         
        function modify_quantity($table, $session, $product, $quantity) { 
            $query = "UPDATE $table SET quantity='$quantity' WHERE session='$session' "; 
            $query .= "AND product='$product' "; 
            mysql_query($query); 
        } 
         
        function clear_cart($table, $session) { 
            $query = "DELETE FROM $table WHERE session='$session' "; 
            mysql_query($query); 
        } 
         
        function cart_total($table, $session) { 
            $query = "SELECT * FROM $table WHERE session='$session' "; 
            $result = mysql_query($query); 
            if(mysql_num_rows($result) > 0) { 
                while($row = mysql_fetch_object($result)) { 
                    $query = "SELECT price FROM inventory WHERE product='$row->product' "; 
                    $invResult = mysql_query($query); 
                    $row_price = mysql_fetch_object($invResult); 
                    $total += ($row_price->price * $row->quantity); 
                } 
            } 
            return $total; 
        } 
         
        function display_contents($table, $session) { 
            $count = 0; 
            $query = "SELECT * FROM $table WHERE session='$session' ORDER BY id "; 
            $result = mysql_query($query); 
            echo "<table border=0>";
            echo "<tr><td bgcolor=#AACCFF>���~�s��</td><td bgcolor=#AACCFF>���~�W��</td><td bgcolor=#AACCFF>���</td>";
            echo "<td bgcolor=#AACCFF>�ʶR�ƶq</td><td bgcolor=#AACCFF>�涵�p�p</td><td bgcolor=#AACCFF>���~�y�z</td></tr>";
            while($row = mysql_fetch_object($result)) { 
                $query = "SELECT * FROM inventory WHERE product='$row->product' "; 
                $result_inv = mysql_query($query); 
                $row_inventory = mysql_fetch_object($result_inv); 
                $contents["product"][$count] = $row_inventory->product; 
                $contents["price"][$count] = $row_inventory->price; 
                $contents["quantity"][$count] = $row->quantity; 
                $contents["total"][$count] = ($row_inventory->price * $row->quantity); 
                $contents["description"][$count] = $row_inventory->description;
              
                echo "<tr><td bgcolor=#AACCFF>".$row_inventory->id."</td>"; 
                echo "<td bgcolor=#AACCFF>".$row_inventory->product."</td>"; 
                echo "<td bgcolor=#AACCFF>".$row_inventory->price."</td>"; 
                echo "<td bgcolor=#AACCFF>".$row->quantity."</td>"; 
                echo "<td bgcolor=#AACCFF>".$contents["total"][$count]."</td>"; 
                echo "<td bgcolor=#AACCFF>".$row_inventory->description."</td></tr>";

                $count++; 
            } 
    echo "</table>";
            $total = $this->cart_total($table, $session); 
            $contents["final"] = $total; 
            return $contents; 
        } 
         
        function num_items($table, $session) { 
            $query = "SELECT * FROM $table WHERE session='$session' "; 
            $result = mysql_query($query); 
            $num_rows = mysql_num_rows($result); 
            return $num_rows; 
        } 
         
        function quant_items($table, $session) { 
            $quant = 0; 
            $query = "SELECT * FROM $table WHERE session='$session' "; 
            $result = mysql_query($query); 
            while($row = mysql_fetch_object($result)) { 
                $quant += $row->quantity; 
            } 
            return $quant; 
        } 
    } 
?>
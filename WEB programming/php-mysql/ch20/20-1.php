<?php
      $date="2003-01-31";
      if (ereg ("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})", $date, $regs)) {
             echo "$regs[3] / $regs[2] / $regs[1] <p>";
             echo "$regs[0] <p>";
             echo "$regs[1]�~ $regs[2]�� $regs[3]��";
      } else {
            echo "���X�k������榡�G$date";
       }
?>

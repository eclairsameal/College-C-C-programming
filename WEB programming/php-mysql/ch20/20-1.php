<?php
      $date="2003-01-31";
      if (ereg ("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})", $date, $regs)) {
             echo "$regs[3] / $regs[2] / $regs[1] <p>";
             echo "$regs[0] <p>";
             echo "$regs[1]年 $regs[2]月 $regs[3]日";
      } else {
            echo "不合法的日期格式：$date";
       }
?>

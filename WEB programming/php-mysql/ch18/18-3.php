<?php
    $nowcnt=$_COOKIE[cnt];
    $nowcnt++;
    setcookie("cnt",$nowcnt,time()+60);
    echo "您是第 $nowcnt 次光臨本站";
?>
<?php
    $nowcnt=$_COOKIE[cnt];
    $nowcnt++;
    setcookie("cnt",$nowcnt,time()+60);
    if ($nowcnt>=5) setcookie("cnt",$nowcnt,time()-60);
    echo "�z�O�� $nowcnt �����{����";
?>
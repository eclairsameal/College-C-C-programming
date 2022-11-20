<html><title)伺服器運作狀況即時顯示表</title>         
<table border=0><tr><td bgcolor=litered width=100% colspan="9"><p align="center"><b>伺服器運作狀況即時顯示表</B><center>         
<?php
set_time_limit(0);         
echo strftime ("%Y 年 %m 月 %d 日.\n");
?> 
</td></tr>       
<tr><td bgcolor="#COCOCO">IP 位址</td><td bgcolor="#COCOCO">偵測時間</td>         
<td bgcolor="#COCOCO">FTP  </td>         
<td bgcolor="#COCOCO">Telnet</td><td bgcolor="#COCOCO">SMTP   </td>         
<td bgcolor="#COCOCO">DNS</td><td bgcolor="#COCOCO">HTTP   </td>
<td bgcolor="cococo">POP3</td><td bgcolor="#COCOCO">Finger  </td>
</td></center>



<?php
//此程式必須啟動 php_sockets.dll
$port=array(22,23,25,53,80,110,79);
$filename="host.txt";
         $fl=file($filename);
         for($i=0;$i<count($fl);$i++){
          $a=preg_split('/\//',$fl[$i]);
          $name[]=$a[0];
          $ip[]=$a[1];
          $yn[]=$a[2];
         }     
         for($j=0;$j<count($fl);$j++){
          echo "<tr><td bgcolor=yellow> 
          $name[$j]</td><td bgcolor=liteblue>".date("h:i:s A")."</td>";
          for ($i=0;$i<7;$i++){
          if (substr($yn[$j],$i,1)=="1") {
            @$result[$i]=fsockopen($ip[$j],$port[$i],$serno,$errstr,1);
            if($result[$i]){
              echo "<td bgcolor=litegreen>正常</td>";
            } else {
              echo "<td bgcolor=red>失敗</td>";
            }
           } else {
            echo "<td bgcolor=litegreen>N/A</td>";
           }
          } 
         echo "</tr>";
         }  
?>




<tr><td bgcolor=litegray width=100% colspan="9">備註:<br>

1.本檢測表為本單位對各單位伺服器之簡易偵測, 不代表該伺服器一定能正常運作<br>
2.N/A 代表未檢測.<br></td></tr></table>
</html>
    
<html><title)���A���B�@���p�Y����ܪ�</title>         
<table border=0><tr><td bgcolor=litered width=100% colspan="9"><p align="center"><b>���A���B�@���p�Y����ܪ�</B><center>         
<?php
set_time_limit(0);         
echo strftime ("%Y �~ %m �� %d ��.\n");
?> 
</td></tr>       
<tr><td bgcolor="#COCOCO">IP ��}</td><td bgcolor="#COCOCO">�����ɶ�</td>         
<td bgcolor="#COCOCO">FTP  </td>         
<td bgcolor="#COCOCO">Telnet</td><td bgcolor="#COCOCO">SMTP   </td>         
<td bgcolor="#COCOCO">DNS</td><td bgcolor="#COCOCO">HTTP   </td>
<td bgcolor="cococo">POP3</td><td bgcolor="#COCOCO">Finger  </td>
</td></center>



<?php
//���{�������Ұ� php_sockets.dll
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
              echo "<td bgcolor=litegreen>���`</td>";
            } else {
              echo "<td bgcolor=red>����</td>";
            }
           } else {
            echo "<td bgcolor=litegreen>N/A</td>";
           }
          } 
         echo "</tr>";
         }  
?>




<tr><td bgcolor=litegray width=100% colspan="9">�Ƶ�:<br>

1.���˴���������U�����A����²������, ���N��Ӧ��A���@�w�ॿ�`�B�@<br>
2.N/A �N���˴�.<br></td></tr></table>
</html>
    
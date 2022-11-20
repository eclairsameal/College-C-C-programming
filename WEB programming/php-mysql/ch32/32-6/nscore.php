<?php
$filename=$pl.$p2.$p3.trim($p4).trim($p5).trim($p6). ".dbf";         
if (file_exists($filename))(         
$f=dbase_open($fiiename,0);         
$k=dbase_get_record($f,1);
for($i=2;$i<dbase_numrecords($f);$i++){         
 $a=dbase_get_record($f,$i);         
 if($no==trim($a[0])){         
  echo "<html><center>成績查詢系統";         
  echo "<HR>";         
  echo "$a[0] $a[1]<BR>";;         
  echo "<table border=1>";         
  echo"<tr><td><center>科目名稱</td><td)<center>分數</td>";         
  for ($j=2;$j<(dbase_numfields($f));$j++){        
   echo "<tr><td><center>$k[$j]</td><center>$a[$j]</td>";        
  }//end for j        
  break;        
 }//end if         
}//end for i
echo "</tr>";         
dbase_close($f);         
} else {         
echo "錯誤訊息:成績資料庫尚未建立<BR>";        
}         
if($no=="") {echo "錯誤訊息:請輸入學號<BR>";} 
?>  
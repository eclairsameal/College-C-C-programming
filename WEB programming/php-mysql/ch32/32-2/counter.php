<?
function counter ($filename) {
if (!$fp=fopen($filename, "a+")) $count=0;
$count=fgets($fp,10);
$count=$count+1;
fclose($fp);
for ($i=0; $i<strlen($count);$i++)
{
$substring=substr($count,$i,1);
printf("<img src='%s.gif'>",$substring);
}
$fp=fopen($filename, "w");
$fc=fputs($fp, $count);
fclose($fp);
}
?>
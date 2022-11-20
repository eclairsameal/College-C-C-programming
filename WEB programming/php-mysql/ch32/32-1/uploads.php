<?php
if ($uploadedfile<>"none") {
 if (!copy($uploadedfile, "$uploadedfile_name")) {
 echo "<font face='arial' size='2'> $name 檔案上傳失敗 ,<br>";
 echo "也可能是檔案太大<br>";
 echo "請使用 back 按鍵再試一次";
 } else {
 echo "<font face='arial' size='2'>檔案上傳成功 !<br>";
 echo "檔案型態：$uploadedfile_type <BR>";
 echo "檔案大小：$uploadedfile_size <BR>";
 echo "檔案名稱：$uploadedfile_name <BR>";
 echo "檔案說明：$description <BR>";
 }
}
?>

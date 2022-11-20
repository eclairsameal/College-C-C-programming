<?php 
    
    try { 
         $filename="abc.php";
         if (!file_exists($filename)){
            throw new Exception("發生例外錯誤: 檔案不存在!!"); 
         } 
     } catch (Exception $e) { 
        echo $e->getMessage(); 
        exit();
     } 
     echo "程式繼續執行";
?>
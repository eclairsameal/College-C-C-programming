<?php 
    class myFileNotExist extends Exception{
         function __construct($f){
              echo "發生例外錯誤: 檔案 ".$f." 不存在!!";
         }
    }
    class myEmptyFile extends Exception{
          function __construct($f){
              echo "發生例外錯誤: 檔案 ".$f." 是空檔案!!";
          }
    }
    function checkfile($filename){
         try {
             if (!file_exists($filename)){
                throw new myFileNotExist($filename); 
             } 
             if (filesize("empty.txt")==0) {
                throw new myEmptyFile($filename);
             }
         } catch (myFileNotExist $e) { 
             echo $e->getMessage(); 
         } catch (myEmptyFile $e) { 
             echo $e->getMessage(); 
         }
     }
     echo "<p>測試 abc.txt 此檔案應該不存在 <br>";
     checkfile("abc.txt");
     echo "<p>測試 empty.txt 此檔案存在, 但是是空檔案 <br>";
     checkfile("empty.txt"); 
?>
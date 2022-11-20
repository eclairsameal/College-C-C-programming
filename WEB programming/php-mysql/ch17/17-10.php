<?php 
    class myFileNotExist extends Exception{
         function __construct($f){
              echo "�o�ͨҥ~���~: �ɮ� ".$f." ���s�b!!";
         }
    }
    class myEmptyFile extends Exception{
          function __construct($f){
              echo "�o�ͨҥ~���~: �ɮ� ".$f." �O���ɮ�!!";
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
     echo "<p>���� abc.txt ���ɮ����Ӥ��s�b <br>";
     checkfile("abc.txt");
     echo "<p>���� empty.txt ���ɮצs�b, ���O�O���ɮ� <br>";
     checkfile("empty.txt"); 
?>
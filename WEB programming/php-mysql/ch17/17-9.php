<?php 
    
    try { 
         $filename="abc.php";
         if (!file_exists($filename)){
            throw new Exception("�o�ͨҥ~���~: �ɮפ��s�b!!"); 
         } 
     } catch (Exception $e) { 
        echo $e->getMessage(); 
        exit();
     } 
     echo "�{���~�����";
?>
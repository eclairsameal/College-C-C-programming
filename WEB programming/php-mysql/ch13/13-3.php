<html>
<title>�h���}�C</title>
<body>
<?php
$A = array(
         0 => array(          //�]�w��0�C
                  0 => "00" ,
                  1 => "01" ,
                  2 => "02"
                  ) ,         
         1 => array(          //�]�w��1�C
                  0 => "10",
                  1 => "11",
                  2 => "12"
                  ),
         2 => array(           //�]�w��2�C
                  0 => "20",
                  1 => "21",
                  2 => "22"
                  )
       ) ;
echo "��ܰ}�C���e<br>";
for ($B=0; $B<=2; $B++){        
   for ($c=0; $c<=2; $c++)      
      echo $A[$B][$c].", " ;       
echo "<br>" ;
   }
?>
</body>
</html>

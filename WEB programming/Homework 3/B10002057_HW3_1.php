<html>
<head>
  <title>Scores</title>
</head>
<body>
<?php
  $id = $_POST['id'];
  $name = $_POST['name'];
  $ch0 = $_POST['ch1'];
  $ch1 = $_POST['ch2'];
  $ch2 = $_POST['ch3'];
  $ch3 = $_POST['ch4'];
  $ch4 = $_POST['ch5'];
  $ch5 = $_POST['ch6'];
  $ch6 = $_POST['ch7'];
  $ch7 = $_POST['ch8'];
  $ch8 = $_POST['ch9'];
  $ch9 = $_POST['ch10'];
  
  $answer_array = array(0,0,0,0,0,0,0,0,0,0);
  $right = 0;

  if($ch0=="博麗霊夢"){$answer_array[0]=1; $right++;}
  if($ch1=="十六夜咲夜"){$answer_array[1]=1; $right++;}
  if($ch2=="風見幽香"){$answer_array[2]=1; $right++;}
  if($ch3=="藤原妹紅"){$answer_array[3]=1; $right++;}
  if($ch4=="四季映姬·亞瑪撒那度"){$answer_array[4]=1; $right++;}
  if($ch5=="古明地戀"){$answer_array[5]=1; $right++;}
  if($ch6=="八坂神奈子"){$answer_array[6]=1; $right++;}
  if($ch7=="宮古芳香"){$answer_array[7]=1; $right++;}
  if($ch8=="愛莉絲·瑪嘉特羅伊德"){$answer_array[8]=1; $right++;}
  if($ch9=="鈴仙·優曇華院·稻葉"){$answer_array[9]=1; $right++;}
  $solution_array = array('A','D','C','A','B','C','A','B','B','C');

  print '<table border="1">';
  print "<tr><td>Student No</td> <td>Student Name</td> <td>Total Score</td></tr>";
  $Score = $right*10;
  print "<tr><td>$id</td> <td>$name</td> <td>$Score</td></tr>";
  print "</table>";
  print '<table border="1">';
    echo "<tr><td>Right</td> <td>Wrong</td>";
      for($i=0; $i<10; $i++){
        if($answer_array[$i]==0){
          $out_i = $i + 1;
          echo "<td>Question $out_i</td>";
        }
      }
    echo "</tr>"; 
    $wrong = 10-$right;
    echo "<tr><td>$right</td> <td>$wrong</td>";   
      for($i=0; $i<10; $i++){
        if($answer_array[$i]==0){
          echo "<td>$solution_array[$i]</td>";
        }
      }
    echo "</tr>";
  print "</table>";
?>
</body>
</html>
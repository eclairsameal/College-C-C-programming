<html>
<head>
  <title>Lucky Wheel</title>
  <meta charset="UTF-8">
</head>
<body>

  
<?php
  $plays = $_POST['plays'];
  $now_plays = $_POST['now_plays'];
  $pay = $_POST['pay'];
  //echo "plays: $plays</br>";
  //echo "pay: $pay</br>";
  //echo "now_plays: $now_plays</br>";

  $tdcolor = array("white", "white", "white", "white", "white", "white", "white", "white",
                  "white", "white", "white", "white", "white", "white", "white");

  if ($now_plays!=0 && $now_plays<=$plays) {
    $lucky = rand(0, 14);
    $tdcolor[$lucky] = "orange";
  }

  print'<table border = "1"  width = "250" height = "300">';
    print'<tr align = "center">';
      print"<td>";
        print'<table border = "1" cellpadding = "5">';
        $nu = 0;
        for ($i=0; $i < 5; $i++) { 
          echo"<tr>";
          echo "<td align = \"center\" bgcolor = \"$tdcolor[$nu]\">$nu</td>"; $nu++;
          for ($j=0; $j < 5; $j++) { 
            if ($j==$i) {echo"<td align = \"center\">$nu</td bgcolor = \"$tdcolor[$nu]\">"; $nu++;}
            else{echo"<td bgcolor = \"black\">&nbsp;&nbsp;&nbsp;</td>";}
          }
          echo"<td align = \"center\" bgcolor = \"$tdcolor[$nu]\">$nu</td>"; $nu++;
        }
        print"</table>";
        echo "</br>";

        if ($now_plays!=0 && $now_plays<=$plays) {
          switch($lucky) {
            case 0: { print"Your roll is 0. You lost 150."; $pay -= 150;} break;
            case 1: { print"Your roll is 1. You won 100."; $pay += 100;} break;
            case 2: { print"Your roll is 2. You lost 100."; $pay -= 100;} break;
            case 3: { print"Your roll is 3. You won 1000."; $pay += 1000;} break;
            case 4: { print"Your roll is 4. You lost all."; $pay = 0;} break;
            case 5: { print"Your roll is 5. You won 500."; $pay += 500;} break;
            case 6: { print"Your roll is 6. You lost 300."; $pay -= 300;} break;
            case 7: { print"Your roll is 7. You won 200."; $pay += 200;} break;
            case 8: { print"Your roll is 8. You lost 1000."; $pay -= 1000;} break;
            case 9: { print"Your roll is 9. You won 250."; $pay += 250;} break;
            case 10: { print"Your roll is 10. You lost 250."; $pay -= 250;} break;
            case 11: { print"Your roll is 11. You lost 200."; $pay -= 200;} break;
            case 12: { print"Your roll is 12. You won 300."; $pay += 300;} break;
            case 13: { print"Your roll is 13. You won 500."; $pay += 500;} break;
            case 14: { print"Your roll is 14. You won 150."; $pay += 150;} break;
          }
          echo "</br>";
        }
        if($now_plays>$plays){
          if ($pay>=100) {
            $tp=$pay-100;
            echo "Total pay: $pay You won: $tp .</br>";
          }
          if ($pay==100) {
            echo "Total pay: $pay Did not lose not win.</br>";
          }
          if ($pay<100) {
            echo "Total pay: $pay You lost all. </br>";
          }
          echo "Thanks for playing Lucky Wheel.</br>";
          echo "Start a new game?";
          print "<form action = \"B10002057_HW3_2.html\" method = \"POST\">";
            print "<input type = \"submit\" value = \"GO\"/>";
          print "</form>"; 
        }
        $now_plays++;
        $j = $now_plays - 1;  
        if($j<=$plays){
          print "<form action = \"$PHP_SELF\" method = \"POST\">";
            echo"<input type=\"hidden\" value=\"$plays\" name=\"plays\">";
            echo"<input type=\"hidden\" value=\"$pay\" name=\"pay\">";
            echo"<input type=\"hidden\" value=\"$now_plays\" name=\"now_plays\">";
            print "<input type = \"submit\" value = \"Go\"/><input type = \"submit\" value = \"Stop\"/>";
         print "</form>"; 
       }
  print"</td></tr></table>";
?>
</body>
</html>
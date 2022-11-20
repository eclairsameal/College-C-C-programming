<?php

define ("LINE_BREAK", "<br>"); 
define ("TABLE_START", "<table width=600>\n"); 
define ("TABLE_END", "</table>\n"); 
define ("ROW_START", "  <tr>\n"); 
define ("ROW_END", "  </tr>\n"); 
define ("COL_START", "   <td align=center>\n      "); 
define ("COL_END", "\n   </td>\n"); 
define ("IMG_START", "<img src="); 
define ("IMG_END", ">"); 
define ("IMG_WIDTH", " width="); 
define ("IMG_HEIGHT", " height="); 
define ("A_START", '<a href="'); 
define ("A_CLOSE", '">'); 
define ("A_END", "</a>"); 

# 顯示圖形及連結


function showDir ($adirectory, $i) 

{ 
  global $browsedir; 

  $start = $i; 

# 更改 $maxcols 及 $maximages 可改變每一頁顯示的小圖的行數與列數。

  $maxcols = 2; 
  $maximages = 6; 
  $maximages = $i + ($maximages - 3); 

# 更改 $imagemaxwidth 及 $imagemaxheight 可改變顯示小圖的寬度與高度。

  $imagemaxwidth = 100; 
  $imagemaxheight = 100; 
    
# 計算高度與寬度的比例。

  $imagemaxratio =  $imagemaxwidth / $imagemaxheight; 
    
  $ndirectory = sizeof ($adirectory); 
  echo (TABLE_START); 
  for ($i; $i<=$maximages;) 
  { 
     echo (ROW_START); 
     for ($icols=1; $icols<=$maxcols; $icols++) 
     { 
       echo (COL_START); 
       $imagefilename = $adirectory[++$i]; 
       if (strlen($imagefilename)>0) 
       { 
         $imagepath = $browsedir."/".$imagefilename; 
         $imagesize = GetImageSize ($imagepath); 
         if ($imagesize) 
         { 
           $imagewidth = $imagesize[0]; 
           $imageheight = $imagesize[1]; 
           $imageratio = $imagewidth / $imageheight; 
           if ($imageratio > $imagemaxratio) 
           { 
              $imageoutputwidth = $imagemaxwidth; 
              $imageoutputheight = ceil ($imagemaxwidth/$imagewidth*$imageheight); 
           } 
           else if ($imageratio < $imagemaxratio) 
           { 
              $imageoutputheight = $imagemaxheight; 
              $imageoutputwidth = ceil ($imagemaxheight/$imageheight*$imagewidth); 
           } else 
           { 
              $imageoutputwidth = $imagemaxwidth; 
              $imageoutputheight = $imagemaxheight; 
           } 

# 顯示圖形

           echo (A_START.$imagepath.A_CLOSE); 
           echo (IMG_START.$imagepath.IMG_WIDTH.$imageoutputwidth.IMG_HEIGHT.$imageoutputheight.IMG_END); 
           echo (LINE_BREAK.$adirectory[$i]); 
           echo (A_END); 
         } 
         echo (COL_END); 
       } 
     } 
     echo (ROW_END); 
  } 
  echo (TABLE_END); 
pagemenu ($browsedir, $ndirectory, $start); 

} 

function pagemenu ($browsedir, $ndirectory, $pg) { 

echo "<br><center><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\" color=\"#000033\">page:"; 

$pg_num = 1; 

for ($img_num = 0; $img_num <= $ndirectory;) { 

    if ($pg == $img_num) {
    echo "<span class=\"menulink_1\"><a href=\"thumb.php?browsedir=$browsedir&start=$img_num\"> *$pg_num</a> <span>"; 
    } else { 
    echo "<span class=\"menulink_2\"><a href=\"thumb.php?browsedir=$browsedir&start=$img_num\"> $pg_num</a> <span>"; 
    }

# 建立其他頁次的連結, 每頁顯示四張圖, 故頁數 $pg_num 每加 1 , $img_num 就加 4 。

    $pg_num = $pg_num + 1; 
    $img_num = $img_num + 4; 

} 

echo "</font>\n"; 

} 

function dirToArray ($browsedir, $extensions) 
{ 

  $nextensions = sizeof ($extensions); 
  $idirectory = 0; 
  $directory = dir($browsedir); 
    
  while ($entry = $directory->read()) 
  { 
      for ($i=1; $i<=$nextensions; $i++) 
      { 
         $compare = stristr ($entry, $extensions[$i]); 
         if (strlen($compare) == strlen($extensions[$i])) 
         { 
            $adirectory[++$idirectory] = $entry; 
            break; 
         } 
      } 
  } 
  $directory->close();
  return $adirectory; 
} 

#主程式

#變數 $browsedir 為圖檔放置的位置。

$browsedir="./images";

# 允許瀏覽的圖檔副檔名, 放置於陣列中, 可自行增加。

$extensions[1] = "jpeg"; 
$extensions[2] = "jpg"; 
$extensions[3] = "gif"; 
$extensions[4] = "png";  
showDir (dirToArray ($browsedir, $extensions), $start); 
?>

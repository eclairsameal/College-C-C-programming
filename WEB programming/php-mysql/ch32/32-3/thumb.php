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

# ��ܹϧΤγs��


function showDir ($adirectory, $i) 

{ 
  global $browsedir; 

  $start = $i; 

# ��� $maxcols �� $maximages �i���ܨC�@����ܪ��p�Ϫ���ƻP�C�ơC

  $maxcols = 2; 
  $maximages = 6; 
  $maximages = $i + ($maximages - 3); 

# ��� $imagemaxwidth �� $imagemaxheight �i������ܤp�Ϫ��e�׻P���סC

  $imagemaxwidth = 100; 
  $imagemaxheight = 100; 
    
# �p�Ⱚ�׻P�e�ת���ҡC

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

# ��ܹϧ�

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

# �إߨ�L�������s��, �C����ܥ|�i��, �G���� $pg_num �C�[ 1 , $img_num �N�[ 4 �C

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

#�D�{��

#�ܼ� $browsedir �����ɩ�m����m�C

$browsedir="./images";

# ���\�s�������ɰ��ɦW, ��m��}�C��, �i�ۦ�W�[�C

$extensions[1] = "jpeg"; 
$extensions[2] = "jpg"; 
$extensions[3] = "gif"; 
$extensions[4] = "png";  
showDir (dirToArray ($browsedir, $extensions), $start); 
?>

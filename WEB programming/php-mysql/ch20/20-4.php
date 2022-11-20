<?php
   $string ="´ú¸Õ¥Î¤å¦r";
   echo "**********$string**********<p>";
   $string = ereg_replace ("^", "<BR>", $string);
   $string = ereg_replace ("$", "<BR>", $string);
   echo "==========$string==========";
?>

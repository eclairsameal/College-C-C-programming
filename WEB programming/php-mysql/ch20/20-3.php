<?php
     $string = "This is a test. That is another test.";
     echo ereg_replace (" is", "  was", $string)."<P>";
     echo ereg_replace (" is", "<B> is</B>", $string)."<P>";
     echo ereg_replace ("test", "<a href=http://www.flag.com.tw>test</a>", $string);
?>

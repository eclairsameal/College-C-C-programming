<?PHP
     $num = 49;
     $string = "This string has four words. <BR>";
     $string = ereg_replace ('four', $num, $string);
     echo $string;
     $num = '49';
     $string = "This string has four words";
     $string = ereg_replace ('four', $num, $string);
     echo $string;
?>

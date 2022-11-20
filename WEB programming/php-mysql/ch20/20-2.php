<?PHP
    $string="I am abc";
    if (ereg ("abc", $string)) echo "'abc' is True <p>";                   
    if (ereg ("^abc", $string)) echo "'^abc' is True <p>";                   
    if (ereg ("abc$", $string)) echo "'abc$' is True";
?>

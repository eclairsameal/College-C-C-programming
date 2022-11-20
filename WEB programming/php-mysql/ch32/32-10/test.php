<?php
include ('telnet.class.php');
$a=NEW Telnet ('10.10.50.254',23);

$a->write('root'.chr(10));
$a->write('123456'.chr(10));
$a->write(chr(10));
$a->write("cd config".chr(10));
$a->write("rm -f *.conf".chr(10));
echo $a->read_till ('ipfw.conf');
?>
<?php
if ($uploadedfile<>"none") {
 if (!copy($uploadedfile, "$uploadedfile_name")) {
 echo "<font face='arial' size='2'> $name �ɮפW�ǥ��� ,<br>";
 echo "�]�i��O�ɮפӤj<br>";
 echo "�Шϥ� back ����A�դ@��";
 } else {
 echo "<font face='arial' size='2'>�ɮפW�Ǧ��\ !<br>";
 echo "�ɮ׫��A�G$uploadedfile_type <BR>";
 echo "�ɮפj�p�G$uploadedfile_size <BR>";
 echo "�ɮצW�١G$uploadedfile_name <BR>";
 echo "�ɮ׻����G$description <BR>";
 }
}
?>

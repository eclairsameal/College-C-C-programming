<?php
  $a=array('this', 'is', 'a', 'book','that','is', 'a','pen');
  $pos=array_search('book',$a);
  echo "$a[$pos]����m�b�}�C���� $pos ��<p>";
  $p=array_keys($a,'is');
  foreach ($p as $k => $v)
     echo "��[ $k ]�� is �X�{�b�}�C�� $v �Ӧ�m<br>";
  echo "�`�@�� ".
count($p)." �� is �b�}�C�� <br>";
?>
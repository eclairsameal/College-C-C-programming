<?php
  header("Refresh: 5");
?>
<html>
<title>��s����</title>
<body>
<?php
  $msg[0]="�Ǧp�f�����, ���ɫh�h.";
  $msg[1]="�����, ���鲦.";
  $msg[2]="�n�����ۨ�, �滷������";
  $msg[3]="�ѤU�L����, �u�Ȧ��ߤH";
  $msg[4]="���Ѭ����\����";
  $msg[5]="�L��, �O�̦n����ڻy��";
  $i=rand()% 6;
  echo "����p�y : $msg[$i]";
?>
</body>
</html>
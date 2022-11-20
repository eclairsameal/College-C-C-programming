# time_date.pl
#  Input: None
# Output: The nine values returned by localtime
#

($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, 
  $isdst) = localtime;

print "\$sec = $sec\n";
print "\$min = $min\n";
print "\$hour = $hour\n";
print "\$mday = $mday\n";
print "\$mon = $mon\n";
print "\$year = $year\n";
print "\$wday = $wday\n";
print "\$yday = $yday\n";
print "\$isdst = $isdst\n";


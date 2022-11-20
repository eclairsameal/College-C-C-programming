# quadeval.pl – A simple Perl program
#  Input: Four numbers, representing the values of 
#       a, b, c, and x
# Output: The value of the expression 
#       axx + bx + c
# Get input
print "Please input the value of a ";
$a = <STDIN>;
print "Please input the value of b ";
$b = <STDIN>;
print "Please input the value of c ";
$c = <STDIN>;
print "Please input the value of x ";
$x = <STDIN>;
# Compute and display the result
$result = $a * $x * $x + $b * $x + $c;
print "The value of the expression is: $result \n";

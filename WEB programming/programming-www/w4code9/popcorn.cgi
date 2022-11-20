#!/usr/local/bin/perl

# popcorn.cgi
# A CGI program to process the popcorn sales form

use CGI ":standard";

# Initialize total price and total number of purchased items

$total_price = 0;
$total_itemi = 0;

# Produce the header part of the HTML return value

print header;
print start_html("CGI-Perl Popcorn Sales Form, using CGI.pm");

# Set local variables to the parameter values

my($name, $street, $city, $payment) = 
      (param("name"), param("street"),
       param("city"), param("payment"));
my($unpop, $caramel, $caramelnut, $toffeynut) = (param("unpop"), param("caramel"),
        param("caramelnut"), param("toffeynut"));

# Compute the number of items ordered and the total cost

$total_price = 3.0 * $unpop + 3.5 * $caramel + 4.5 * $caramelnut +
               5.0 * $toffeynut;
$total_items = $unpop + $caramel + $caramelnut + $toffeynut;

# Produce the result information to the browser and finish the page

print h3("Customer:"), "\n";
print "$name<br/>\n", "$street <br/>\n", "$city <br/><br/>\n";
print "<b>Payment method:</b> $payment <br/><br/>\n";
print h3("Items ordered:"), "\n";
if ($unpop > 0) {print "Unpopped popcorn: $unpop <br/>\n";}
if ($caramel > 0) {print "Caramel popcorn: $caramel <br/>\n";}
if ($caramelnut > 0) {print "Caramel nut popcorn: $caramelnut <br/>\n";}
if ($toffeynut > 0) {print "Toffey nut popcorn: $toffeynut <br/>\n";}
print "Thank you for your order <br/><br/>\n";
print "<b>Your total bill is:</b> \$ $total_price <br/> \n";
print end_html;

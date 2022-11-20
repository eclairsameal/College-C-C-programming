#!/usr/local/bin/perl

# conelec1.cgi
# This CGI program processes the consumer electronics survey form
# and updates the file that stores the survey data, survdat.dat

use CGI ":standard";
use Fcntl qw(:DEFAULT :flock);

# error - a function to produce an error message for the client
#         and exit in case of input/output errors

sub error {
    print start_html();
    print "Error - input/output error in conelec1.pl <br/>";
    print end_html();
    exit(1);
}

# Begin the main program
# Get the form values

my($age, $gender, $vote) = (param("age"), param("gender"),
			     param("vote"));

# Produce the header for the reply page - do it here so error
#  messages appear on the page

print header;

# Set $index to the line index of the current vote

$index = $age + $gender;

# Open and lock the survey data file

open(SURVDAT, "+<survdat.dat") or error(); 

flock(SURVDAT, LOCK_EX) or error();

# Read the survey data file, unlock it, and close it

for ($count = 0; $count <= 7; $count++) {
   chomp($file_lines[$count] = <SURVDAT>); 
}

# Split the line into its parts, increment the chosen device, and 
#  put it back together again

@file_votes = split / /, $file_lines[$index]; 
$file_votes[$vote]++;
$file_lines[$index] = join(" ", @file_votes);

# Rewind the file for writing 

seek(SURVDAT, 0, 0) or error();

# Write out the file data and close it (which also unlocks it)

foreach $line (@file_lines) {
    print SURVDAT "$line\n";
}

close(SURVDAT);

# Build the web page to thank the survey participant

print start_html("Thankyou");
print "Thank you for participating in our survey <br/> <br/> \n";
print end_html;


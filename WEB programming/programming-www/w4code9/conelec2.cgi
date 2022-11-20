#!/usr/local/bin/perl -w

# conelec2.pl - display the survey results

# make_rows - a subprogram to make the rows of an output table

sub make_rows {
  my $index = $_[0];

# Split the input lines for females into age arrays

@age1 = split(/ /, $vote_data[$index]);
@age2 = split(/ /, $vote_data[$index + 1]);
@age3 = split(/ /, $vote_data[$index + 2]);
@age4 = split(/ /, $vote_data[$index + 3]);

# Add the row titles to the age arrays

unshift(@age1, "10-25");
unshift(@age2, "26-40");
unshift(@age3, "41-60");
unshift(@age4, "Over 60");

# Create the column titles in HTML by giving their address to the th
#  function and storing the return value in the @rows array

@rows = th(\@col_titles);

# Now create the data rows with the td function
#  and add them to the row addresses array

push(@rows, td(\@age1), td(\@age2), td(\@age3), td(\@age4));
}  ##** end of the make_rows subprogram

# error - a function to produce an error message for the client
#         and exit in case of open errors

sub error {
    print start_html;
    print "Error - input/output error in conelec2.pl <br/>";
    print end_html;
    exit(1);
}  ##** end of the error subprogram

use CGI qw(:standard);


# Make the column titles array

@col_titles = ("Age Group", "Conventional TV", "HDTV", "VCR",
	       "CD player", "MiniCD player/recorder", "DIVD player",
	       "Other");
print header;

# Open and read the survey data file

open(SURVDAT, "<survdat.dat") or error();
@vote_data = <SURVDAT>;

# Create the beginning of the result web page

print start_html("Survey Results");
print h2("Results of the Consumer Electronics Purchasing Survey"), "\n";

# Create the rows of the female survey results table

make_rows(0);

# Create the table for the female survey results
#  The address of the array of row addresses is passed to Tr

print table({-border => "border"},
	    caption(h3("Survey Data for Females")),
	     Tr(\@rows)
	   );

# Create the rows for the male results table

make_rows(4);

# Create the table for the male survey results
#  The address of the array of row addresses is passed to Trsults

print "<br /><br />";
print table({-border => "border"},
	    caption(h3("Survey Data for Males")),
	    Tr(\@rows)
	   );

print end_html;


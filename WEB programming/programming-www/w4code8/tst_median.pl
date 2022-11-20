# tst_median.pl - a program to test a function that
#                 computes the median of a given array

# median - a function
# Parameters:
#     A reference to an array of numbers
# Return value:
#     The median of the array, where median is the 
#      middle element of the sorted array, if the
#      length is odd; if the length is even, the median
#      is the average of the two middle elements of the
#      sorted array

sub median {
    my $ref_list = $_[0];

# Compute the length of the passed array

    my $len = $#$ref_list + 1;

# Sort the parameter array

    @list = sort {$a <=> $b} @$ref_list;

# Compute the median

    if ($len % 2 == 1) {  # length is odd
        return $list[$len / 2];
    } else {  # length is even
        return ($list[$len / 2] + $list[$len / 2 - 1]) / 2;
    }
     
}  # End of function median

# Begin main program
# Create two test arrays, one with odd length and one with 
#  even length

@list1 = (11, 36, 5, 20, 41, 6, 8, 0, 9);
@list2 = (43, 77, 11, 29, 8, 51, 9, 18);

# Call median on both arrays and display the results

$med = median(\@list1);
print "The median of the first array is: $med \n";
$med = median(\@list2);
print "The median of the second array is: $med \n";


# process_names.pl - A simple program to illustrate
#                     the use of arrays
#  Input: A file, specified on the command line, of 
#         lines of text, where each line is a person’s
#         name
# Output: The input names, after all letters are converted
#         to uppercase, in alphabetical order 

$index = 0;

#>>> Loop to read the names and process them
while($name = <>) {

#>>> Convert the name’s letters to uppercase and put it in
#>>>  the names array
    $names[$index++] = uc($name);
}

#>>> Display the sorted list of names
print "\nThe sorted list of names is:\n\n\n";
foreach $name (sort @names) {
    print ("$name \n");
}

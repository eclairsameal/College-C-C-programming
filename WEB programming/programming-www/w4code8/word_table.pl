# word_table.pl
#  Input: A file of text in which all words are separated by white-
#         space or punctuation, possibly followed by whitespace, 
#         where the punctuation can be a comma, a semicolon, a 
#         question mark an exclamation point, a period, or a colon.
#         The input file is specified on the command line
# Output: A list of all unique words in the input file, 
#         in alphabetical order

#>>> Main loop to get and process lines of input text
while (<>) {

#>>> Split the line into words
    @line_words = split /[ \.,;:!\?]\s*/;

#>>> Loop to count the words (either increment or initialize to 1)
    foreach $word (@line_words) {
        if (exists $freq{$word}) {
            $freq{$word}++;
        } else {
            $freq{$word} = 1;
        }
    }
}
#>>> Display the words and their frequencies
print "\n Word \t\t Frequency \n\n";
foreach $word (sort keys %freq) {
    print " $word \t\t $freq{$word} \n";
}

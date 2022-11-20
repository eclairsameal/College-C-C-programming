# word_table.rb
#  Input: Text from the keyboard. All words in the input are 
#         separated by white space or punctuation, possibly followed  
#         by white space, where the punctuation can be a comma, a 
#         semicolon, a question mark, an exclamation point, a period, 
#         or a colon.
# Output: A list of all unique words in the input, in alphabetical
#          order, along with their frequencies of occurrence 

freq = Hash.new
line_words = Array.new

# Main loop to get and process lines of input text
while line = gets

# Split the line into words
    line_words = line.chomp.split( /[ \.,;:!\?]\s*/)

# Loop to count the words (either increment or initialize to 1)
    for word in line_words
        if freq.has_key?(word) then
            freq[word] = freq[word] + 1
        else
            freq[word] = 1
        end
    end
end

# Display the words and their frequencies
puts "\n Word \t\t Frequency \n\n"
for word in freq.keys.sort
    puts " #{word} \t\t #{freq[word]}"
end

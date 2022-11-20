# process_names.rb - A simple Ruby program to
#  illustrate the use of arrays
#  Input: A list of lines of text, where each line
#         is a person's name
# Output: The input names, after all letters are 
#         converted to uppercase, in alphabetical order

index = 0
names = Array.new

# Loop to read the names and process them
while(name = gets)

# Convert the name's letters to uppercase and put it
#  in the names array
  names[index] = name.chomp.upcase
  index += 1
end

# Sort the array in place and display it
names.sort!
puts "The sorted array"
for name in names
  puts name
end

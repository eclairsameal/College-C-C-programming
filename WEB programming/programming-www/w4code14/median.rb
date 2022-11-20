# median - a method
#  Parameter: An array of numbers
#  Return value: The median of the parameter array
# 
def median(list)

# Sort the array
  list2 = list.sort

# Get the length of the array
  len = list2.length

# Compute the median
  if(len % 2 == 1)  # length is odd
    return list2[len / 2]
  else              # length is even
    return (list2[len / 2] + list2[len / 2 - 1]) / 2
  end

end  # end of the median method


# Stack2_class.rb - a class to implement a stack-like 
#                   structure in an array
class Stack2_class

# Constructor - parameter is the size of the stack - default is 100
  def initialize(len = 100)
    @stack_ref = Array.new(len)
    @max_len = len
    @top_index = -1
  end

# push method
  def push(number)
    if @top_index == @max_len
      puts "Error in push - stack is full"
    else
      @top_index += 1
      @stack_ref[@top_index] = number
    end
  end

# pop method
  def pop()
    if @top_index == -1
      puts "Error in pop - stack is empty"
    else
      @top_index -= 1
    end
  end

# top method
  def top()
    if @top_index > -1
      return @stack_ref[@top_index]
    else
      puts "Error in top - no elements"
    end
  end

# top2 method
  def top2
    if @top_index > 0
      return @stack_ref[@top_index - 1]
    else
      puts "Error in top2 - there are not 2 elements"
    end
  end

# empty method
  def empty()
    @topIndex == -1
  end

end

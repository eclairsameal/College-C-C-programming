# home_controller.rb - for the popcorn application
class HomeController < ApplicationController
  def the_form
  end

# result method - fetch data and compute the cost

  def result

# Fetch the form values

    @unpop = params[:unpop].to_i
    @caramel = params[:caramel].to_i
    @caramelnut = params[:caramelnut].to_i
    @toffeynut = params[:toffeynut].to_i
    @name = params[:name]
    @street = params[:street]
    @city = params[:city]
    @payment = params[:payment]

# Compute the item costs and total cost

    @unpop_cost = 3.0 * @unpop
    @caramel_cost = 3.5 * @caramel
    @caramelnut_cost = 4.5 * @caramelnut
    @toffeynut_cost = 5.0 * @toffeynut
    @total_price = @unpop_cost + @caramel_cost +
                   @caramelnut_cost + @toffeynut_cost
    @total_items = @unpop + @caramel + @caramelnut + @toffeynut

# Now convert the dollar amounts to strings with 2 places
#  to the right of the decimal point
    @total_price = sprintf("%5.2f", @total_price)
    @unpop_cost = sprintf("%5.2f", @unpop_cost)
    @caramel_cost = sprintf("%5.2f", @caramel_cost)
    @caramelnut_cost = sprintf("%5.2f", @caramelnut_cost)
    @toffeynut_cost = sprintf("%5.2f", @toffeynut_cost)

  end
end
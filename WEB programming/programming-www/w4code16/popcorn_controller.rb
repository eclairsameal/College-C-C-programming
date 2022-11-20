# popcorn_controller.rb
#  The controller for the popcornA application
#  When the user enters a zip code in the popcorn
#  order form, this application puts in the city
#  and state for the user

class PopcornController < ApplicationController
  @@city_state_data = {"81611" => "Aspen, Colorado",
                     "81411" => "Bedrock, Colorado",
                     "80908" => "Black Forest, Colorado",
                     "80301" => "Boulder, Colorado",
                     "81127" => "Chimney Rock, Colorado",
                     "80901" => "Colorado Springs, Colorado",
                     "81223" => "Cotopaxi, Colorado",
                     "80201" => "Denver, Colorado",                     
                     "81657" => "Vail, Colorado",
                     "80435" => "Keystone, Colorado",
                     "80536" => "Virginia Dale, Colorado"
                     }
  def show_form
  end

# The fill_city_state method
#  Renders the city and state

  def fill_city_state
    zip = params[:zip]

# If possible, set city_state to the city and state
    if @@city_state_data.has_key?(zip)
      city_state = @@city_state_data[zip]

# Otherwise, set it to blanks
    else
      city_state = " , "
    end

# Render it
    render :text => city_state
  end # end of the fill_city_state method
end
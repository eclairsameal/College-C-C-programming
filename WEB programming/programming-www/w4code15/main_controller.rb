# main_controller.rb - for the cars application
class MainController < ApplicationController

# welcome method - fetches values for the 
#  initial view

  def welcome
    @num_cars = Corvette.count
    @num_states = State.count
  end

# result method - fetches values for the
#  result view

  def result
    @year1 = params[:year1]
    @year2 = params[:year2]
    @body = params[:body]
    @carz = Corvette.find(:all, :conditions => ["year >= ? and year <= ? and 
                           body_style = ?", @year1, @year2, @body])
    @statez = State.find(:all)
  end
end
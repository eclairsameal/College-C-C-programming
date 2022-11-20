# request_controller.rb - for the cars application
class RequestController < ApplicationController
  def enter
  end
  def result
    @year1 = params[:year1]
  end
end
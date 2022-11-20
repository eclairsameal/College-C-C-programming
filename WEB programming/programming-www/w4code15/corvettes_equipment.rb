class CorvettesEquipment < ActiveRecord::Base
  belongs_to :corvette
  belongs_to :equipment
  has_many :corvette
end
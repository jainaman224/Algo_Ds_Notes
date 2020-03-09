class Array
  def beadsort
    map {|e| [1] * e}.columns.columns.map(&:length)
  end
 
  def columns
    y = length
    x = map(&:length).max
    Array.new(x) do |row|
      Array.new(y) { |column| self[column][row] }.compact # it remove null value
    end
  end
end
 
# Driver code:
p [2,31,34,324,2].beadsort

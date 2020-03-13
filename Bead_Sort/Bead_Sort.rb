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
 
def myarray(a,n)
  for i in 0..n
    a[i] = gets.chomp.to_i
  end
  return a
end

# Driver code:
a = Array.new
n = gets.chomp.to_i
new_arr = myarray(a,n)
print(new_arr.beadsort)

# Cocktail Sort In Ruby

class Array 
    def cocktailSort!
        begin
            swap = false
            0.upto(length - 2) do |i|
                if self[i] > self[i + 1]
                    self[i], self[i + 1] = self[i + 1], self[i]
                    swap = true
                end
            end
            break unless swap

            swap = false
            (length - 2).downto(0) do |i|
                if self[i] > self[i + 1]
                    self[i], self[i + 1] = self[i + 1], self[i]
                    swap = true
                end
            end
        end while swap
        self
    end
end

# Taking User Input

puts "Enter the size of array: "
size = gets.to_i
puts
input_array = Array.new(size)

counter = 0

# Input array values using while loop

while(counter != size)
    puts "Enter the value at index #{counter}: "
    input_array[counter] = gets.to_i
    counter += 1
end

puts 

puts "Input Array: #{input_array}"
print "Cocktail Sort: ", input_array.cocktailSort!

# Sample Input and Output

= begin

Enter the size of array: 11

Enter the value at index 0: 10
Enter the value at index 1: 8
Enter the value at index 2: 4
Enter the value at index 3: 3
Enter the value at index 4: 1
Enter the value at index 5: 9
Enter the value at index 6: 0
Enter the value at index 7: 2
Enter the value at index 8: 7
Enter the value at index 9: 5
Enter the value at index 10: 6

Input Array: [10, 8, 4, 3, 1, 9, 0, 2, 7, 5, 6]
Cocktail Sort: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

= end

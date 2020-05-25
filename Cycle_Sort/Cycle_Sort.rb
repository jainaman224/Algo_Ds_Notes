# Cycle Sort In Ruby

# Function definition
def cycleSort!(input)
    change = 0

    # Looping through the input to find cycles to rotate
    for cycleStart in 0 .. input.size - 2
        item = input[cycleStart]

        # Finding where to put the item
        position = cycleStart
        for i in cycleStart + 1 ... input.size
            position += 1 if input[i] < item
        end

        # If the item is already present, there is no cycle
        next if position == cycleStart

        # Otherwise, put the item there or right after any duplicates
        position += 1 while item == input[position]
        input[position], item = item, input[position]
        change += 1

        # Rotate the rest of the cycle
        while position != cycleStart

            # Finding where to put the item
            position = cycleStart
            for i in cycleStart + 1 ... input.size
                position += 1 if input[i] < item
            end

            # Putting the item there or right after any duplicates
            position += 1 while item == input[position]
            input[position], item = item, input[position]
            change += 1
        end
    end
    change
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
puts "Cycle Sort: "

cycleSort!(input_array)
puts "#{input_array}"

=begin

Sample Input

Enter the size of array: 15

Enter the value at index 0: 0
Enter the value at index 1: 1
Enter the value at index 2: 2
Enter the value at index 3: 2
Enter the value at index 4: 2
Enter the value at index 5: 2
Enter the value at index 6: 1
Enter the value at index 7: 9
Enter the value at index 8: 3.5
Enter the value at index 9: 5
Enter the value at index 10: 8
Enter the value at index 11: 4
Enter the value at index 12: 7
Enter the value at index 13: 0
Enter the value at index 14: 6

Sample Output

Input Array: [0, 1, 2, 2, 2, 2, 1, 9, 3, 5, 8, 4, 7, 0, 6]
Cycle Sort: [0, 0, 1, 1, 2, 2, 2, 2, 3, 4, 5, 6, 7, 8, 9]

=end

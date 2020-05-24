# Shell Sort In Ruby

# Function Definition
def shell_sort(values)
    inct = values.size / 2

    while inct > 0
        inct.upto(values.size - 1){ |i|
            j = i
            temp = values[i]

            while j >= inct and values[j - inct] > temp
                values[j] = values[j - inct]
                j -= inct
            end

            values[j] = temp
        }
        inct = (inct == 2 ? 1 : inct * 10 / 22)
    end
    values
end

# Taking User Input
puts "Enter the size of array: "
size = gets.to_i
puts
input_array = Array.new(size)

counter = 0

# Input Array Values Using While Loop
while(counter != size)
    puts "Enter the value at index #{counter}: "
    input_array[counter] = gets.to_i
    counter += 1
end

puts 

puts "Input Array: #{input_array}"
puts "Shell Sort: "

# Function Call
shell_sort(input_array)
puts "#{input_array}"

= begin

Enter the size of array: 5

Enter the value at index 0: 121
Enter the value at index 1: 71
Enter the value at index 2: 1
Enter the value at index 3: 88
Enter the value at index 4: 9

Input Array: [121, 71, 1, 88, 9]
Shell Sort: [1, 9, 71, 88, 121]

-----------------------------------------------

Enter the size of array: 7

Enter the value at index 0: 68
Enter the value at index 1: 1
Enter the value at index 2: 11
Enter the value at index 3: -8
Enter the value at index 4: 0
Enter the value at index 5: 3
Enter the value at index 6: 35

Input Array: [68, 1, 11, -8, 0, 3, 35]
Shell Sort: [-8, 0, 1, 3, 11, 35, 68]

= end

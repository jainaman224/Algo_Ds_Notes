# Circle Sort In Ruby

class Array
    def circle_sort!
        while _circle_sort!(0, size - 1) > 0
        end
        self
    end

    private
    def _circle_sort!(lower, higher, swapping = 0)
        return swapping if lower == higher
        low, high = lower, higher
        middle = (lower + higher) / 2

        while lower < higher
            if self[lower] > self[higher]
                self[lower], self[higher] = self[higher], self[lower]
                swapping += 1
            end
            lower += 1
            higher -= 1
        end

        if lower == higher && self[lower] > self[higher+1]
            self[lower], self[higher + 1] = self[higher + 1], self[lower]
            swapping += 1
        end

        swapping + _circle_sort!(low, middle) + _circle_sort!(middle + 1, high)
    end
end

puts "Enter the size of array: "
size = gets.to_i
puts
input_array = Array.new(size)

counter = 0

while(counter != size)
    puts "Enter the value at index #{counter}: "
    input_array[counter] = gets.to_i
    counter += 1
end

puts 

puts "Input Array: #{input_array}"
puts "Circle Sort: #{input_array.circle_sort!}"

= begin

Enter the size of array: 3

Enter the value at index 0: 999
Enter the value at index 1: 21
Enter the value at index 2: 58

Input Array: [999, 21, 58]
Circle Sort: [21, 58, 999]

--------------------------------------------------

Enter the size of array: 5

Enter the value at index 0: 121
Enter the value at index 1: 71
Enter the value at index 2: 1
Enter the value at index 3: 88
Enter the value at index 4: 9

Input Array: [121, 71, 1, 88, 9]
Circle Sort: [1, 9, 71, 88, 121]

= end

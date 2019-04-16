# Function that sorts the given input
def shaker_sort(input , length)
    issort = true # variable to check whether any swapping occurs
    while issort
        issort = false # When no swapping occured
        i = 0
        # Loop in the forward direction
        for j in i..length-(i+2)
            # If any smaller number is caught
            # Swap the elements
            if input[j+1] < input[j]
                a = input[j]
                input[j] = input[j+1]
                input[j+1] = a
                issort = true # Swapping occured
            end
        end
        # Loop in the opposite direction than the previous one
        for j in length-(i+2)..i+1
            # If any smaller number is caught
            # Swap the elements
            if input[length-i-2] < input[length-i-3]
                a = input[length-i-2]
                input[length-i-2] = input[length-i-3]
                input[length-i-3] = a
                issort = true # Swapping occured
            end
        end
        i = i+1
    end
    # Prints the sorted list
    for i in 0..length-1
        print(input[i].to_s + " ")
    end
end
input = [2,7,8,1,4,1]
length = input.length()
# Driver function
shaker_sort(input , length)
=begin
input = [2,7,8,1,4,1]
output = 1 1 2 4 7 8
=end

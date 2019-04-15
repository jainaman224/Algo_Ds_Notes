# Function that sorts the given input
def shaker_sort(input , length)
    issort = true
    while issort
        # variable to check whether any swapping occurs
        issort = false
        i = 0
        # If any smaller number is caught
        for j in i..length-(i+2)
            # Swap the elements
            if input[j] > input[j+1]
              a = input[j]
              input[j] = input[j+1]
              input[j+1] = a
              issort = true
            end
        end
        # Loop in the opposite direction than the previous one
        # If any smaller number is caught
        for j in length-(i+2)..i+1
            # Swap the elements
            if input[length-i-2] < input[length-i-3]
              a = input[length-i-2]
              input[length-i-2] = input[length-i-3]
              input[length-i-3] = a
              issort = true
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
shaker_sort(input , length)
=begin
input = [2,7,8,1,4,1]
output = 1 1 2 4 7 8
=end

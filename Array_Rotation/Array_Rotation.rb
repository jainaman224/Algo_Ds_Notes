# Function for the Array Rotation.
# Shifting the elements of the array to the left by one index and rotating the
# Zeroth indexed element to (n-1)th index.
def Left_Array_Rotation(arr , n)
    temp = arr[0]
    for i in 0..n-2
        arr[i] = arr[i+1]
    end
    arr[n-1] = temp
    return arr
end

# Function for the Number of times Rotation to be performed.
def Rotation(input , no_of_rot , n)
    d = no_of_rot
    temp_arr = input
    for i in 0..d-1
        temp_arr = Left_Array_Rotation(temp_arr , n)
    end
    for i in 0..n-1
        print(temp_arr[i].to_s + " ")
    end
end

input = [1 , 3 , 8 , 5 , 9]
no_of_rot = 2 # Variable for the Number of times rotation to be performed.
n = input.length()

# Driver Function
Rotation(input , no_of_rot , n)

=begin
input = [1 , 3 , 8 , 5 , 9]
output = 8 5 9 1 3
=end

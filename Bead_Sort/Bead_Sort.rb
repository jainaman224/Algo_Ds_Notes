# Bead Sort is a Natural Sorting Algorithm Also known as Gravity sort,
# this algorithm was inspired from natural phenomenons and was designed keeping in mind objects(or beads) falling under the influence of gravity.
# The Idea: Positive numbers are represented by a set of beads like those on an abacus.
# Implementation of Bead sort in Ruby

class Array
    # BeadSort algorithm function
    def beadsort
        # this will take the matrix and make transpose of it to sort.
        map { |e| [1] * e }.columns.columns.map(&:length)
    end

    # Columns for the matrix
    def columns
        y = length
        x = map(&:length).max
        Array.new(x) do |row|
        Array.new(y) { |column| self[column][row] }.compact # it remove null value
        end
    end
end

# function for taking dynamic array input.
def myarray(a, n)
    for i in 0..n
        a[i] = gets.chomp.to_i
    end
    return a
end

# Driver code:
a = Array.new
n = gets.chomp.to_i
new_arr = myarray(a, n)
print(new_arr.beadsort.reverse())

# Output
# Before sorting
# 23 2 12 54 90 102 32
# After sorting
# 2 12 23 32 54 90 102

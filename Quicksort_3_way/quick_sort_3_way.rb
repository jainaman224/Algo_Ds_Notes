#3 way Quick Sort in Ruby

def quick_sort(a, lo, hi)
    if lo < hi
        temp = partition(a, lo, hi)
        l = temp[0]
        r = temp[1]
        quick_sort(a, lo, l - 1)
        quick_sort(a, r + 1, hi)
    end
end

def partition(a, lo, hi)
    pivot = a[lo]
    i = lo + 1
    lt = lo
    gt = hi
    
    while(i <= gt)
        
        if a[i] < pivot
            temp = a[lt]
            a[lt] = a[i]
            a[i] = temp
            lt += 1
            i += 1
        elsif a[i] > pivot
            temp = a[i]
            a[i] = a[gt]
            a[gt] = temp
            gt -= 1
        else
            i += 1
        end
    end
    return lt, gt
end

puts "Enter the size of array : "
n = gets
puts "Enter the values for the array : "
$i = 0
$num = Integer(n)
arr = Array.new

while $i < $num  do
    
    arr[$i] = gets
    $i +=1
end
$num2 = Integer(n) - 1
puts quick_sort(arr, 0, $num2)
puts "After sorting : "
puts arr

=begin
Sample Input-Output
Enter the size of array : 
4
Enter the values for the array : 
10
14
12
13

After sorting : 
10
12
13
14
=end

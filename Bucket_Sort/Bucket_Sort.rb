DEFAULT_BUCKET_SIZE = 5

def bucket_sort(input, bucket_size = DEFAULT_BUCKET_SIZE)
    print 'Array is empty' if input.empty?

    array = input.split(' ').map(&:to_i)

    bucket_count = ((array.max - array.min) / bucket_size).floor + 1

    # create buckets
    buckets = []
    bucket_count.times { buckets.push [] }

    # fill buckets
    array.each do |item|
        buckets[((item - array.min) / bucket_size).floor].push(item)
    end

    # sort buckets
    buckets.each(&:sort!)

    buckets.flatten.join(' ')
end

puts 'Enter a list of numbers (separated by space) : '
list = gets
puts 'The sorted list is : '
print bucket_sort(list)


# Output :
# Enter a list of numbers (separated by space) : 
# 7 9 5 4 1
# The sorted list is : 
# 1 4 5 7 9


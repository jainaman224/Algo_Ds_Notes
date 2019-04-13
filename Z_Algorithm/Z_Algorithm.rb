def getZarr(str, z_arr)
    n = str.length
    left = 0
    right = 0

    for i in 1..n
        if i > right
            left = i
            right = i

            while right < n and str[right - left] == str[right] do
                right += 1
            end

            z_arr[i] = right - left
            right -= 1
        else
            k = i - left

            if z_arr[k] < right - i + 1
                z_arr[i] = z_arr[k]
            else
                left = i

                while right < n and str[right - left] == str[right] do
                    right += 1
                end

                z_arr[i] = right - left
                right -= 1
            end 
        end
    end
end


def search(text, pattern)
    concat = pattern + "$" + text
    size = concat.length
    z_arr = Array.new(size, 0)

    getZarr(concat, z_arr)

    for i in 0..size-1
        if z_arr[i] == pattern.length
            print "Pattern found at %d\n" % [i - pattern.length]
        end
    end
end


text = "namanchamanbomanamansanam"
pattern = "aman"

search(text, pattern)

=begin Output

Pattern found at 2
Pattern found at 8
Pattern found at 17

=end

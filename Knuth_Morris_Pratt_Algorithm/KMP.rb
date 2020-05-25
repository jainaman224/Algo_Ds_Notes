# Given a text and a pattern, we need to find all occurrences of pattern in text

def kmp_search(pattern, text)
    pattern_size = pattern.length
    text_size = text.length

    lps = Array.new(pattern_size) # longest_prefix_suffix array 
    lps = calculate_lps(pattern, lps) # compute lps[]
    i = 0 # index for pattern[]
    j = 0 # index for text[]
    
    while i < text_size
        if pattern[j] == text[i]
            i += 1
            j += 1
        end

        if j == pattern_size
            puts "Pattern found at #{i - j + 1}"
            j = lps[j - 1]
        elsif i < text_size && pattern[j] != text[i]
            if j != 0
                j = lps[j - 1]
            else
                i += 1
            end
        end
    end
end

# function to preprocess lps[] to hold the longest prefix suffix values for pattern
def calculate_lps(pattern, lps)
    len = 0
    lps[0] = 0

    i = 1
    while i < pattern.length
        if pattern[i] == pattern[len]
            len += 1
            lps[i] = len
            i += 1
        else
            if len != 0
                len = lps[len - 1]
            else
                lps[i] = 0
                i += 1
            end
        end
    end
    
    return lps
end

# Driver Code
puts "Enter the text:"
text = gets.chomp

puts "Enter the pattern:"
pattern = gets.chomp

kmp_search(pattern, text)

=begin
Enter the text:
namanchamanbomanamansanam

Enter the pattern:
aman

Output

Pattern found at 2
Pattern found at 8
Pattern found at 17
=end

=begin
Rabin–Karp algorithm is a string-searching algorithm that uses
hashing to find any one of a set of pattern strings in a text.
=end

PN = 101 # prime number
AN = 256 # no. of characters in alphabet

def search(pattern, text)
    patlen = pattern.length # pattern length
    txtlen = text.length # text length
    val = 1
    hpat = 0 # pattern hash value
    htxt = 0 # text hash value

    for i in 0..(patlen - 2)
        val = (val * AN) % PN # PN is a prime number
    end
    
    for i in 0..(patlen - 1)
        hpat = (AN * hpat + pattern[i].ord) % PN
        htxt = (AN * htxt + text[i].ord) % PN
    end
    
    for i in 0..(txtlen - patlen)
        if (hpat == htxt)
            # check for patterns
            for j in 0..(patlen - 1)
                if (text[i + j] != pattern[j])
                    break
                end
                
                j += 1
                
                if (j == patlen)
                    puts "Found at index starting from #{i}"
                end
            end
        end
        
        # Calculate the new pattern including i+m
        if (i < txtlen - patlen)
            htxt = (AN * (htxt -  text[i].ord * val) + text[i + patlen].ord) % PN
            
            if (htxt < 0)
                htxt = htxt + PN
            end
        end
    end
end

# Driver program
puts "Enter the text:"
text = gets.chomp

puts "Enter the pattern:"
pattern = gets.chomp

search(pattern, text)

=begin
Enter the text:
XWINGO XOR WINGO

Enter the pattern:
WINGO

Output
Found at index starting from 1
Found at index starting from 11
=end

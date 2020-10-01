def search (text, pattern)
  for i in (0 .. text.length - pattern.length)
    j = 0
    while j < pattern.length
      if text[i+j] != pattern[j]
        break
      end
        j += 1
    end
    if j == pattern.length
      puts("Pattern found at " + (i+1).to_s)
    end
  end
end

text = "random variables are so random"
pattern = "ran"
search(text,pattern)

# Output
# Pattern found at 1
# Pattern found at 25

def gcdFunction(a, b)
  if a == 0
    return b
  end
  return gcdFunction(b % a, a)
end

def power(x, y, m)
  if y == 0
    return 1
  end

  p = power(x, (y/2).to_i, m) % m
  p = (p * p) % m

  if y % 2 == 0
    return p
  else
    return (x * p) % m
  end
end

def modInverse(a, m)
  gcd = gcdFunction(a, m)

  if gcd != 1
    return -1
  else
    return power(a, m - 2, m)
  end
end

a = 3
m = 11

ans = modInverse(a, m)

if ans == -1
  puts "Inverse doesn't exist"
else
  puts "Modular multiplicative inverse is " + ans.to_s
end

# OUTPUT

# Modular multiplicative inverse is 4

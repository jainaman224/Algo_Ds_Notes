def sieve(max)
    # Set up an array with all the numbers from 0 to the max
    primes = (0..max).to_a
  
    # Set both the first and second positions (i.e., 0 and 1) to nil, as they
    # aren't prime.
    primes[0] = primes[1] = nil
    
    # Iterate through primes array
    counter = 0
    primes.each do |p|
      # Skip if nil
      next unless p
  
      # Break if we are past the square root of the max value 
      break if p*p > max
      counter += 1
      # Start at the square of the current number, and step through.
      # Go up to the max value, by multiples of the current number, and replace
      # that value with nil in the primes array
      (p*p).step(max,p) { |m| primes[m] = nil }
    end
  
    # Finally, return the compacted array.
    puts "Solved for #{max} in #{counter} steps."
    primes.compact
  end
  
  def prime?(num)
    sieve(num).include?(num)
  end
  
   # Checks whether a given number say 105557 is prime or not
  puts prime?(105557)
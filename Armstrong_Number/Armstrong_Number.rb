    #A positive integer of n digits is called an Armstrong number of order n (order is number of digits) if
    #abcd... = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + .... 
    
    #To calculate the order of the number
      def order(num)
          # variable to store of the number 
          count = 0
          while (num != 0) 
                  count = count + 1
          num = num / 10
        end
        return count 
      end
    
    # Function to check whether the given number is 
    # Armstrong number or not 
    def Armstrong (num) 
        count = order(num) 
        temp = num 
        sum1 = 0
        while (temp != 0)
                d = temp % 10
                sum1 = sum1 + d**count
        temp = temp / 10
        end
    
        # If condition satisfies 
      boolean=false
    
      if (num != sum1)
            return boolean
      else if(num == sum1)
            boolean=true
            return boolean 
      end 
      end
    end
    
    # Driver Program 
    num = 153
    print(Armstrong(num))
    
    #True
    
    num = 134
    print(Armstrong(num))
    
    #False 

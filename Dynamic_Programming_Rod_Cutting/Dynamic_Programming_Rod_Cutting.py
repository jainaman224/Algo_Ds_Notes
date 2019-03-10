'''Function to calculate maximum profit'''
def SellRod(n,prices):
    if(n == 1):
         #base case
         return prices[1]

    #The profit if you sell the rod as is  
    noCut = prices[n]
    
    #The prices for the different cutting options, set to -1.
    yesCut = [-1 for x in range(n)]

    for i in range(1, n):
        if(solutions[i] == -1):
        
          '''We haven't calulated solution for length i yet.
             We know we sell the part of length i,
             so we get prices[i].
             We just need to know how to sell rod of length n-i.'''
            yesCut[i] = prices[i] + SellRod(n-i)
            
        else:
        
         '''We have calculated solution for length i.
            We add the two prices.'''
            yesCut[i] = prices[i] + solutions[n-i]
        
     '''We need to find the highest price in order
        to sell more efficiently.
        We have to choose between noCut and
        the prices in yesCut.'''
        
        maxProfit = noCut #Initialize max to noCut
        for i in range(n):
            if(yesCut[i] > maxProfit):
                maxProfit = yesCut[i]
        
        solutions[n] = maxProfit
        return maxProfit

    
'''Driver Program to test the above function
   
   Input
   
        n : size of price array - 1
   prices : Price array
   
   
   Output
      return : maximum profit    '''

n = 8
prices = [1, 5, 8, 9, 10, 17, 17, 20] 
solutions = [-1 for x in range(size+1)]
print("Maximum profit is", SellRod(size-1,))

'''Output
  Maximum profit is 30 '''

      
      
      
   
   
   
    
    

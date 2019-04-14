## Dynamic Programming - Rod Cutting
We are given a rod of length n and we want to sell it. In order to sell it, we can either sell it as is or cut it into 
pieces and sell them separately. The selling price is directly dependent on the length of the piece. <br><br>
The only restriction is that we can only cut the rod into pieces of integer length. <br><br>
We are also given an array of prices, also of length n. This array contains the price for selling a rod at a certain length.
For example, prices[5] shows the price we can sell a rod of length 5. Generalising, prices[x] shows the price a rod of 
length x can be sold.We are tasked to find the optimal solution to sell the given rod and prices array.
### Approach

When we receive a rod of length n, we have two options:
 - Don’t cut it and sell it as is (receiving prices[n]).
 - Cut it and sell it in two parts. One part the length we cut it and the other the rod we are left with,
 which we have to try and sell separately. How though are we cutting the rod? We are cutting it in two parts, 
 so one will have length, say, i and the other length n-i. We need to check which cut gives the greatest profit
 of all the possible cuts.
 - Choose the maximum price of the two. 

The function representing our approach is the following:<br>
  
  **Profit(n) = Max{ Price(n), Price(i) + Profit(n-i) }** <br> <br>
Now we need to find our base case. For that, we will look at our restriction. We can only cut our rod in integer bits.
So the smallest length we can get is 1. One could say that the smallest length of a rod is 0, but that case is not possible
as rod of length 0 means that we don’t have a rod.<br><br>
So, if we get a rod of length 1, we can only sell it as is. The profit of this sale is prices[1].<br><br>
We have developed the method we will follow and we have found our base case, so we can head right into the code.
### Implementation
First, we need to initialize the array that will hold the solutions for the different lengths. 
The values of this array will be initialized at -1 and we will update them every time we find a better solution.
We chose -1 so that we can easily check if we have found a solution for the given length.<br><br>
Moreover, we will need our array of prices. The first value (for index=0) should be 0, as we cannot sell for 
profit a rod of no length. You can set the rest to any value you want, in any order. Ascending order makes 
intuitive sense; as the length increases so does the price. You don’t have to follow intuition though; 
be a rebel! (although another order might produce weird or trivial results)


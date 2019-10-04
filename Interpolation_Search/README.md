#  Interpolation Search

Interpolation sort is an improvement over binary search.  
Binary search always checks the value at the middle index. 
But interpolation search may check at the different locations based on the value of the element being searched.  
For interpolation search to work efficiently the array elements/data should be sorted and uniformly distributed. 

## Algorithm

Step 1: Make start = 0 & end = n-1<br />
Step 2: Calculate position(pos) to start searching at:<br /> 
`pos = start + ((end - start) / (Array[end] - Array[start])) * (element - Array[start])`<br />
Step 3: If Array[pos] == element, element found at the index pos.<br />
Step 4: Otherwise if element > Array[pos] make start = pos + 1 and repeat the same process <br />
Step 5: Else if element < Array[pos] make end = pos-1 and repeat the same process.

## Example

Find element : 4 

- Iteration 1 <br />
![Screenshot (162)](https://user-images.githubusercontent.com/28682701/58583702-3d6dcf00-8272-11e9-98c2-caea66db889b.png)

Array[1] < 4 hence start = 1 + 1 = 2 

- Iteration 2 <br />
![Screenshot (163)](https://user-images.githubusercontent.com/28682701/58584706-84f55a80-8274-11e9-99ee-47d62e591e73.png)

## Pseudocode
```
A → Array list
N → Size of A
X → Target Value

Procedure Interpolation_Search()

    Set Lo  →  0
    Set Mid → -1
    Set Hi  →  N-1

    While X does not match
       
        if Lo equals to Hi OR A[Lo] equals to A[Hi]
            EXIT: Failure, Target not found
        end if
      
        Set Mid = Lo + ((Hi - Lo) / (A[Hi] - A[Lo])) * (X - A[Lo]) 

        if A[Mid] = X
            EXIT: Success, Target found at Mid
        else 
            if A[Mid] < X
                Set Lo to Mid+1
            else if A[Mid] > X
                Set Hi to Mid-1
            end if
        end if
    End While

End Procedure
```
## Time complexity

If elements are uniformly distributed, then O (log log n). In worst case it can take upto O(n)
 
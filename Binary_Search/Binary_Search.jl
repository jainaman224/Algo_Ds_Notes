function Binary_Search(x,key)     #declared function
mid = Int(floor((1 + length(x))/2))  #calculating the mid of array
           try 
           if x[mid] == key      
           println("Key found")        # if key is found
           elseif x[mid]< key           #comparision to see if right side of key is to iterated
           Binary_Search(x[mid+1:end],key) #recursive call
           else x[mid]>key            #comparision to see if left side of key is to iterated
           Binary_Search(x[1:mid-1],key)  #recursive call
           end
           catch
           println("Key: $key not found") # else key is not found
           end
end

x = [1,4,6,8,9,19,56]
key = 10
Binary_Search(x,key) 

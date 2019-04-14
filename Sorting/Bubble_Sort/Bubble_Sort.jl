function bubble_sort(x) #function declaration	
	for i in range(1,length(x)-1) #outer for loop 
		for j in range(1,length(x)-1) #inner for loop	
            		if x[j]>x[j+1]  #comparison to test acesending
                		t=x[j]       #exchange of variable
                		x[j]=x[j+1]  # ...
                		x[j+1]=t     #using a second one
            		end
    		end
    end
    for i in range(1,length(x)) #loop for printing
        println(x[i])
    end
end


x = [1,4,6,8,7,9,5,6]
bubble_sort(x)

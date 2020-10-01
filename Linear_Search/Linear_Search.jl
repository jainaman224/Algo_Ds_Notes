function Linear_Search(x,key)
    if in(key,x) == true                                         #checking for key
        println("Key $key is found at postion $(find(x .==key))")
    else
        println("Key $key not found")
    end
end


x = [1,23,3,45,6,67]

Linear_Search(x,3)

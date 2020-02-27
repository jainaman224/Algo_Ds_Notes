def order(num)
    count=0
    while(num!=0)
        {
          count=count+1
          num=num/10
        }
    end
    return count
end

puts order(18)
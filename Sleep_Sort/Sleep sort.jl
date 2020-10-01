input = [3,2,4,7,3,6,9,1]
output = Int[]
 
@sync for i in input
    @async begin
        sleep(i)
        push!(output, i)
    end
end
 
@assert output == sort(input)
println(output)

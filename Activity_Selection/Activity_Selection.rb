start = [1,3,1,5,8,6]
finish = [2,6,6,7,10,8]

n = start.length()
def print_activities(start , finish , n)
  print "Following activities are selected \n "
  i = 0
  print (i.to_s + "\t")
  for j in 1..n-1
    if start[j]>finish[i]
      print (j.to_s + "\t")
      i = j
    end
  end
end

print_activities(start, finish , n)

=begin
input = [1,3,1,5,8,6]
Following activities are selected
0 1 4
=end

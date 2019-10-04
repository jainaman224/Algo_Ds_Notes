'''
The problem statement for Activity Selection is that "Given a set of n activities with their start and finish times, we need to select maximum number of non-conflicting activities that can be performed by a single person, given that the person can handle only one activity
at a time." The Activity Selection problem follows a Greedy approach.
'''

# Function to compute the activities to be chosen
def activitySelection(s, f ): 
    n = len(f)
	print("Following activities are selected:")
    i = 0
	#First Activity is always selected
    print(i)	
    for j in range(0,n): 
        if s[j] >= f[i]: 	#We select only those activities whose starting time is greater than equal to
            print(j) 		#finishing time of previously selected activity.
            i = j 

#The array of n elements where s[i] denotes starting time of ith activity			
s = [1, 3, 1, 5, 6, 8]
#The array of n elements where f[i] denotes finishing time of ith activity
f = [2, 6, 6, 7, 8, 10] 
# Call to activitySelection function
activitySelection(s, f)

'''
Input:
Start
1 3 1 5 6 8
Finish
2 6 6 7 8 10

Output:
Following activities are selected
 0 1 4 5
'''

''' Activity Seection in Python '''

def activitySelection(s, f ): 
    n = len(f)
    i = 0
    print(i)	#First Activity is always selected
    for j in range(0,n): 
        if s[j] >= f[i]: 	#We select only those activities whose starting time is greater than equal to
            print(j) 		#finishing time of previously selected activity.
            i = j 
  
s = [1, 3, 1, 5, 8, 6] #The array of n elements where s[i] denotes starting time of ith activity
f = [2, 6, 6, 7, 10, 8] #The array of n elements where s[i] denotes finishing time of ith activity
activitySelection(s, f)

''' Python 3
Output is 0 1 4 '''

'''
    JOB SEQUENCING ALGORITHM

    There are n tasks(job) given to perform. Each of them has a certain profit associated 
    with them. Also, there is a deadline given to every task. The tasks must be completed
    before their deadlines.
    The problem is to find the maximum profit we can achieve while satisfying all the conditions.

'''

n = 9
deadline = [5,4,3,3,4,5,2,3,7]
profit = [85,25,16,40,55,19,92,80,15]
jobs = []
maxDeadline = 0         #Maximum deadline among the jobs.
for i in range(0,n):
    jobs.append((profit[i],(deadline[i],i+1)))
    maxDeadline = max(maxDeadline,deadline[i])
jobs.sort(key=lambda x:x[0])    #Jobs are sorted according to their profits.
time = []
for i in range(0,maxDeadline+1):
    time.append(0)
for i in range(len(jobs)-1,-1,-1):  #We iterate over the jobs in decreasing order of the profit.
    for j in range(jobs[i][1][0],0,-1):
        if time[j]==0:      #We assign the job to the first available slot before it's deadline.
            time[j]=jobs[i][1][1]
            break

maxProfit = 0
for i in range(1,maxDeadline+1):
    print(time[i],end=" ")
    if time[i]==0:
        continue
    maxProfit = maxProfit + profit[time[i]-1]
print("")
print("Max profit : "+str(maxProfit))

'''
        Output : 4 7 8 5 1 0 9
        Max profit : 367
        where time[i] denotes the number of the job which is assigned to time i.
        time[i] = 0 denotes no job assigned to that time.
'''

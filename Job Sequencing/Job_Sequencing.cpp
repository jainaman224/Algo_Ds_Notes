/*
    JOB SEQUENCING ALGORITHM

    There are n tasks(job) given to perform. Each of them has a certain profit associated 
    with them. Also, there is a deadline given to every task. The tasks must be completed
    before their deadlines.
    The problem is to find the maximum profit we can achieve while satisfying all the conditions.

*/
#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ulint unsigned long long int
#define lint long long int
#define mp make_pair
#define pb push_back
#define f(x) for(lint i=0;i<x;i++)
#define fj(x) for(lint j=0;j<x;j++)
#define mod 1000000007
#define F first
#define S second
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


int main(){
    lint n=9;
    lint deadline[9] = {5,4,3,3,4,5,2,3,7};
    lint profit[9] = {85,25,16,40,55,19,92,80,15};
    vector<pair<lint,pair<lint,lint> > > jobs;
    lint maxDeadline = 0;       // Maximum deadline among the jobs.
    for(lint i=0;i<n;i++){
        jobs.push_back(make_pair(profit[i],make_pair(deadline[i],i+1)));
        maxDeadline = max(maxDeadline,deadline[i]);
    }
    sort(jobs.begin(),jobs.end());  // Jobs are sorted according to their profits.
    lint time[maxDeadline+1]={0};
    for(lint i=jobs.size()-1;i>=0;i--){ // We iterate over the jobs in decreasing order of the profit.
        for(lint j=jobs[i].second.first;j>=1;j--){ 
            if(time[j]==0){ // We assign the job to the first available slot before it's deadline.
                time[j]=jobs[i].second.second;
                break;
            }
        }
    }
    lint maxProfit = 0;
    for(lint i=1;i<=maxDeadline;i++){
        cout<<time[i]<<" ";
        if(time[i] == 0){
            continue;
        }
        maxProfit+=profit[time[i]-1];
    }
    cout<<endl;
    cout<<"Max profit : "<<maxProfit;
    /*
        Output : 4 7 8 5 1 0 9
        Max profit : 367
        where time[i] denotes the number of the job which is assigned to time i.
        time[i] = 0 denotes no job assigned to that time.
    */
    return 0;
}


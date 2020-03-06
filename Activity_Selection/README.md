# Activity Selection

Problem Statement : You are given n activities with their start and finish times. Select the maximum number of activities that can be done by a single person, considering that a person can work on a single activity at a time.

## EXAMPLE 

Consider the following 3 activities (A1,A2,A3) sorted by finish time.
     start[]  =  {5, 12, 14];
     finish[] =  {14, 25, 30};
    -- The person will start the first working on A1 at 5 unit time and finishes it on 14 unit time, 
    now he can't do A2 as its start time has already passed, 
    so he will start A3 at 14 unit time and finish it on 30 unit time.

    --Conclusion- A person can perform at most two activities. The maximum set of activities that can be executed is {0, 2} [ These are indexes in start[] and 
    finish[] ] i.e. activities A1 and A3 can be done.

## Pseudo code

By using greedy method, it is a 3 step process.
--Concept : We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.
    
    STEP 1 : Sort the activities according to their finish times.
    STEP 2 : Selece the first activity in the sorted array and print it.
    STEP 3 : For remaining activities, check if the start time of this activity is greater than or equal to the finish time of previously selected activity. If yes, then select it and print it.

## Complexity 

 Time complexity : 

        For a sorted input : O(n) , where n is the number of total activities.
        For an unsorted input : O(nlogn) , where n is the number of total activities.


## Implementation

- [C code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Activity_Selection/Activity_Selection.c)

- [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Activity_Selection/Activity_Selection.cpp) 

- [Dart Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Activity_Selection/Activity_Selection.dart)

- [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Activity_Selection/Activity_Selection.py)

- [Go Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Activity_Selection/Activity_Selection.go)

- [Ruby Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Activity_Selection/Activity_Selection.rb)

- [Java Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Activity_Selection/Activity_Selection.java)

- [JavaScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Activity_Selection/Activity_Selection.js)
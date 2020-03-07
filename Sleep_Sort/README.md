# Sleep Sort

   Sleep sort works by starting a separate task for each item to be sorted, where each task sleeps for an interval corresponding to the item's sort key, then emits the item. Items are then collected sequentially in time.
# Example
 Let’s assume  we have a laptop that’s  takes 1 seconds to work through each element.
 
 **INPUT: 10 8 6**
 
 - 1s  10
 - 2s: 8
 - 3s: 6
 - 9s:  print(6)  (6  wake up so print it)
 - 10s: print(8)  (8  wake up so print it)
 - 11s: print(10) (10 wake up so print it)
 
 **OUTPUT : 6 8 10**
 
 # Time complexity
 
 - Creating multiple threads is done internally by the OS using a priority queue (used for scheduling purposes). Hence inserting all the  array elements in the priority queue takes O(Nlog N) time.
 
- Also the output is obtained only when all the threads are processed, i.e., when all the elements ‘wakes’ up. Since it takes O(arr[i]) time to wake the ith array element’s thread. So it will take a maximum of O(max_element(array)) for the largest element of the array to wake up.

 - Thus overall time complexitu is ,O(NlogN + max(input)) 
 ("where, N = number of elements in the input array, and input = input array elements")
 
 # Limitations 
 -  This algorithm won’t work for negative numbers as a thread cannot sleep for a negative amount of time.
 
 # Sleep Sort Algorithm implementation in Python
      import threading
      import time

      _lk = threading.Lock()

      class SleepSortThread(threading.Thread):
         def __init__(self, val):
            self.val = val
            threading.Thread.__init__(self)

         def run(self):
            global _lk
            # Thread is made to sleep in proportion to value
            time.sleep(self.val * 0.1)
            # Acquire lock
            _lk.acquire()
            print(self.val, end = " ")
            # Release lock
            _lk.release()
            
         def SleepSort(list):
            ts = []
            # Intialize a thread corresponding to each element in list
            for i in list:
               t = SleepSortThread(i)
               ts.append(t)  
            # Start all Threads
            for i in ts:
               i.start()
            # Wait for all threads to terminate
          for i in ts:
            i.join()
            
         x = [2, 4, 3, 1, 6, 8, 4]
         x = SleepSort(x)
         
         # Output
         # 1 2 3 4 4 6 8

# Pseudocode

      procedure print(n)
         sleep n second
         print(n)
      end
      for arg in args
         run print(arg) in background 
      end
      
      wait for all processes o finish
     
[Reference: Geeksforgeeks](https://www.geeksforgeeks.org/sleep-sort-king-laziness-sorting-sleeping/)

[Reference: Wikipedia](https://it.wikipedia.org/wiki/Sleep_sort)

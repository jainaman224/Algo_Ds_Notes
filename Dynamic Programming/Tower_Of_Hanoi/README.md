# Tower of Hanoi
The Tower of Hanoi is one of the main application of *recursion*. It says "*if you can solve n-1 cases, then you can easily solve the nth case*".
Tower of Hanoi, is a mathematical puzzle which consists of three towers (pegs) and more than one rings is as depicted. These rings are of different sizes and stacked upon in an ascending order, i.e. the smaller one sits over the larger one. The problem is to move all these rings **from pole A to pole C using the pole B as spare pole** while maintaining the same order. The main issue is that the smaller disk must always come above the larger disk.
![ToH](https://blog-c7ff.kxcdn.com/blog/wp-content/uploads/2016/12/tower-01-1.jpg)

## Algorithm
**Base Case**: `if n=1`
- Move the ring from A to C using B as spare

**Recursive Case**:
- Move n-1 rings from A to B using C as spare
- Move the one ring left on A to C using B as spare
- Move n-1 rings from B to C using A as spare


## Illustration For 3 Disks 
![GIF](https://www.tutorialspoint.com/data_structures_algorithms/images/tower_of_hanoi.gif)


***For n disks, total 2^n^ – 1 moves are required.***

## Pseudocode
```
FUNCTION MoveTower(disk, source, destination, spare):
IF disk == 0, THEN:
    move disk from source to destination
ELSE:
    MoveTower(disk - 1, source, spare, destination)   // Step 1 above
    move disk from source to destination              // Step 2 above
    MoveTower(disk - 1, spare, destination, source)   // Step 3 above
END IF
```
When _disk_ is 0, the smallest disk. In this case we don't need to worry about smaller disks, so we can just move the disk directly. In the other cases, we follow the three-step recursive procedure we already described.

## Tree For Three Disks
![Tree for Three Disks](https://cdn-images-1.medium.com/max/1500/1*LEkUpm8-CoxGko2f84gjOg.jpeg)

## Implementation

*  [C Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Tower_Of_Hanoi/towerofhanoi.c)

> :rocket: [Compile Online](https://repl.it/@gauravburjwal/Tower-of-Hanoi-in-C) :rocket:

*  [C++ Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Tower_Of_Hanoi/Tower_Of_Hanoi.cpp)

> :rocket: [Compile Online](https://repl.it/@gauravburjwal/Tower-of-Hanoi-C) :rocket:
 
*  [JavaScript Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Tower_Of_Hanoi/Tower_Of_Hanoi.js)

> :rocket: [Compile Online](https://repl.it/@gauravburjwal/Tower-of-Hanoi-JS) :rocket:
  
*  [Python Code](https://github.com/jainaman224/Algo_Ds_Notes/blob/master/Tower_Of_Hanoi/Tower_Of_Hanoi.py)

> :rocket: [Compile Online](https://repl.it/@gauravburjwal/Tower-of-Hanoi-Python) :rocket:
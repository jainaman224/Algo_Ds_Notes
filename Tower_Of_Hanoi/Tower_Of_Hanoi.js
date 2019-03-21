//Tower of Hanoi problem using recursion

function TowerOfHanoi(num, source, destination, auxillary){
    if(num === 1){
        console.log(`Move disk 1 from rod ${source} to ${destination}`);
        return 0;
    }

    TowerOfHanoi(num-1, source, auxillary, destination);
    console.log(`Move disk ${num} from rod ${source} to ${destination}`);
    TowerOfHanoi(num-1, auxillary, destination, source);
}

var input = 3;
TowerOfHanoi (input, 'A', 'C', 'B'); //A, C, B are the name of rods
// A is source rod, B is auxillary rod, C is destination rod

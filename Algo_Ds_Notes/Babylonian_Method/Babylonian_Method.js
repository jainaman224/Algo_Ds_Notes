//    1. Start with an arbitrary positive start value num (the closer to the 
//        root, the better).
//    2. Initializing guess=1;
//    3. Gives the accuracy of decimal places
//    4. Do following until desired approximation is achieved.
//        a) Get the next approximation for root using average of num and guess
//        b) Set guess = number/guess */

//Function for square_root 
function square_root(number)
{
    var num = number;
    var guess = 1;
    var accuracy = 0.000001;
    while(num - guess > accuracy)
    {
        num = (num + guess)/2;
        guess = number / num;
    }
    return num;
}

//To check if function is working
var n = 3; 
var result = square_root(n).toFixed(6);
console.log(result);

//Output- 1.732051

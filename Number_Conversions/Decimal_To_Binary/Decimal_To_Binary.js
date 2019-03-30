//JS program to convert a decimal number to binary number 

// function to convert decimal to binary 
function decimalToBinary(number) {
    // array to store binary number 
    let binaryNum = [];

    // counter for binary array 
    var i;

    for (i = number; i > 0; i = parseInt(i / 2)) {
        binaryNum.push(i % 2);
    }
    return binaryNum.reverse().join("");
}

// Driver program to test above function 
decimalToBinary(29);

//OUTPUT
//'11101'

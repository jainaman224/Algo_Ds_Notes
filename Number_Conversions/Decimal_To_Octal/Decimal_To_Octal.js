//JS program to convert a decimal number to octal number 

// function to convert decimal to octal
function decimalToOctal(number) {
    // array to store octal number 
    let octalNum = [];

    // counter for octal array 
    var i;

    for (i = number; i > 0; i = parseInt(i / 8)) {
        octalNum.push(i % 8);
    }
    return octalNum.reverse().join("");
}

// Driver program to test above function 
decimalToOctal(29);

//OUTPUT
//'35'

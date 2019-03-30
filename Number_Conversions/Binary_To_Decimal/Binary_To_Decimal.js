// JS program to convert binary to decimal 
// Function to convert binary to decimal 
function binaryToDecimal(n) {
    var num = n;
    var decimal_value = 0;

    // Initializing base value to 1, i.e 2^0 
    var base = 1;

    var temp = num;
    while (temp > 0) {
        var last_digit = temp % 10;
        var digitValue = last_digit * base;
        decimal_value += digitValue;
        base = base * 2;
        temp = Math.floor(temp / 10);
    }
    return decimal_value;
}
// The main function 
function main() {
    var num = 101011101;
    console.log(binaryToDecimal(num));
}
main();


//OUTPUT
//349

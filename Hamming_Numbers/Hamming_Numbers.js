//Function for finding hamming numbers
function Hamming(n) {
    var succession = [1];
    var length = succession.length;
    var candidate = 2;
    while (length < n) {
        if (isHammingNumber(candidate)) {
            succession[length] = candidate;
            length++;
        }
        candidate++;
    }
    return succession;
}
//Function to check if a number is hamming number and if true return it.
function isHammingNumber(num) {
    while (num % 5 === 0) num /= 5;
    while (num % 3 === 0) num /= 3;
    while (num % 2 === 0) num /= 2;

    return num == 1;
}
//the value 20 in (Hamming(20)) can be changed to get more hamming numbers.
console.log(Hamming(20));

//OUTPUT
//[ 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16, 18, 20, 24, 25, 27, 30, 32, 36 ]

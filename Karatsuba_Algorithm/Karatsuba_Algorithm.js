/*
The Karatsuba Algorithm implements faster multiplication, 
than the traditional approach.
*/

const karatSuba = (num1, num2) => {

    // for single digit number multiply directly
    if (num1 < 10 || num2 < 10) {
        return num1 * num2;
    }

    let num1Str = num1.toString();
    let num2Str = num2.toString();
    let n = Math.min(num1Str.length, num2Str.length);
    let half = Math.round(n / 2);

    // divide num1 into two halves
    let num1_H = parseInt(num1Str.substring(0, num1Str.length - half));
    let num1_L = parseInt(num1Str.substring(num1Str.length - half, num1Str.length));

    // divide num2 into two halves
    let num2_H = parseInt(num2Str.substring(0, num2Str.length - half));
    let num2_L = parseInt(num2Str.substring(num2Str.length - half, num2Str.length));

    // using the KaratSuba Definition
    let s1 = karatSuba(num1_L, num2_L);
    let s2 = karatSuba(num1_L + num1_H, num2_L + num2_H);
    let s3 = karatSuba(num1_H, num2_H);
    let s4 = s2 - s3 - s1;

    // karatsuba formula for finding product
    let result = s3 * Math.pow(10, 2 * half) + s4 * Math.pow(10, half) + s1;

    return result;
};

// I/O and O/P Examples

// The result is: 83810205
console.log(karatSuba(12345, 6789));
console.log(12345 * 6789);

var number = prompt("Enter a number");
var numberOfDigits = number.length;
var sum = 0;

for (i = 0; i < numberOfDigits; i++) {
  sum += Math.pow(number.charAt(i), numberOfDigits);
}
 
if (sum == number) {
  alert("The entered number is an Armstrong number.");
  
} else {
  alert("The entered number is not an Armstrong number.");
}

/*Enter a number 153
The entered number is an Armstrong number.*/
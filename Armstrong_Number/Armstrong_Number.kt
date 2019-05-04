//Function to get Number of Digits in given Number
fun order(Num: Int):Int {
    var count = 0
    var num = Num
    while(num > 0) {
        num /= 10
        count += 1
    }
    return count
}

//Function to check Armstrong Number
fun armstrong(Num: Int, digits: Int):Int {
    var sum = 0
    var num = Num
    while(num > 0) {
        var digit = num % 10
        var power = powerCalculator(digit, digits)
        sum += power
        num /= 10
    }
    return sum
}

//For Calculating Power Of digits in Armstrong Number
fun powerCalculator(digit: Int, power: Int):Int {
    var product = 1
    var power = power
    while(power > 0) {
        product *= digit
        power -= 1
    }
    return product
}

//Driver Function for Armstrong Number
fun main() {
    //Let's Take We Have To Check for 371
    val number = 371
    val digits:Int = order(number)
    val armNum = armstrong(number, digits)
    if(armNum == number) {
        println("Number is an Armstrong Number")
    }
    else {
        println("Number is Not an Armstrong Number")
    }
}

//Output:- Armstrong Number

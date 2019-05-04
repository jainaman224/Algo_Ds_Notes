fun main() {
    //Let's take a number 36
    var num = 76
    var sqre = num * num
    var count = 0
    //Comparing Number and It's Square
    while(num > 0) {
        if(num % 10 != sqre % 10) {
            count++
        }
        num /= 10
        sqre /= 10
    }
    if(count >= 1) {
        println("Not an Automorpic Number")
    }
    else {
        println("Automorpic Number")
    }
}

//Output:- Automorphic Number

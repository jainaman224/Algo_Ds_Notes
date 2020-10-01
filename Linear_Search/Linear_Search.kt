//Function For Linear Search
fun Linear_Search(list: List<Int>, Num: Int):Int {
    //If number not found than return -1 otherwise return postion of that number.
    var foundAt:Int = -1
    for(number in 0 until list.size) {
        if(list[number] == Num) {
            foundAt = number
        }
    }
    return foundAt
}

//Driver Function For Linear Search
fun main(args:Array<String>) {
    val list = listOf(2, 7, 10, 45, 60, 5)
    val position: Int
    //Let 45 to be searched
    position = Linear_Search(list, 45)
    if(position == -1) {
        println("Number Not Found")
    }
    else {
        println("Number Found at position ${position + 1}")
    }
    //Now search for 1
    val position1: Int
    position1 = Linear_Search(list, 1)
    if(position1 == -1) {
        println("Number Not Found")
    }
    else {
        println("Number Found at position ${position1 + 1}")
    }
}

//Output:-
// Number Found at position 4
// Number Not Found

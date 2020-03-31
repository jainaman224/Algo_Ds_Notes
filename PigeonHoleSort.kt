import java.util.*

fun main(args: Array<String>) {

    var n: Int = Integer.valueOf(readLine())    // taking input for size of the array
    var arr = arrayOfNulls<Int>(n)              // declaring arr of size n
    var read= Scanner(System.`in`)          
    for(i in 0..(n-1)){
        arr[i] = read.nextInt()                 //input value of each array element
    }   
    var min = arr[0]                            //min element in the array
    var max = arr[0]                            //max element in the array
    //finding the minimum and maximum elements in the array
    for(i in 0..(n-1)){
        if(arr[i]!! < min!!)
            min = arr[i]
        if(arr[i]!! > max!!)
            max = arr[i]
    }

    var noOfPigeonHoles = max!! - min!! + 1     //size of the pigeonhole array
    var pigeonHoles = IntArray(noOfPigeonHoles) //pigeonhole array
    Arrays.fill(pigeonHoles,0)                  //initializing all the elements to 0

    //pigeonhole sort algorithm

    for(i in 0..(n-1)){
        var x = arr[i]!! - min                  
        pigeonHoles[x]++
    }
    var index = 0
    
    for(i in 0..(noOfPigeonHoles-1)){
        while(pigeonHoles[i] > 0){
            arr[index++] = i + min
            pigeonHoles[i]--
        }
    }
    
    //printing the array

    println("Sorted Array")
    for(i in 0..(n-1)){
        println(arr[i])
    }
}
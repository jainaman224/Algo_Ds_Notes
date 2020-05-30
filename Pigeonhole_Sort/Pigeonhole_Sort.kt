import java.util.*

fun main(args: Array<String>) {

    var n: Int = Integer.valueOf(readLine())    
    var arr = arrayOfNulls<Int>(n)              
    var read = Scanner(System.`in`)          
    for(i in 0..(n-1)){
        arr[i] = read.nextInt()                 
    }   
    var min = arr[0]                            
    var max = arr[0]                            
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

/*
Sample Input
5
1 5 4 2 0
Sample Output
Sorted Array
0 
1 
2 
4 
5
*/

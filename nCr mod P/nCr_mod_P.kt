import java.util.*

// Function for nCr
fun nCr(n: Int, r: Int, mod: Int):Int {
    if(n < r) {
        return -1
    }
    var pascal = IntArray(r + 1)
    pascal[0] = 1
    for (i in 1 until r + 1) {
        pascal[i] = 0
    }

    // We use the known formula nCr = (n-1)C(r) + (n-1)C(r-1) for computing the values.
    for (i in 1 until n + 1) {
        var k: Int
        if (i < r) {
            k = i
        }
        else {
            k = r
        }
        for (j in k downTo 1) {
            pascal[j] = (pascal[j] + pascal[j - 1]) % mod
        }
    }
    return pascal[r]
}

fun main() {
    val scanner = Scanner(System.`in`)
    println("Please Enter Three Integers.")
    var n = scanner.nextInt()
    var r = scanner.nextInt()
    var mod = scanner.nextInt()
    var ans = nCr(n, r, mod)
    if (ans == -1) {
        println("n can never be less than r.")
    }
    else {
        println("The value of nCr($n,$r) % $mod = $ans")
    }
}

// Input:- Please Enter Three Integers.
//         7 5 6
// Output:- The value of nCr(7,5) % 6 = 3

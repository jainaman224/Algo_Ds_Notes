package main
import "fmt"

func TowerOfHanoi(n int, source byte, destination byte, auxillary byte) {  
    if (n == 1) {  
        fmt.Printf("Move disk 1 from rod %c to rod %c \n", source, destination)  
        return 
    }  
    TowerOfHanoi(n - 1, source, auxillary, destination)  
    fmt.Printf("Move disk %d from rod %c to rod %c \n", n, source, destination)
    TowerOfHanoi(n - 1, auxillary, destination, source)
}  

func main() {
    var n int
    fmt.Print("Enter number of disks: ")
    fmt.Scan(&n) 
    // n = Number of disks 
    
    TowerOfHanoi(n, 'A', 'C', 'B') 
    // A, B and C are names of rods 
    // A is source rod, B is auxillary rod, C is destination rod
}

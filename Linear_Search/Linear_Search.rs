// Rust program for Linear Search
use std::io;

fn main() {
    println!(" Enter number of elements to be entered in the array ");
    let mut size = String::new();
    
    io::stdin().read_line(&mut size).expect("failed to read input.");
    let size: usize = size.trim_end().parse().expect("invalid input");
    let mut vector: Vec<usize> = Vec::with_capacity(size as usize);
    
    println!("Enter element to be searched " );
    let mut element = usize::new();

    println!("Enter elements of array ");
    let mut index = 0;
    
    // Enter values into vector
    while index < size {
        index += 1;
        // Note: Rust takes spaces as non-intergral value
        let mut temp_arr = String::new();
        io::stdin().read_line(&mut temp_arr).expect("failed to read input.");
        let temp_arr: usize = temp_arr.trim_end().parse().expect("invalid input");
        vector.push(temp_arr);
    }
    
    // Linear Search process
    let mut checkpoint = 0;
    for index in 0..size - 1 {
        if element == vector[index]{
            checkpoint = 1;
            println!("Element is found at index ");
            println!("{:?}" , index + 1);
        }
    }
    
    if checkpoint == 0 {
        println!("Element is not found in the array ");
    }
}
/* 
TEST CASE
INPUT
 Enter number of elements to be entered in the array                                                        
3                     
Enter element to be searched 
2                                                                                                        
Enter elements of array                                                                                                       
1                                                                                                                             
2                                                                                                                             
3  
OUTPUT
Element is found at index 
2
INPUT
 Enter number of elements to be entered in the array                                                                          
3                     
Enter element to be searched 
5                                                                                                       
Enter elements of array                                                                                                    
1                                                                                                                             
2                                                                                                                             
3  
OUTPUT
Element is not found in the array 
*/


// Rust program for Selection Sort
use std::io;

fn main() {
    println!(" Enter number of elements to be entered in the array ");
    let mut size = String::new();
    
    io::stdin().read_line(&mut size).expect("failed to read input.");
    let size: usize = size.trim_end().parse().expect("invalid input");
    
    let mut vector: Vec<usize> = Vec::with_capacity(size as usize);
    
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
    
    for index in 0..size - 1 {
        let mut minimum = index;
        let mut j = index + 1;
        while j < size {
            if vector[j] < vector[minimum] {
                minimum = j;
                j += 1;
            }
            // Swapping the smallest number in vector with the indexth location number
            let temp = vector[minimum];
            vector[minimum] = vector[index];
            vector[index] = temp;
        }
    }
    
    println!("Sorted array is ");
    for index in 0..size {
        println!("{:?}",vector[index]);
    }
}
/* 
TEST CASE

INPUT
 Enter number of elements to be entered in the array                                                                          
3                                                                                                                             
Enter elements of array                                                                                                       
3                                                                                                                             
2                                                                                                                             
1  

OUTPUT
Sorted array is                                                                                                               
1                                                                                                                             
2                                                                                                                             
3                                                                                                                     
*/


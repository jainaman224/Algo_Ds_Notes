// Program for Selection sort in Rust

// io package is used for standard input/output
use std::io;

fn main() {
    println!("Enter number of elements for array: ");
    let mut n = String::new();
    
    io::stdin().read_line(&mut n).expect("failed to read input.");
    let n: usize = n.trim_end().parse().expect("invalid input");
    
    // Array cannot be used since it's size is to be determined at compile time
    let mut vector: Vec<usize> = Vec::with_capacity(n as usize);
    
    println!("Enter values to be sorted: ");
    let mut i = 0;
    
    // Loop to enter values into the vector
    while i < n {
        i += 1;
        // Enter values one by one (i.e, new line separated and not space separated) as
        // Rust counts it as a single input and takes spaces as non-intergral value
        let mut a = String::new();
        io::stdin().read_line(&mut a).expect("failed to read input.");
        let a: usize = a.trim_end().parse().expect("invalid input");
        vector.push(a);
    }
    
    for i in 0..n-1 {
        let mut minimum = i;
        let mut j = i+1;
        while j < n {
            if vector[j] < vector[minimum] {
                minimum = j;
                j += 1;
            }
            // Swapping the smallest number in vector with the ith location number
            let temp = vector[minimum];
            vector[minimum] = vector[i];
            vector[i] = temp;
        }
    }
    
    println!("Sorted array is: ");
    for i in 0..n {
        println!("{:?}",vector[i]);
    }
}
/* Output:
    Enter number of elements for array:                                                                                             
    5                                                                                                                               
    Enter values to be sorted:                                                                                                      
    9                                                                                                                               
    7                                                                                                                               
    6                                                                                                                               
    5                                                                                                                               
    4                                                                                                                               
    Sorted array is:                                                                                                                
    4                                                                                                                               
    5                                                                                                                               
    6                                                                                                                               
    7                                                                                                                               
    9                                                                                                                               
*/

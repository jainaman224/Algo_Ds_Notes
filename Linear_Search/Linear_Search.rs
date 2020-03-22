use std::io;

fn linear_search<T: Ord>(vec: &Vec<T>, key: &T) -> Option<usize> {  
    let mut result: Option<usize> = None;
    for (i, n) in vec.into_iter().enumerate() {
        if n == key {
            result = Some(i)
        }
    };
    result
} 

fn main() {
    println!("Enter 5 elements :- ");
    let mut input = String::new();
    let mut some_vec = vec![];
    for i in 0..5 {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Error reading input");
        let my_int: i32 = input.trim().parse().expect("Not a valid number");
        some_vec.push(my_int);
    }
    println!("Enter the element to be searched in the array :- ");    
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Error reading input");
    let my_int: i32 = input.trim().parse().expect("Not a valid number");
    
    match linear_search(&some_vec, &my_int) {
        Some(val) => println!("The element is present at index: {}", val),
        None => println!("The element is not present")
    };
    /* Sample Input :-
        1
        2
        3
        4
        6
        Sample Output :-
        The element is present at index: 4
    */
}

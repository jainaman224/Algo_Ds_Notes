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
    let some_vec = vec![1,2,3,4,5,6,7,8,9,10]; 
    match linear_search(&some_vec, &6) {
        Some(val) => println!("The element is present at index: {}", val),
        None => println!("The element is not present")
    }; 
}

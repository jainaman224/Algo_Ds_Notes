use std::io;
use std::str::FromStr;

fn main() {
    println!("Enter the numbers to be sorted (separated by space) : ");
    let mut i = read_values :: <i32>().unwrap();
    insertion_sort(&mut i);
    println!("Sorted array: {:?}", i)
}

fn insertion_sort(arr: &mut Vec<i32>) {
    for i in 1..arr.len()  {
        let mut j = i;
        while j > 0 && arr[j] < arr[j - 1] {
            arr.swap(j, j - 1);
            j = j - 1;
        }
    }
}

fn read_values<T: FromStr>() -> Result<Vec<T>, T::Err> {
    let mut s = String::new();
    io::stdin()
        .read_line(&mut s)
        .expect("could not read from stdin");
    s.trim()
        .split_whitespace()
        .map(|word| word.parse())
        .collect()
}

/*

Sample Input :
    Enter the numbers to be sorted (separated by space) :                                                                         
    45 34 112 50 91                                                                                                               

Sample Output :
    Sorted array: [34, 45, 50, 91, 112]

*/


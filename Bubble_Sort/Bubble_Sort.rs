use std::io;
use std::str::FromStr;

fn main() {
    println!("Enter the numbers to be sorted (separated by space) : ");
    let i = read_values::<i32>().unwrap();
    let a = bubble_sort(i);
    println!("Sorted array: {:?}", a)
    }

fn bubble_sort(mut a: Vec<i32>) -> Vec<i32> {
    for _ in 0..a.len() {
        let mut flag = false;
        for j in 0..a.len() - 1 {
            if a[j] > a[j + 1] {
                let temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = true
            }
        }
        if !flag {
            break;
        }
    }
    a
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

    Output :
    Enter the numbers to be sorted (separated by space) : 
    5 2 8 6 89
    Sorted array: [2, 5, 6, 8, 89]
	
*/


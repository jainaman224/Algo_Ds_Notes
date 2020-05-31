use std::io;
use std::str::FromStr;

fn main() {
    println!("Enter the numbers to be sorted (separated by space) : ");
    let mut array: Vec<u32> = read_values :: <u32>().unwrap();
    quicksort(&mut array, 0, array.len() - 1);
    println!("The sorted array is : {:?}", array);
}

fn quicksort(array: &mut[isize], first: usize, last: usize) {
    if first < last {
        let midpoint = partition(array, first, last);
        quicksort(array, first, midpoint - 1);
        quicksort(array, midpoint + 1, last);
    }
}

fn partition(array: &mut[isize], first: usize, last: usize) -> usize {
    let pivot = array[last];
    let i: isize = first as isize;
    let mut i: isize = i - 1;
    let mut j = first;
    while j < last - 1 {
        if array[j] < pivot {
            i = i + 1;
            let k: usize = i as usize;
            swap(array, k, j);
        }
        j = j + 1;
    }
    let k: isize = i + 1;
    let k: usize = k as usize;
    if array[last] < array[k] {
        swap(array, k, last);
    }
    return k;
}

fn swap(array: &mut[isize], a: usize, b: usize) {
    let temp = array[a];
    array[a] = array[b];
    array[b] = temp;
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
    Sample Input :
    Enter the numbers to be sorted (separated by space) :                                                                         
    45 23 15 80 5 

Sample Output :	
    The sorted array is : [5, 15, 23, 45, 80]
*/


use std::io;
use std::str::FromStr;

fn main() {
    println!("Enter the numbers to be sorted (separated by space) : ");
    let mut arr: Vec<u32> = read_values::<u32>().unwrap();
    radix_sort(&mut arr);
    println!("The sorted array is : {:?}", arr);
}

fn radix_sort(input: &mut [u32]) {
    if input.len() == 0 {
        return;
    }

    let mut buckets: Vec<Vec<u32>> = Vec::with_capacity(10);    // initialize buckets
    for _ in 0..10 {
        buckets.push(Vec::new());
    }

    let count: usize = input.iter()    // count how many digits the longest number has
        .max()
        .unwrap()
        .to_string()
        .len();
    let mut divisor: u32 = 1;

    for _ in 0..count {
        for num in input.iter() {
            let temp = (num / divisor) as usize;
            buckets[temp % 10].push(*num);
        }

        let mut j: usize = 0;
        for k in 0..10 {
            for x in buckets[k].iter() {
                input[j] = *x;
                j += 1;
            }
            buckets[k].clear();
        }
        divisor *= 10;
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
    45 23 15 80 5 

Sample Output :	
    The sorted array is : [5, 15, 23, 45, 80]
	
*/


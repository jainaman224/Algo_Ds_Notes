/*
            Rust Program to implement Merge Sort  
     --------------------------------------------------------            
                    Merge Sort 
     --------------------------------------------------------            
Merge sort is a divide-conquer-combine algorithm based on the idea of breaking down a list into several sub-lists .
The list is broken into sublists until each sublist consists of a single element and merging those sublists in a 
manner that results into a sorted list.

The idea is :
    -> Divide the unsorted list into N sublists, each containing 1 element.
    -> Take adjacent pairs of two singleton lists and merge them to form a list of 2 elements.N will now convert
       into N/2 lists of size 2.
    -> Repeat the process till a single sorted list of size N is obtained.

Complexity Analysis :

The list of size N is divided into a max of logN parts, and the merging of all sublists into a single list takes O(N) time.
The worst case run time of this algorithm is O(NlogN) .
The average and best case run time of this algorithm is N(logN) .
The space complexity of this algorithm is N .
*/


use std::io;
use std::str::FromStr;

fn main() {
    println!("Enter the numbers to be sorted (separated by space) : ");
    let mut i = read_values::<i32>().unwrap();
    merge_sort(&mut i);
    println!("Sorted array: {:?}", i)
    }

fn merge_sort(a: &mut Vec<i32>) {
    let size = a.len();
    let mut buffer = vec![0; size];
    merge_split(a, 0, size, &mut buffer);
}

fn merge_split(a: &mut Vec<i32>, start: usize, end: usize, buffer: &mut Vec<i32>) {
    if end - start > 1 {
        // Determine the split index
        let split = (start + end) / 2;
		
		// Split and merge sort
        merge_split(a, start, split, buffer);
        merge_split(a, split, end, buffer);
        merge(a, buffer, start, split, end);
        merge_copy(buffer, a, start, end);
    }
}

fn merge(src: &Vec<i32>, dest: &mut Vec<i32>, start: usize, split: usize, end: usize) {
    // Define cursor indices for the left and right part that will be merged
    let mut left = start;
    let mut right = split;

    // Merge the parts into the destination in the correct order
    for i in start..end {
        if left < split && (right >= end || src[left] <= src[right]) {
            dest[i] = src[left];
            left += 1;
        } else {
            dest[i] = src[right];
            right += 1;
        }
    }
}

fn merge_copy(src: &Vec<i32>, dest: &mut Vec<i32>, start: usize, end: usize) {
    (start..end).for_each(|i| dest[i] = src[i]);
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
    76 56 45 3 1 4
    
    Sample Output :
    
    Sorted array: [1, 3, 4, 45, 56, 76]    
*/


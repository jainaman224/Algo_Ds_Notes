/* Problem Statement : Find all occurrences of 
 * a pattern in a string in linear time O(m+n)
 * where m is the length of the pattern and n
 * is the length of the string.*/

use std::io::{stdin, stdout, Write};
use std::convert::TryInto;

fn z_array(zstring: &Vec<char>) -> Vec<u32> {
    let z_length = zstring.len();
    let mut z_arr = vec![0u32; z_length];
    z_arr[0] = 1;
    let mut index = 1;
    let mut var_ind = 0;
    let mut left = 0; let mut right = 0;
    /* To form the z array, run two loops from the beg of the 
     * array, match the char at that index for the outer loop 
     * with the char at index in the inner loop. If they match, 
     * move both of the indices forward, calculate the max length 
     * til which they match. */
    while index < z_length {

        if index > right {
            left = index; right = index;

            while right < z_length && 
                zstring[right - left] == zstring[right] {
                right += 1;
            }
            z_arr[index] = (right - left).try_into().unwrap();
            right -= 1;
        }
        else {
            var_ind = index - left;

            if z_arr[var_ind] < ((right - index + 1).try_into().unwrap()) {
                z_arr[index] = z_arr[var_ind];
            }
            else {
                left = index;
                while (right < z_length && 
                    zstring[right - left] == zstring[right]) {
                    right += 1;
                }

                z_arr[index] = (right - left).try_into().unwrap();
                right -= 1;
            }
        }
        index += 1;
    }

    z_arr
}

fn search_the_pattern(strng :&str, pattern :&str) {
    let strng: Vec<char> = strng.chars().collect();
    let pattern: Vec<char> = pattern.chars().collect();
    let mut z_string = Vec::with_capacity(strng.len() + pattern.len());
    let pattern_length = pattern.len();
    z_string.extend(pattern);
    z_string.push('$');
    z_string.extend(strng);
    let z_array = z_array(&z_string);

    // Go through the z array, if at any index value is equal to the
    // length of the pattern, the pattern appears in the string.
    for index in pattern_length + 1.. z_array.len() - 1 {
        if z_array[index] as usize == pattern_length {
            println!("Pattern found at index : {}", index - pattern_length - 1); 
        }
    }

}

fn main() {
    println!("Enter the string :");
    let mut strng = String::new();
    //let _ = stdout().flush();
    stdin().read_line(&mut strng).expect("Error in string input.");
    let strng: String = strng.trim().parse().unwrap();
    let strng: &str = &*strng;
    
    let mut pattern = String::new(); // make a mutable string variable
    println!("Enter the pattern :");
    stdin().read_line(&mut pattern).expect("Error in pattern input.");
    let pattern: String = pattern.trim().parse().unwrap();
    let pattern: &str = &*pattern;
    //let tokens:Vec<&str>= strng.split(",").collect();

    // Call the driver function with the string and the pattern
    search_the_pattern(strng, pattern);
}

/* Example :
 * Enter the string :
The thesis was defended there then.
Enter the pattern :
the
Pattern found at index : 4
Pattern found at index : 24
Pattern found at index : 30
*/

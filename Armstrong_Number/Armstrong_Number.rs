// Armstrong number in Rust
// 'N' is an armstrong number of 'l' digits if it is of the form
// N = N1^l + N2^l + N3^l + ... + Nl^l
// where Nk is the kth digit in N.

use std::io;

fn main(){
    println!("Enter a number: ");
    let mut nums = String::new();

    io::stdin()
        .read_line(&mut nums)
        .expect("Failed to read line");
    
    let mut num : i32 = nums.parse().unwrap();
    let mut sum :i32 = 0;
    let mut temp : i32 = num;
    let mut len = 0;

    while temp > 0{
        len += 1;
        temp /= 10;
    }

    temp = num;
    
    while temp > 0{
        let mut tempp = temp % 10;
        sum += tempp.pow(len);
        temp /= 10;
    }
    if sum==num{
        println!("{} is an Armstrong number.", num);
    }
    else{
        println!("{} is not an Armstrong number.", num);
    }
}
// [Sample input 1] 
// Enter a number: 153
// [Sample output 1] 
// 153 is an Armstrong number.

// [Sample input 1] 
// Enter a number: 58
// [Sample output 1] 
// 58 is an Armstrong number.
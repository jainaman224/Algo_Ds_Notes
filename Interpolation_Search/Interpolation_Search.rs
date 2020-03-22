pub fn interpolation_search(arr: &[i32], target: &i32) -> Result<usize, usize> {
    // Handle empty sequence.
    if arr.is_empty() {
        return Err(0);
    }

    // Setup variable storing iteration informaion.
    // hi -> upper bound of search range.
    // lo -> lower bound of search range.
    // interpolant -> position to probe in the sequence
    let mut hi = arr.len() - 1;
    let mut lo = 0_usize;
    let mut interpolant = 0_usize;

    // Main loop to calculate the interpolant.
    loop {
        let lo_val = arr[lo];
        let hi_val = arr[hi];

        // Three condition to exit the loop
        //   a. hi and lo flag overlapping -> all elements are scanned.
        //   b. target value is less than the lowest value
        //   c. target value exceeds the highest value
        if hi <= lo || *target < lo_val || *target > hi_val  {
            break;
        }

        // The linear interpolation part
        let offset = (*target - lo_val) * (hi - lo) as i32 / (hi_val - lo_val);
        interpolant = lo + offset as usize;

        let mid_val = arr[interpolant];

        //  Comparison between the interpolant and targert value.
        // New boundaries must step one index further to avoid infinite searching.
        if mid_val > *target {
            hi = interpolant - 1;
        } else if mid_val < *target {
            lo = interpolant + 1;
        } else {
            break;
        }
    }

    if *target > arr[hi] {
        Err(hi + 1)
    } else if *target < arr[lo] {
        Err(lo)
    } else {
        Ok(interpolant)
    }
}

fn main() {
    // Taking input from user
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

    println!("{:?}", interpolation_search(&some_vec, &my_int));
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

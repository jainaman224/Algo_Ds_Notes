/// Heapsort.

pub fn heapsort(arr: &mut [i32]) {
   
                                                                     // This procedure would build a valid max-heap.
                                                                       // (or min-heap for sorting descendantly)
    let end = arr.len();
    for start in (0..end / 2).rev() {
                                                                                // Skip leaf nodes (end / 2).
        sift_down(arr, start, end - 1);
    }

                                                                                  // -- Sorting part --
                                                                               // Iteratively sift down unsorted part (the heap).
    for end in (1..arr.len()).rev() {
        arr.swap(end, 0);
        sift_down(arr, 0, end - 1);
    }
}

                                                           /// Internal function for heap to fix itself to conform to heap definition.

                                                                    /// Precondiition: all elements below `start` are in heap order

                                                                             /// expect `start` itself.

fn sift_down(arr: &mut [i32], start: usize, end: usize) {
    let mut root = start;
    loop {
        let mut child = root * 2 + 1;                                 // Get the left child
        if child > end {
            break;
        }
        if child < end && arr[child] < arr[child + 1] {
                                                                       // Right child exists and is greater.
            child += 1;
        }

        if arr[root] < arr[child] {
                                                                          // If child is greater than root, swap'em!
            arr.swap(root, child);
            root = child;
        } else {
            break;
        }
    }
}

#[cfg(test)]

mod base {
    use super::*;
    base_cases!(heapsort);
}

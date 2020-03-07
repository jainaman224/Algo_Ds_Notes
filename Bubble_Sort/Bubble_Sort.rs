fn bubble_sort(numbers: &Vec<i64>, compare_fn: |i64, i64| -> i64) -> Vec<i64> {
    let mut temp;
    let mut target = numbers.clone();
    let length = numbers.len();

    for _ in range(0, length) {
        for j in range(0, length - 1) {
            if compare_fn(target[j], target[j+1]) > 0  {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }

    target
}

 /*sample input: 2 3 4 5 6 7 1
output :1 2 3 4 5 6 7
*/

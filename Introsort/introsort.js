function swap(input, left, right){
    var temp = input[left];
    input[left] = input[right];
    input[right] = temp;
}


const insertion_Sort = (input) => {
    for (let i = 1; i < input.length; i++) {
        let j = i - 1
        let temp = input[i]
        while (j >= 0 && input[j] > temp) {
            input[j + 1] = input[j]
            j--
        }
        input[j+1] = temp
    }
    return input;
}


function partition(input, left, right,pivot) {
        i       = left, //left pointer
        j       = right; //right pointer
    while (i <= j) {
        while (input[i] < pivot) {
            i++;
        }
        while (input[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(input, i, j); //swapping two elements
            i++;
            j--;
        }
    }
    return i;
}

var array_length;

function heap_root(input, i) {
    var left = 2 * i + 1;
    var right = 2 * i + 2;
    var max = i;

    if (left < array_length && input[left] > input[max]) {
        max = left;
    }   

    if (right < array_length && input[right] > input[max])     {
        max = right;
    }

    if (max != i) {
        swap(input, i, max);
        heap_root(input, max);
    }
}


function heapSort(input) {
    
    array_length = input.length;

    for (var i = Math.floor(array_length / 2); i >= 0; i -= 1)      {
        heap_root(input, i);
    }

    for (i = input.length - 1; i > 0; i--) {
        swap(input, 0, i);
        array_length--;
    
        heap_root(input, 0);
    }
}


function medianof3(input, lo, mid, hi) {
    if (input[mid] < input[lo]) {
        if (input[hi] < input[mid]) {
            return input[mid];
            } else {
            return (input[hi] < input[lo]) ? input[hi] : input[lo];
        }
    } else {
        if (input[hi] < input[mid]) {
            return (input[hi] < input[lo]) ? input[lo] : input[hi];
        } else {
            return input[mid];
        }
    }
}
var size_threshold = 16;

function introsort_loop (input, lo, hi, depth_limit) {
    while (hi-lo > size_threshold) {
        if (depth_limit === 0) {
            heapsort(input, lo, hi);
            return;
        }
        depth_limit=depth_limit-1;
        var p = partition(input, lo, hi, medianof3(input, lo, lo+((hi-lo)/2)+1, hi-1));
        introsort_loop(input, p, hi, depth_limit);
        hi = p;
    }
    insertion_Sort(input, lo, hi);
}

var arr = [-1, 3, 6, 6, 5, 4, -9 ,9, 0, 2, 4, 1, 6, 7 ];
introsort_loop(arr,0,arr.length, (Math.log(arr.length))*2);
console.log(arr);

/*Output
[
  -9, -1, 0, 1, 2, 3,
   4,  4, 5, 6, 6, 6,
   7,  9
]
 */
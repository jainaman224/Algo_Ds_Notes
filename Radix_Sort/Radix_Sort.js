// helper function to get the last nth digit of a number
var getDigit = function (num, nth) {
    // get last nth digit of a number
    var remainder = 0;
    while (nth--) {
        remainder = num % 10
        num = Math.floor((num - remainder) / 10)
    }
    return remainder
}

// radixSort
function radixSort(list) {
    var max = Math.floor(Math.log10(Math.max.apply(Math, list))),
        //get the length of digits of the max value in this array
        digitBuckets = [],
        index = 0;

    for (var i = 0; i < max + 1; i++) {

        // rebuild the digit buckets according to this digit
        digitBuckets = []
        for (var j = 0; j < list.length; j++) {
            var digit = getDigit(list[j], i + 1);
            digitBuckets[digit] = digitBuckets[digit] || [];
            digitBuckets[digit].push(list[j]);
        }

        // rebuild the list according to this digit
        index = 0
        for (var t = 0; t < digitBuckets.length; t++) {
            if (digitBuckets[t] && digitBuckets[t].length > 0) {
                for (j = 0; j < digitBuckets[t].length; j++) {
                    list[index++] = digitBuckets[t][j];
                }
            }
        }
    }
    return list
}

var array = [76, 45, 89, 23, 9];
radixSort(array);

//OUTPUT
//[ 9, 23, 45, 76, 89 ]

//O(kn) where k is the number of bits required to represent the largest element in the array and n is the number of element

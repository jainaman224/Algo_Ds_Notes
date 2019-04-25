//Bucket sort is a distribution sort. It works by arranging elements into ‘buckets’ which are then sorted using another sort. This typically utilizes insertion sort then merged into a sorted list.Bucket sort is exceptionally fast because of the way elements are strategically assigned to buckets. This is normally through using an array where the index is the value. This means that there’s a higher cost of memory for the sake of speed.

### Pseudocode
1. Import some type of insertion sort to use in bucket sort function
2. Create bucketSort function (array, bucket size)
3. Create vars for i, min, max, and bucket size
4. Find min and max value
5. Create amount of buckets
6. Push values to correct buckets 
7. Sort buckets

//A implementation of bucket sort will work by splitting the array of size n into k buckets which holds a specific range of element values. These buckets will then be sorted using a sorting algorithm which can be chosen based on the expected input size.

// InsertionSort to be used within bucket sort
function insertionSort(array) {
  var length = array.length;
  
  for(var i = 1; i < length; i++) {
    var temp = array[i];
    for(var j = i - 1; j >= 0 && array[j] > temp; j--) {
      array[j+1] = array[j];
    }
    array[j+1] = temp;
  }
  
  return array;
}

// Implement bucket sort
function bucketSort(array, bucketSize) {
  if (array.length === 0) {
    return array;
  }

  // Declaring vars
  var i,
      minValue = array[0],
      maxValue = array[0],
      bucketSize = bucketSize || 5;
  
  // Setting min and max values
  array.forEach(function (currentVal) {
  	if (currentVal < minValue) {
  		minValue = currentVal;
  	} else if (currentVal > maxValue) {
  		maxValue = currentVal;
  	}
  })

  // Initializing buckets
  var bucketCount = Math.floor((maxValue - minValue) / bucketSize) + 1;
  var allBuckets = new Array(bucketCount);
  
  for (i = 0; i < allBuckets.length; i++) {
    allBuckets[i] = [];
  }
  
  // Pushing values to buckets
  array.forEach(function (currentVal) {
  	allBuckets[Math.floor((currentVal - minValue) / bucketSize)].push(currentVal);
  });

  // Sorting buckets
  array.length = 0;
  
  allBuckets.forEach(function(bucket) {
  	insertionSort(bucket);
  	bucket.forEach(function (element) {
  		array.push(element)
  	});
  });

  return array;
}



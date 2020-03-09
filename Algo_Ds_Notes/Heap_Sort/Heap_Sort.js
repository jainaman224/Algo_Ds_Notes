/**
 * Returns half the provided number
 *
 * @function parent
 * @param {number} number - Number to be halved
 * @return {number}
 *
 * Examples:
 *    parent(10)
 *    => 5
 */
function parent(number) {
  return Math.floor(number/2);
}

/**
 * Returns index corresponding to the left in a Heap
 *
 * @function left
 * @param {number} number - Number whose left is to be calculated
 * @return {number}
 *
 * Examples:
 *    left(10)
 *    => 20
 */
function left(number) {
  return 2 * number;
}

/**
 * Returns index corresponding to the right in a Heap
 *
 * @function parent
 * @param {number} number - Number whose right is to be calculated
 * @return {number}
 *
 * Examples:
 *    right(10)
 *    => 21
 */
function right(number) {
  return (2 * number) + 1;
}

/**
 * Returns half the provided number
 *
 * @function half
 * @param {number} number - Number to be halved
 * @return {number}
 *
 * Examples:
 *    half(10)
 *    => 5
 */
function half(number) {
  return parent(number);
}

/**
 * Returns half the provided number
 *
 * @extends Number
 * @function parent
 * @return {number}
 *
 * Examples:
 *    Number(10).parent();
 *    => 5
 */
Number.prototype.parent = function() {
  return Math.floor(Number(this)/2);
}

/**
 * Returns index corresponding to the left in a Heap
 *
 * @extends Number
 * @function left
 * @return {number}
 *
 * Examples:
 *    Number(10).left();
 *    => 20
 */
Number.prototype.left = function() {
  return 2 * Number(this);
}

/**
 * Returns index corresponding to the right in a Heap
 *
 * @extends Number
 * @function right
 * @return {number}
 *
 * Examples:
 *    Number(10).right();
 *    => 21
 */
Number.prototype.right = function() {
  return (2 * Number(this)) + 1;
}

/**
 * Returns half the provided number
 *
 * @extends Number
 * @function parent
 * @return {number}
 *
 * Examples:
 *    Number(10).half();
 *    => 5
 */
Number.prototype.half = function() {
  return Number(this).parent();
}

/**
 * Add a property to the Array object to track the heapSize of heap structure
 *
 * @extends Array
 * @property heapSize
 * @return undefined
 *
 * Examples:
 *    var arr = [];
 *    arr.heapSize = 10;
 *    => 10
 */
Array.prototype.heapSize = 0;

/**
 * Returns an array with elements populated between the specified range(INCLUSIVE)
 * in a REVERSE Order
 *
 * @extends Array
 * @function reverseRangeArray
 * @param {number} startIndex - Start element of the array to be built
 * @param {number} endIndex - End element of the array to be built
 * @return {array}
 *
 * Examples:
 *    (new Array()).reverseRangeArray(0, 5);
 *    ([]).reverseRangeArray(0, 5);
 *    => [5, 4, 3, 2, 1, 0]
 */
Array.prototype.reverseRangeArray = function(startIndex, endIndex) {
  var arr = []
  for(var i=endIndex; i>=startIndex; i--) {
    arr.push(i);
  }
  return arr;
}

/**
 * Ensures the max-heap property is being maintained from the index provided
 * Recursive, Max-Heap property A[parent] >= A[left] as well as A[right]
 *
 * @function maxHeapify
 * @param {array} arr - Input array
 * @param {number} i - Index at which the Max-Heap property is to be applied
 * @return undefined
 *
 * Examples:
 *    var arr = [5, 3, 8, 7, 9, 6, 2, 4, 1];
 *    maxHeapify(arr, 5)
 */
function maxHeapify(arr, i) {
  arr.heapSize = arr.heapSize || arr.length;

  var l = Number(i).left(), r = Number(i).right();

  var largest = (l <= arr.heapSize-1 && arr[l] > arr[i]) ? l : i;
  if (r <= arr.heapSize-1 && arr[r] > arr[largest]) {
    largest = r;
  }

  if(largest !== i) {
    [arr[i], arr[largest]] = [arr[largest], arr[i]];
    maxHeapify(arr, largest);
  }
}

/**
 * Re-order the input array to adhere to the Max-Heap property at all indices
 *
 * @function buildMaxHeap
 * @param {array} arr - Input array
 * @return undefined
 *
 * Examples:
 *    var arr = [5, 3, 8, 7, 9, 6, 2, 4, 1];
 *    buildMaxHeap(arr);
 */
function buildMaxHeap(arr) {
  arr.heapSize = arr.length;
  (new Array()).reverseRangeArray(0, Number(arr.length).half()).forEach(function(i) {
    maxHeapify(arr, i);
  });
}

/**
 * Sorts the array by adhering to the Max-Heap property and simulataneously
 * decreasing the heap size
 *
 * @function heapSort
 * @param {array} arr - Input array
 * @return {array}
 *
 * Examples:
 *    var arr = [5, 3, 8, 7, 9, 6, 2, 4, 1];
 *    heapSort(arr);
 *    => [1, 2, 3, 4, 5, 6, 7, 8, 9]
 */
function heapSort(arr) {
  buildMaxHeap(arr);
  (new Array()).reverseRangeArray(1, arr.length-1).forEach(function(i) {
    [arr[0], arr[i]] = [arr[i], arr[0]];
    arr.heapSize -= 1;
    maxHeapify(arr, 0);
  });
  return arr;
}

function unitTestHeap() {
  test("Max Heapify", maxHeapifyTest());
  test("Build Max Heap", buildMaxHeapTest());
  test("Heap Sort", heapSortTest())
}

function test(functionName, functionTest) {
  if(functionTest) {
    console.log(functionName + " OK");
  } else {
    console.log(functionName + " FAIL");
  }
}

function maxHeapifyTest() {
  var arr = [5, 3, 8, 7, 9, 6, 2, 4, 1];
  maxHeapify(arr, 2);
  return JSON.stringify(arr) === JSON.stringify([5, 3, 9, 7, 8, 6, 2, 4, 1]);
}

function buildMaxHeapTest() {
  var arr = [5, 3, 8, 7, 9, 6, 2, 4, 1];
  buildMaxHeap(arr);
  return JSON.stringify(arr) === JSON.stringify([9, 8, 6, 7, 3, 5, 2, 4, 1]);
}

function heapSortTest() {
  var arr = [5, 3, 8, 7, 9, 6, 2, 4, 1]
  return JSON.stringify(heapSort(arr)) === JSON.stringify([1, 2, 3, 4, 5, 6, 7, 8, 9]);
}

unitTestHeap();

/*
Function to find the length of longest incresing subsequence
input : an array of numbers
returns :length of longest increasing subsequence
*/

function lengthOfLIS(nums){

  //temporary array to save subsequence length values from that index
  var arr = Array(nums.length);
  //maxLen will store the result
  maxLen = 0;
  for(var i = 0 ; i< nums.length;i++){
    //iterate over the array to find values for each index
    let max = 0;
    for(var j = i-1;j>=0;j--){
      if(nums[i]>nums[j]){
        max = Math.max(max,arr[j])
      }
    }
    // add 1 because a subsequence of length 1 can always exist at any index
    arr[i] = max+1;
    //update maxLen if the value at the index i is greater than the current maxLen value
    maxLen = Math.max(maxLen,arr[i]);
  }

  return maxLen;
}

  //Examples

a1  = [1,2,3];
console.log("The length of longest increasing subsequence is : " +lengthOfLIS(a1));
// output :The length of longest increasing subsequence is : 3

a2 = [2,1,4,6,8,9,3];
console.log("The length of longest increasing subsequence is : " +lengthOfLIS(a2));
//output :The length of longest increasing subsequence is : 6

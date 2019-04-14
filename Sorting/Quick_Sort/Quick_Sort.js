function Quick_Sort(array, low, high){

  if( high - low <= 1){
        return;
  }

  var temp = low + 1;

  for(var i = low + 1; i < high; ++i ){
    if( array[i] < array[low] ){
      var t = array[temp];
      array[temp] = array[i];
      array[i] = t;
      temp++
    }
  }

  array[temp-1] = [array[low], array[low] = array[temp-1]][0];

  Quick_Sort(array, low, temp-1);
  Quick_Sort(array, temp, high);

}

array = [4, 3, 6, 9, 5, 1, 8, 7, 2];
Quick_Sort(array,0,array.length);
console.log(array)

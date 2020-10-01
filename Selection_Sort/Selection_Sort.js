function Selection_Sort(array){
  for( var i = 0; i < array.length; i++ ){
    var small = i;
    for( var j = i + 1; j < array.length; j++ ){
      if( array[j] < array[small]){
        small = j;
      }
    }
    if(i !== small){
      var temp = array[i];
      array[i] = array[small];
      array[small] = temp;
    }
  }
  return array;
}

array = [4, 3, 6, 9, 5, 1, 8, 7, 2];
console.log(Selection_Sort(array));

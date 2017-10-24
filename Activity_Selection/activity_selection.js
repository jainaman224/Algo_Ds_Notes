var activities = function(start, finish, length) {
  i = 0;
  console.log((i + 1) + " ");
  for(var j = 1; j < length; j++) {
    if(start[j] >= finish[i]) {
      console.log((j + 1) + " ");
      i = j;
    }
  }
}

var start = [1, 3, 1, 5, 8, 6];
var finish = [2, 6, 6, 7, 10, 8];

activities(start, finish, start.length);

// Output
// 1 2 5

//dijkstra algo uisng JavaScript
function solve(graph, s) {
  var solutions = {};
  solutions[s] = [];
  solutions[s].dist = 0;
  
  while(true) {
    var parent = null;
    var nearest = null;
    var dist = Infinity;
    
    //for each existing solution
    for(var n in solutions) {
      if(!solutions[n])
        continue
      var ndist = solutions[n].dist;
      var adj = graph[n];
      //for each of its adjacent nodes...
      for(var a in adj) {
        //without a solution already...
        if(solutions[a])
          continue;
        //choose nearest node with lowest *total* cost
        var d = adj[a] + ndist;
        if(d < dist) {
          //reference parent
          parent = solutions[n];
          nearest = a;
          dist = d;
        }
      }
    }
    
    //no more solutions
    if(dist === Infinity) {
        break;
    }
    
    //extend parent's solution path
    solutions[nearest] = parent.concat(nearest);
    //extend parent's cost
    solutions[nearest].dist = dist;
  }
  
  return solutions;
}
//create graph
var graph = {};

var layout = {
  'R': ['2'],
  '2': ['3','4'],
  '3': ['4','6','13'],
  '4': ['5','8'],
  '5': ['7','11'],
  '6': ['13','15'],
  '7': ['10'],
  '8': ['11','13'],
  '9': ['14'],
  '10': [],
  '11': ['12'],
  '12': [],
  '13': ['14'],
  '14': [],
  '15': []
}


for(var id in layout) {
  if(!graph[id])
    graph[id] = {};
  layout[id].forEach(function(aid) {
    graph[id][aid] = 1;
    if(!graph[aid])
      graph[aid] = {};
    graph[aid][id] = 1;
  });
}

var start = '10';

var solutions = solve(graph, start);

console.log("From '"+start+"' to");
for(var s in solutions) {
  if(!solutions[s]) continue;
  console.log(" -> " + s + ": [" + solutions[s].join(", ") + "]   (dist:" + solutions[s].dist + ")");
}

const points = [];
const hull = [];
const ele = document.querySelector('.content');
const table = document.querySelector('.table');

let leftMost;
let currentVertex;
let index;
let nextIndex = -1;
let nextVertex;

function setup() {
  createCanvas(800, 800);
  let buffer = Math.floor(Math.random()) * 50;
  for (let i = 0; i < 150;i++){
    points.push(createVector(random(buffer, width - buffer), random(buffer, width - buffer)));
  }
  points.sort((a, b) => a.x - b.x);
  leftMost = points[0];
  currentVertex = leftMost;
  hull.push(currentVertex);
  nextVertex = points[1];
  index = 2;
}

function draw() {
  window.addEventListener('click',()=>{
    setInterval(()=>{
      main();
    },4500)
  })
}

function main (){
  background(0);

  stroke(255);
  strokeWeight(8);
  for (let p of points) {
    point(p.x, p.y);
  }

  stroke(0, 100,95 );
  fill(0, 0, 100, 90);
  beginShape();
  for (let p of hull) {
    vertex(p.x, p.y);
  }
  endShape(CLOSE);

  stroke(0, 100, 95);
  strokeWeight(20);
  point(leftMost.x, leftMost.y);

  stroke(100, 0, 2);
  strokeWeight(20);
  point(currentVertex.x, currentVertex.y);

  stroke(0, 100, 80);
  strokeWeight(2);
  line(currentVertex.x, currentVertex.y, nextVertex.x, nextVertex.y);

  let checking = points[index];
  stroke(255);
  line(currentVertex.x, currentVertex.y, checking.x, checking.y);

  const a = p5.Vector.sub(nextVertex, currentVertex);
  const b = p5.Vector.sub(checking, currentVertex);
  const cross = a.cross(b);

  if (cross.z < 0) {
    nextVertex = checking;
    nextIndex = index;
  }

  index = index + 1;
  if (index == points.length) {
    if (nextVertex == leftMost) {
       hull.forEach((val)=>{
      const values =    document.createElement('span');
    values.textContent = `${val.x} , ${val.y}` ;
    table.appendChild(values);
  })
      console.log('hull created');
      noLoop();
      // displayHull();
    } else {
      hull.push(nextVertex);
      currentVertex = nextVertex;
      index = 0;
      //points.splice(nextIndex, 1);
      nextVertex = leftMost;
    }
  }
  hull.forEach(val=>{
    ele.textContent = `${val.x} , ${val.y}` ;
  })
}

// void displayHull(){
//  
// }
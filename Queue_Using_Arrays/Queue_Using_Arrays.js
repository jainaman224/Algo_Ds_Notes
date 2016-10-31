var front = -1;
rear = -1;
var size = 4;

var queue = new Array(size);

/**
 * Checks is the queue is empty.
 * @returns {Bool} True if the queue is empty.
 */
function isEmpty() {
  if(front == -1 || front > rear)
    return true;
  else
    return false;
}

/**
 * Adds an element to the queue.
 * @param {Object|String|Number} element - The element to be added to the queue.
 */
function enqueue(element) {
  if (rear == size - 1)
    console.log("Queue is full.");
  else {
    if(front == -1)
      front = 0;

    rear += 1;
    queue[rear] = element;
    console.log(element + " was entered successfully.");
  }
}

/**
 * Removes the element in position "front" from the queue.
 */
function dequeue() {
  if(isEmpty())
    console.log("Queue is currently empty.");
  else {
    var deletion = queue[front];
    front++;
    console.log(deletion + " has been removed.");
  }
}

/**
 * Prints out the elements in the queue.
 */
function display() {
  for(var i = front; i <= rear; i ++) {
    console.log(queue[i] + "\n");
  }
}

enqueue(23);
enqueue(45);
enqueue(65);
enqueue(89);
enqueue(90);
dequeue();
dequeue();
display();

/**
* OUTPUT:
* 23 was entered successfully.
* 45 was entered successfully.
* 65 was entered successfully.
* 89 was entered successfully.
* Queue is full.
* 23 has been removed.
* 45 has been removed.
* 65
* 89
*/

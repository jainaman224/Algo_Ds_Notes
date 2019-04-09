class queueElement {
    constructor(element, priority) {
        this.element = element;
        this.prioriry = priority;
    }
}

class PriorityQueue {
    constructor() {
        this.items = [];
    }

    //to add an element to the queue
    enqueue(element, priority) {
        var newQueueElement = new queueElement(element, priority);
        var isPresent = false;
        for (let i = 0; i < this.items.length; i++) {
            if (this.items[i].priority > newQueueElement.priority) {
                this.items.splice(i, 0, newQueueElement);
                isPresent = true;
                break;
            }
        }
        if (!isPresent) {
            this.items.push(newQueueElement);
        }
    }

    //to remove element form a queue
    dequeue() {
        if (this.isEmpty()) {
            return "Underflow";
        }
        return this.items.shift();
    }

    //the front function
    //returns the highest priority elemnt of queue
    front() {
        if (this.isEmpty()) {
            return "Empty Queue";
        }
        return this.items[0];
    }
    //the rear function
    // returns the lowest priorty element of the queue 
    rear() {
        if (this.isEmpty()) {
            return "Empty Queue";
        }
        return this.items[this.items.length - 1];
    }
    // isEmpty function 
    isEmpty() {
        return this.items.length == 0; //true if queue is empty
    }
    // printQueue function 

    printPriorityQueue() {
        var string = "";
        for (var i = 0; i < this.items.length; i++)
            string += this.items[i].element + " ";
        return string;
    }
}

var newPriorityQueue = new PriorityQueue();
newPriorityQueue.enqueue("1", 1);
newPriorityQueue.enqueue("2", 2);
newPriorityQueue.enqueue("3", 3);
newPriorityQueue.enqueue("4", 4);
newPriorityQueue.enqueue("5", 5);
console.log(newPriorityQueue.printPriorityQueue());
console.log(newPriorityQueue.front().element);
console.log(newPriorityQueue.rear().element);
console.log(newPriorityQueue.dequeue().element);
//After dequeue
console.log(newPriorityQueue.printPriorityQueue());


//OUTPUT =>

// 1 2 3 4 5 
// 1
// 5
// 1
// 2 3 4 5

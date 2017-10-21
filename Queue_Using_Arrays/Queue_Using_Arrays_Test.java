public class Queue_Using_Arrays_Test{
	public static void main(String args[]){
		Queue_Using_Arrays qi = new Queue_Using_Arrays ();
		System.out.println("Queue is empty: " + qi.IsEmpty());
		System.out.println("Queue is full: " + qi.IsFull());
		System.out.println("Queue is: ");
		qi.enqueue(100);
		qi.enqueue(200);
		qi.enqueue(300);
		qi.enqueue(400);
		qi.enqueue(500);
		qi.enqueue(600);
		qi.enqueue(700);
		qi.enqueue(800);
		qi.enqueue(900);
		qi.enqueue(1000);
		qi.print();
		System.out.println("Queue is full: " + qi.IsFull());
		qi.enqueue(1100);
		System.out.println("Queue is empty: " + qi.IsEmpty());
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.dequeue();
		qi.print();
	}
}

/*
OUTPUT:
Queue is empty: true
Queue is full: false
Queue is: 
100	
200	
300	
400	
500	
600	
700	
800	
900	
1000	
Queue is full: true
Can't enqueue 1100
Queue is empty: false
Dequeued Item: 100
Dequeued Item: 200
Dequeued Item: 300
Dequeued Item: 400
Dequeued Item: 500
Dequeued Item: 600
Dequeued Item: 700
Dequeued Item: 800
Dequeued Item: 900
Dequeued Item: 1000
Can't dequeue.
Queue is Empty.
*/

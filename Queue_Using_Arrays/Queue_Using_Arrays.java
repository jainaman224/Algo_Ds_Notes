public class Queue_Using_Arrays {
	int[] arr = new int[5];
	int front = -1;
	int rear = -1;
	
	//Constructors
	Queue_Using_Arrays() {
		arr = new int[10];
		front = -1;
		rear=-1;
		}
	Queue_Using_Arrays(int size) {
		arr = new int[size];
		front = -1;
		rear=-1;
	}
	
	//Displaying the queue
	public void print() {
		if(front == -1)
			System.out.println("Queue is Empty.");
		else{
			for(int i=front; i<=rear;i++){
				System.out.println(arr[i]+"\t");
			}
		}
	}
	
	//Checking whether the queue is full
	public boolean IsFull(){
		if (rear==arr.length-1){
			return true;
		}
		else return false;
	}
	
	//Checking whether the queue is empty
	public boolean IsEmpty(){
		if (rear==-1 && front == -1){
			return true;
		}
		else return false;
	}
	
	//Enqueue operation
	public void enqueue(int item) {
		if(IsEmpty()){
			front++;
			rear++;
			arr[rear]=item;
		}
		else if(!IsFull()){
			rear++;
			arr[rear]=item;
		}
		else{
			System.out.println("Can't enqueue " + item);
		}
	}
	
	//Returns size of queue
	public int getSize() {
		return  arr.length;
	}
	
	//Dequeue operation
	public void dequeue() {
		if(front!=rear && !IsEmpty()){
			int temp = arr[front];
			front++;
			System.out.println("Dequeued Item: " + temp);
		}
		else if( front == rear && !IsEmpty()){
			int temp = arr[front];
			front = -1;
			rear = -1;
			System.out.println("Dequeued Item: " + temp);
		}
		else
			System.out.println("Can't dequeue.");
	}
}

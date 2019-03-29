/*
    author: kunal-kushwaha
    date: 29-03-2019
*/

class Queue_Circluar {

    protected int[] data;
    private static int DEFAULT_SIZE = 10;

    protected int end = 0;
    protected int front = 0;
    private int size = 0;

    public Queue_Circluar(){

        this(DEFAULT_SIZE); // will run if no value is passed
    }

    public Queue_Circluar(int size){

        data = new int[size];
    }
    public boolean isFull(){

        return size == data.length;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public boolean insert(int item){
        if(isFull()){
            return false;
        }
        data[end++] = item;

        end = end % data.length;    // restart from index 0
        size++;

        return true;
    }

    public int remove() throws Exception{
        if(isEmpty()){
            throw new Exception("Removing from empty Queue");
        }

        int temp =  data[front++];

        front = front % data.length;
        size--;

        return temp;
    }

    public int front() throws Exception{
        if(isEmpty()){
            throw new Exception("Checking front from empty queue");
        }
        return data[0];
    }

    public void display(){

        for (int i = front; i < end ; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println("END");
    }

}

class Queue extends Queue_Circluar{

    public Queue(){
        super();
    }

    public Queue(int size){
        super(size);
    }

    @Override
    public boolean insert(int item) {

        if(isFull()){
            System.out.println("RESIZING");
            int[] temp = new int[data.length * 2];

            for (int i = 0; i < data.length; i++) {
                temp[i] = data[(front + i) % data.length];
            }

            front = 0;
            end = data.length;
            data = temp;
        }
        return super.insert(item);
    }
}

public class Dynamic_Queue {

    public static void main(String[] args) throws Exception{

        Queue queue = new Queue();

        for (int i = 0; i < 50; i++) {
            queue.insert(i);
        }

        System.out.println("Queue contains : ");
        queue.display();

    }
}

/*
    OUTPUT :
    RESIZING
    RESIZING
    RESIZING
    Queue contains :
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 END
*/

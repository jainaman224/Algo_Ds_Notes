public class Queue_Circluar {

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

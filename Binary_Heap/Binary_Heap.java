import java.util.Scanner;

public class Binary_Heap {
    static int[] heap;
    static int size;
    static int maxSize;
    
    // returns the index of parent of position num
    static int parent(int num) {
        return num / 2;
    }
    
    // returns the index of left child of position num
    static int leftChild(int num) {
        return 2 * num + 1;
    }
    
    // returns the index of right child of position num
    static int rightChild(int num) {
        return 2 * num + 2;
    }
    
    // swap two values in the heap
    static void swap(int a, int b) {
        int temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }
    
    // check and correct if heap conditions are violated
    static void heapify(int pos) {
        while (true) {
            int ptr = pos;
            int left = leftChild(pos);
            int right = rightChild(pos);
            
            if (left < size + 1) {
                if (heap[ptr] > heap[left]) ptr = left;
            }
            if (right < size + 1) {
                if (heap[ptr] > heap[right]) ptr = right;
            }
            if (pos == ptr) return;
            swap(pos, ptr);
            pos = ptr;
        }
    }
    
    // return minimum element of the heap
    static int extractMin() {
        if (size < 0){
            return -1;
        }
        int min = heap[0];
        heap[0] = heap[size];
        heap[size] = 0;
        size--;
        heapify(0);
        return min;    
    }
    
    // insert to the heap
    static void insert(int num) {
        size++;
        if (size >= maxSize) {
            return;
        }
        heap[size] = num;
        int pointer = size;
        while (heap[pointer] < heap[parent(pointer)]) {
            swap(pointer, parent(pointer));
            pointer = parent(pointer);
        }
    }
    
    // prints the content of the heap
    static void printHeap() {
        if (size < 0) return;
        for (int i = 0; i <= size; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner input =  new Scanner(System.in);
        int n = input.nextInt();
        size = -1;
        heap = new int[n];
        maxSize = n;
        
        while (n > 0) {
            n--;
            int op = input.nextInt();
            if (op == 1) {
                int num = input.nextInt();
                insert(num);
            }
            if (op == 2) {
                extractMin();
            }
            if (op == 3) {
                printHeap();
            }    
        }
    }
}

/*
 * Input:
 * 10
 * 1 5
 * 1 4
 * 3
 * 1 9
 * 2
 * 3
 * 1 6
 * 1 1
 * 3
 * 2
 * 3
 * 
 * Explanation:
 * There are n queries. First digit of each of the n lines denotes the type of query.
 * 1 = insert
 * 2 = extract minimum
 * 3 = print heap
 * Query 1 is followed by the number to be inserted.
 * 
 * Output:
 * 4 5
 * 5 9
 * 1 5 9 6
 * 5 9 6
*/

import java.util.NoSuchElementException;

public class HeapPriorityQueue {
    private String[] heap;
    private int size; // Number of elements in the heap

    /**
     * Initializes an empty priority queue with the given initial capacity
     */
    public HeapPriorityQueue(int initialCapacity) {
        heap =  new String[initialCapacity + 1];
        size = 0;
    }

    /**
     * Initializes an empty priority queue
     */
    public HeapPriorityQueue() {
        this(1);
    }

    /**
     * Initializes a priority queue from the array of values
     *
     * @param vals the array of values
     */
    public HeapPriorityQueue(String [] vals) {
        size = vals.length;
        heap = new String[size + 1];
        // we do not use the 0 index with the heap
        System.arraycopy(vals, 0, heap, 1, size);

        for(int x = size/2; x > 0; x--) {
            percolateDown(x);
        }
    }

    /**
     * Returns true if the priority queue is empty
     *
     * @return true if this priority queue is empty; false otherwise
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Returns the number of elements in the priority queue
     *
     * @return the number of elements in the priority queue
     */
    public int size() {
        return size;
    }

    /**
     * Returns the smallest element in the priority queue
     *
     * @return the smallest element in the priority queue
     * @throws NoSuchElementException if the priority queue is empty
     */
    public String min() {
        if(isEmpty()) {
            throw new NoSuchElementException("Priority Queue is empty!");
        }
        return heap[1];
    }

    /**
     * Add a new element to the priority queue
     *
     * @param element the element to insert
     */
    public void insert(String element) {
        if(size == heap.length -1) {
            doubleSize();
        }

        int pos = ++size;
        // percolate up
        for(; pos > 1 && element.compareTo(heap[pos/2]) < 0; pos = pos/2) {
            heap[pos] = heap[pos/2];
        }
        heap[pos] = element;
    }

    /**
     * Removes and returns the smallest element in the priority queue
     *
     * @return the smallest element in the priority queue
     * @throws NoSuchElementException if the priority queue is empty
     */
    public String removeMin() throws NoSuchElementException {
        if(size == 0) {
            throw new NoSuchElementException("Priority Queue is empty!");
        }

        String min = heap[1];
        heap[1] = heap[size--];
        percolateDown(1);
        return min;
    }

    private void doubleSize() {
        String [] old = heap;
        heap = (String[]) new String[heap.length * 2];
        System.arraycopy(old, 1, heap, 1, size);
    }

    private void percolateDown(int k) {
        String tmp = heap[k];
        int left;
        // Traverse down the left side of the tree
        for(; 2*k <= size; k = left) {
            left = 2*k;
            int right = left + 1;
            if(left != size && heap[left].compareTo(heap[right]) > 0) {
                left = right;
            }
            if(tmp.compareTo(heap[left]) > 0) {
                heap[k] = heap[left];
            } else {
                break;
            }
        }
        heap[k] = tmp;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for(int x = 1; x <= size; ++x) {
            out.append(heap[x]).append(" ");
        }
        // remove trailing space
        out.setLength(out.length() - 1);
        return out.toString();
    }

    /*
     * Output is provided with the inline comments
     */
    public static void main(String [] args) {
        String [] keys = new String[]{"p", "r", "i", "o"};
        HeapPriorityQueue h = new HeapPriorityQueue(keys);
        System.out.println(h.toString()); // i o p r
        h.insert("q");
        h.insert("z");
        h.insert("b");
        System.out.println(h.toString()); // b o i r q z p
        h.removeMin();
        System.out.println(h.toString()); // i o p r q z
        h.removeMin();
        System.out.println(h.toString()); // o q p r z
        System.out.println(h.min()); // o
        h.removeMin();
        System.out.println(h.min()); p
        h.removeMin();
        h.removeMin();
        assert(h.size() == 2);
        h.removeMin();
        h.removeMin();
        System.out.println(h.isEmpty()); // true
    }
}

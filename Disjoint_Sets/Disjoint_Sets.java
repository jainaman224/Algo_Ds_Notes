import java.util.Scanner;

public class Disjoint_Sets {
    static int[] parent;
    static int[] size;
    
    // function that initially defines the parent of all element as itself.
    static void makeSet(int n) {
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        return;
    }
    
    // recursive function to find the parent of an element.
    static int find(int a) {
        if (parent[a] == a) return a;
        else return find(parent[a]);        
    }
    
    // function to merge two elements such that both of them belong to the same set
    static void union(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);
        
        if (parent_a != parent_b) {
            if (size[parent_a] < size[parent_b]) {
                
                // swap a and b
                int temp = a;
                a = b;
                b = temp;
            }
            parent[parent_b] = parent_a;
            size[a] += size[b];
        }
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of nodes and number of edges");
        int n = input.nextInt();
        int e = input.nextInt();
        parent = new int[n + 1];
        size = new int[n + 1];
        System.out.println("Enter e edges");

        // make set with n nodes (1,2,...,n)
        makeSet(n);     
        for (int i = 0; i < e; i++) {
            int a = input.nextInt();
            int b = input.nextInt();
            union(a, b);
        }
        for (int i = 1; i < n + 1; i++) {
            System.out.println(find(i));
        }
    }
}

/* Sample Input/Output
 
    Input:
    6 4
    1 3
    3 4
    2 5
    5 6
    
    Output:
    1
    2
    1
    1
    2
    2
    
    Explanation:
    First line of input is n and e respectively.
    e line contain edges
    
    ith line of output corresponds to the set that i belongs to. (0 <= i <= n)
*/

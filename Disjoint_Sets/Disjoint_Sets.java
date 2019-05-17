public class Disjoint_Sets {
    //declare global arrays to store the parent of each element and size of each set
    static int[] parent;
    static int[] size;
    
    //function that initially defines the parent of all element as itself.
    static void makeSet(int n) {
        for (int i=0;i<n+1;i++) {
            parent[i]=i;
            size[i]=1;
        }
        return;
    }
    
    //recursive function to find the parent of an element.
    static int find(int a) {
        if (parent[a]==a) return a;
        else return (find(parent[a]));      
    }
    
    
    //function to merge two elements such that both of them belong to the same set, i.e. they share a common parent
    static void union(int a, int b) {
        int parent_a=find(a);
        int parent_b=find(b);
        
        if (parent_a!=parent_b) {
            if (size[parent_a]<size[parent_b]){
                //swap a and b
                int temp=a;
                a=b;
                b=temp;
            }
            parent[parent_b]=parent_a;
            size[a]+=size[b];
    
        }
    }
    
    
    public static void main(String[] args) {
                
        int n=6;
        parent=new int[n+1];
        size=new int[n+1];
        makeSet(n); //make set with n nodes (1,2,...,n)
        
        // create graphs 1--3--4 and 2--5--6
        union(1,3);
        union(3,4);
        
        union(2,5);
        union(5,6); 
        
         //check if 1 and 4 belong to the same set (expected output: 1  1)
        System.out.println(find(1)+ "  " + find(4));
        
        //check if 2 and 6 belong to the same set (expected output: 2  2)
        System.out.println(find(2)+ "  " + find(6));
        
        //check if 1 and 2 belong to the same set (expected output: 1  2)
        System.out.println(find(1)+ "  " + find(2));
    }

}

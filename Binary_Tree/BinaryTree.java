public class BinaryTree { 
    static class Node {    
    int value; 
        Node left, right; 
          
        Node(int value){ 
            this.value = value; 
            left = null; 
            right = null; 
        } 
    } 
       
    public void insert(Node node, int value) {
        if (value < node.value) 
        { 
          if (node.left != null)
           { insert(node.left, value); }
            else
            { System.out.println(" Inserted " + value + " to the left of " + node.value);
             node.left = new Node(value);
             } 
        }
        else if (value > node.value) {
          if (node.right != null) {
            insert(node.right, value);
          } 
          else 
          {
            System.out.println("  Inserted " + value + " to the right of " + node.value);
            node.right = new Node(value);
          }
        }
      }
     public static void main(String args[]) 
    {
     
       BinaryTree bs = new BinaryTree();
                Node root = new Node(10);
                System.out.println("Building tree with root value " + root.value);
                bs.insert(root, 12);
                bs.insert(root, 5);
                bs.insert(root, 4);
                bs.insert(root, 20);
                bs.insert(root, 8);
                bs.insert(root, 7);
                bs.insert(root, 15);
                bs.insert(root, 13);
                
     }
}
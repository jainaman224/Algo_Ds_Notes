import java.util.Deque;
import java.util.LinkedList;

/*
This class represents a CartesianTree which is a binary tree derived from a
sequence of numbers; it can be uniquely defined from the properties that it is
heap-ordered (min or max) and that a symmetric (in-order) traversal of the tree
returns the original sequence.

Example: Input - [3,2,1,6,0,5]
         CartesianTree:       6
                            /   \
                           3     5
                            \    /
                             2  0
                               \
                                1
*/

class CartesianTree
{

  /*
  Node class represents a node in a graph
  Node attributes include:
  val - (int) represents the value of the node
  left - (Node) represents the left child of the node
  right - (Node) represents the right child of the node

  Constructor template: Node n = new Node(int)
  Example: Node n1 = new Node(12);
  */

  static class Node
  {
    int val;
    Node left;
    Node right;

    Node(int val)
    {
      this.val = val;
      this.left = null;
      this.right = null;
    }
  }

  // CartesianTree can be built in Linear time using all nearest smaller values
  // problem
  private Node cartesianTreeBuilder(int[] nums)
  {
    if(nums == null || nums.length == 0)
      return null;

    Deque<Node> stack = new LinkedList<Node>();

    for(int i=0;i<nums.length;i++)
    {
      // create new node for each element in the array
      Node current = new Node(nums[i]);

      // keep poping the stack till we find an element at top which is less than
      // the current array element
      while(!stack.isEmpty() && stack.peek().val < nums[i])
        current.left = stack.pop();

      // as the element which is greater than current array element is at the
      // top we assign it as the parent of current node
      if(!stack.isEmpty())
      {
        stack.peek().right = current;
      }

      stack.push(current);
    }

    // as the stack contains decreasing order of Nodes we return the last element
    // which forms the root of the CartesianTree
    return stack.removeLast();
  }

  // Property of CartesianTree states that it's in order traversal should returns
  // the original sequence
  private void inOrderTraversal(Node x)
  {
    if(x != null)
    {
      inOrderTraversal(x.left);
      System.out.print(x.val+" ");
      inOrderTraversal(x.right);
    }
  }


  public static void main(String args[])
  {
    int[] nums = {3,2,1,6,0,5};
    CartesianTree ct = new CartesianTree();

    Node result = ct.cartesianTreeBuilder(nums);

    System.out.println("Inorder Traversal of CartesianTree is: ");
    ct.inOrderTraversal(result);
  }

  /*

  OUTPUT:
  Inorder Traversal of CartesianTree is:
  3 2 1 6 0 5

  */
}

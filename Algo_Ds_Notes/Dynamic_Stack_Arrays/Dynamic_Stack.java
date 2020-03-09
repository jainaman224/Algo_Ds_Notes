 class stackDynamicArray {
   
     private int data[];
     private int top;
     public stackDynamicArray() 
     {
         data = new int[2];
         top = -1;
     }
     public int size() 
     {
         return top + 1;
     }
     public int top() 
     {
         if (top == -1) 
         {
             System.out.println("UnderFlow");
             return Integer.MIN_VALUE;
         }
         return data[top];
     }
     public boolean isEmpty() 
     {
         if (top == -1)
             return true;
         else
             return false;
     }
     public void push(int element) 
     {
         if (size() == data.length) 
         {
             doubleCapacity();
         }
         top++;
         data[top] = element;
     }
     public void doubleCapacity()
     {
         int temp[] = new int[2 * data.length];
         for (int i = 0; i < size(); i++) 
         {
             temp[i] = data[i];
         }
         data = temp;
     }
     public int pop() 
     {
         if (top == -1) 
         {
             System.out.println("UnderFlow");
             return Integer.MIN_VALUE;
         }
         int temp = data[top];
         top--;
         return temp;
     }
 }

 public class DynamicStack {
     public static void main(String[] args) {
     
         stackDynamicArray st = new stackDynamicArray();    
       	 for (int i = 0; i < 10; i++) 
         {
             st.push(i);
         }
         while (!st.isEmpty()) 
         {
             System.out.println(st.pop());
         }
     }
 }

/*OUTPUT:
 9
 8
 7
 6
 5
 4
 3
 2
 1
 0
*/
 

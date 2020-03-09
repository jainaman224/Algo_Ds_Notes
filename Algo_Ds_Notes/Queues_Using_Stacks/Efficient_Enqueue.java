import java.util.Stack;

public class EfficientEnqueue {
    Stack < Integer > primaryStack = new Stack < > ();
    Stack < Integer > secondaryStack = new Stack < > ();
    public void enqueue(int element)
    {
        primaryStack.push(element);
    }
    public int dequeue()
    {
        if (this.size() == 0)
        {
            System.out.print("UnderFlow  ");
            return Integer.MIN_VALUE;
        }
        if (secondaryStack.empty())
        {
            while (!primaryStack.empty())
            {
                secondaryStack.push(primaryStack.pop());
            }
        }
        return secondaryStack.pop();
    }
    public boolean isEmpty()
    {
        return primaryStack.empty() && secondaryStack.empty();
    }
    public int size()
    {
        return primaryStack.size() + secondaryStack.size();
    }
    public static void main(String args[]) {
        EfficientEnqueue q1 = new EfficientEnqueue();
        for (int i = 0; i < 10; i++)
        {
            q1.enqueue(i);
        }
        while (!q1.isEmpty())
        {
            System.out.println(q1.dequeue());
        }
    }
}
/*OUTPUT
 0
 1
 2
 3
 4
 5
 6
 7
 8
 9
 */

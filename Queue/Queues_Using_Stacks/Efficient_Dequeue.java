import java.util.Stack;

public class EfficientDequeue {
    Stack < Integer > primaryStack = new Stack < > ();
    Stack < Integer > secondaryStack = new Stack < > ();
    public void enqueue(int element)
    {
        while (!primaryStack.isEmpty())
        {
            secondaryStack.push(primaryStack.pop());
        }
        secondaryStack.push(element);
        while (!secondaryStack.isEmpty())
        {
            primaryStack.push(secondaryStack.pop());
        }
    }
    public int dequeue()
    {
        if(primaryStack.size()==0)
        {
            System.out.print("UnderFlow ");
            return Integer.MIN_VALUE;
        }
        return primaryStack.pop();
    }
    public boolean isEmpty()
    {
        return primaryStack.empty();
    }
    public int size()
    {
        return primaryStack.size();
    }

    public static void main(String args[]) {
        EfficientDequeue q1 = new EfficientDequeue();
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

/*
OUTPUT:
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

package Stacks;

import java.util.Collection;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by Last on 10/19/2016.
 */
public class Push_Efficient
{
    Queue<Integer> q1 = new LinkedList<Integer>(), q2 = new LinkedList<Integer>();

    public void push(int data){
        q1.add(data);
    }

    public Integer pop(){
        if (q1.isEmpty()){
            return Integer.MIN_VALUE;
        }
        else{
            if (q1.size() == 1){
                return q1.remove();
            }
            else{
                int size = q1.size();
                for (int i = 0; i < size-1; i++) {
                    q2.add(q1.remove());
                }
                int x = q1.remove();
                q1 = q2;
                return x;
            }
        }
    }

    public void printStack(){
        for (int x:
             q1) {
            System.out.println(""+x);
        }
    }

    //Driver method
    public static void main(String[] args) {
        Push_Efficient push_efficient = new Push_Efficient();

        push_efficient.push(10);
        push_efficient.push(20);
        push_efficient.push(30);
        push_efficient.push(40);
        push_efficient.push(50);

        push_efficient.pop();

        push_efficient.push(60);
        push_efficient.push(70);

        push_efficient.pop();

        push_efficient.push(80);

        push_efficient.printStack();
    }
}

//Output
//10
//20
//30
//40
//60
//80

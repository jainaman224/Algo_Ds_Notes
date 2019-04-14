package Stacks;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by Last on 10/19/2016.
 */
public class Pop_Efficient {
    Queue<Integer> q1 = new LinkedList<>(), q2 = new LinkedList<>();

    public Integer pop(){
        if(q1.isEmpty())
            return Integer.MIN_VALUE;
        return q1.remove();
    }

    public void push(int data){
        if(!q1.isEmpty()){
            int size = q1.size();
            for (int i = 0; i < size; i++) {
                q2.add(q1.remove());
            }
            q1.add(data);
            for (int i = 0; i < size; i++) {
                q1.add(q2.remove());
            }
        }
        else{
            q1.add(data);
        }
    }

    public void printStack(){
        for (int x: q1) {
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        Pop_Efficient pop_efficient = new Pop_Efficient();

        pop_efficient.push(10);
        pop_efficient.push(20);
        pop_efficient.push(30);
        pop_efficient.push(40);
        pop_efficient.push(50);

        pop_efficient.pop();

        pop_efficient.push(60);
        pop_efficient.push(70);

        pop_efficient.pop();

        pop_efficient.push(80);
        pop_efficient.push(90);

        pop_efficient.printStack();
    }
}

//Output
//        90
//        80
//        60
//        40
//        30
//        20
//        10

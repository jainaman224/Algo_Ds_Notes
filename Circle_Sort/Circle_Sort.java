import java.io.*;
import java.util.*;

public class Main {
    public static void swap(ArrayList<Integer> arr,int pos1,int pos2)
    {
        int temp = arr.get(pos1);
        arr.set(pos1, arr.get(pos2));
        arr.set(pos2, temp);
    }
    public static boolean circle_sort_rec(ArrayList<Integer> arr,int start,int end)
    {
        boolean swaped = false;
        if((end-start) < 2)
        {
            if (arr.get(start) > arr.get(end))
            {
                swap(arr,start,end);
                swaped = true;
            }
            return swaped;
        }
        int mid = (start+end)/2;
        for (int i=start;i<=mid;i++)
        {
            if (i == start+end-i)
            {
                if(arr.get(i) > arr.get(i+1)) {
                    swap(arr, i, i + 1);
                    swaped = true;
                }
            }
            else
            {
                if (arr.get(i) > arr.get(start+end-i))
                {
                    swap(arr,i,start+end-i);
                    swaped = true;
                }
            }
        }
        if (circle_sort_rec(arr,start,mid))
        {
            swaped = true;
        }
        if (circle_sort_rec(arr,mid+1,end))
        {
            swaped = true;
        }
        return swaped;
    }

    public static void circle_sort(ArrayList<Integer> arr, int size)
    {
        while (circle_sort_rec(arr,0,size-1))
        {
            ;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of array: ");
        int size = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<Integer>(size);
        System.out.print("Enter the elements of the array : ");
        for(int i=0;i<size;i++)
        {
            int temp_num = sc.nextInt();
            arr.add(temp_num);
        }
        circle_sort(arr,size);
        for (int i=0;i<size;i++)
            System.out.print(arr.get(i) + " ");

    }
}

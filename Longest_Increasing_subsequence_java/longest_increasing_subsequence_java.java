package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    static int lengthOfLIS(int[] a) {
        if (a.length == 0) {
            return 0;
        }

        int[] cache = new int[a.length];
        Arrays.fill(cache, 1);

        for (int i = 1; i < a.length; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    cache[i] = Math.max(cache[i], cache[j] + 1);
                }
            }
        }

        return Arrays.stream(cache).max().getAsInt();
    }


    public static void main(String[] args) {
//        int[] arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

        Scanner s = new Scanner(System.in);
        System.out.println("Enter the size of the list");
        int n= s.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the elements of the array");
        for (int i = 0; i <n ; i++) {
            arr[i]=s.nextInt();
        }
        System.out.println(lengthOfLIS(arr));
    }
}


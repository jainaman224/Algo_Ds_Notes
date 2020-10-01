/*
    author: kunal-kushwaha
    date: 25/03/2019
*/

import java.util.Scanner;

public class Egg_Drop {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.println("Enter Number of Eggs : ");
        int egg = input.nextInt();
        System.out.println("Enter Number of Floors : ");
        int floor = input.nextInt();

        int[][] mem = new int[egg + 1][floor + 1];

        System.out.println(eggDropIterativeDP(egg,floor, mem));

    }

    public static int eggDropRecursive(int egg, int floor){
        if(floor == 0){
            return 0;
        }
        if(egg == 1){
            return floor;
        }

        int min = Integer.MAX_VALUE;

        for (int i = 1; i <= floor ; i++) {
            int sol = Math.max(eggDropRecursive(egg - 1, i - 1), eggDropRecursive(egg, floor - i)) + 1;

            if(sol < min){
                min = sol;
            }
        }
        return min;
    }

    public static int eggDropRecursiveDP(int egg, int floor, int[][] mem){
        if(floor == 0){
            return 0;
        }
        if(egg == 1){
            return floor;
        }
        if(mem[egg][floor] != 0){
            return mem[egg][floor];
        }

        int min = Integer.MAX_VALUE;

        for (int i = 1; i <= floor ; i++) {
            int sol = Math.max(eggDropRecursiveDP(egg - 1, i - 1, mem), eggDropRecursiveDP(egg, floor - i, mem)) + 1;

            if(sol < min){
                min = sol;
            }
        }
        mem[egg][floor] = min;
        return min;
    }

    public static int eggDropIterativeDP(int eggs, int floors, int[][] mem){
        for (int e = 1; e <= eggs ; e++) {
            for (int f = 0; f <= floors ; f++) {

                if(f == 0){
                    mem[e][f] = 0;
                }else if(e == 1){
                    mem[e][f] = f;
                }else{
                    int min = Integer.MAX_VALUE;
                    for (int i = 1; i <= f ; i++) {
                        int sol = Math.max(mem[e-1][i-1], mem[e][f-i]) + 1;

                        if(sol < min){
                            min = sol;
                        }
                    }
                    mem[e][f] = min;
                }
            }
        }
        return mem[eggs][floors];
    }

}

/*
OUTPUT :

    Enter Number of Eggs :
    5
    Enter Number of Floors :
    100
    7

*/

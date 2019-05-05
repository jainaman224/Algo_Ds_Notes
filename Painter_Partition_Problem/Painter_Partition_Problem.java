/*
    Painter's Partition Problem

    You are given n boards to paint and k painters are available with
    the restriction that 1 painter can paint 1 unit of board in 1 unit
    time. Also, 1 painter can paint only consecutive pieces of boards.

    We need to find the minimum amount of time required for painting
    all the boards.
*/
import java.util.*; 
  
public class Painter { 

    /*
        This function returns the minimum no. of painters required to
        paint the board given that a painter can paint consecutive mid
        units of board at max.
    */
    public static int painters(int board[], int n, int mid) {
        int painter = 0;
        int time = 0;
        for(int i = 0; i < n; i++) {
            time += board[i];
            if(time > mid) {
                time = board[i];
                painter ++;
            }
        }
        return painter;
    }

    /*
        The minimum time required to paint the boards would be 
        the maximum length of all the boards available, while the
        maximum time would be when there is only one painter 
        available. In that case, he has to print all the boards,
        i.e. the sum total of lengths of all the boards.

        The idea is to apply binary search between these two 
        time periods, and for each iteration, find if the required
        no. of painters with max consecutive mid units painted is
        less than available number of painters.

        This way, we would get the least time required by the
        optimal number of painters to paint all the boards.
    */
    public static int partition(int board[], int k, int sum, int n, int m) {
        int low = m;
        int high = sum;
        while (low < high) {
            int mid = (low + high)/2;
            if(painters(board, n, mid) < k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }

    public static void main(String[] args){
        int n = 5; // The number of boards.
        int[] board = {2, 5, 6, 3, 4};  // Length of boards.
        int k = 4;   // The number of painters.
        int sum = 0;
        int m = 0;
        for(int i = 0; i < n; i++) {
            sum += board[i];
            m = Math.max(m, board[i]);
        }
        System.out.print(" Minimum time to paint all the boards is: " + partition(board, k, sum, n, m));
    }

    /*
        Input : no. of boards = 5
                board = [2,5,6,3,4]
                no. of painters = 4
        Output : Minimum time to paint all the boards is : 7
        Verification : 1st painter will paint first two boards (2+5 = 7)
                    2nd painter will paint the third board (6)
                    3rd painter will paint the last two boards (3+4 = 7)
    */

} 

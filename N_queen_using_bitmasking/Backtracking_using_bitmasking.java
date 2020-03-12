import java.util.*;

class Solution {
    public static List<List<String>> solveNQueens(int n) {
        List<List<String>> res=new ArrayList<List<String>>();
        String[] queens=new String[n];
        char[] initial=new char[n];
        Arrays.fill(initial,'.');
        Arrays.fill(queens,String.valueOf(Arrays.copyOf(initial,n)));
        int[] flag=new int[5*n-2];
        Arrays.fill(flag,1);
        solve(res,queens,flag,0,n);
        return res;
    }
    private static void solve(List<List<String>> res,String[] queens,int[] flag,int row,int n){
        if(row==n){
            res.add(new ArrayList<String>(Arrays.asList(queens)));
            return;
        }
        for(int col=0;col!=n;col++){
            
            /*Here we use bit patterns to keep track of queen placements for the columns, left diagonals and right diagonals.
            1 in the bit pattern denotes that there is a queen attacking that column or diagonal line and 
            0 means that no queens are attacking that position.*/
            
            if(flag[col]==1 && flag[n+col+row]==1 && flag[4*n-2+col-row]==1){
                flag[col]=0;
                flag[n+col+row]=0;
                flag[4*n-2+col-row]=0;
                char[] chars=queens[row].toCharArray();
                
                chars[col]='Q';
                queens[row]=String.valueOf(chars);
                
                solve(res,queens,flag,row+1,n);
                
                // backtrack the path
                chars=queens[row].toCharArray();
                chars[col]='.';
                queens[row]=String.valueOf(chars);
                
                flag[col]=1;
                flag[n+col+row]=1;
                flag[4*n-2+col-row]=1;
            }
        }
    }
    public static void main(String[] args)  
    { 
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        List<List<String>> ans;
        ans = solveNQueens(n); 
        for(int i=0;i!=ans.size();i++)
        {
            List<String> arr = ans.get(i);
            for(int j=0;j!=arr.size();j++)
            {
               System.out.println(arr.get(j));
            }
            System.out.print("\n");
        }
        input.close();
    }  
}

/*
Sample Input: 
4
Sample Output: 
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
*/

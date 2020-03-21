import java.io.BufferedReader;
import java.io.IOException;
import java.io.*;

class Pascal_Triangle { 
    public static void main (String[] args) throws IOException{ 
        // Taking The Input from User
        System.out.print("Enter the number of rows to be printed: ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Converting String Into Integer
        int rows = Integer.parseInt(br.readLine()); 
        // Calling the Pascal Class
        new Pascal(rows);
    }  
} 

class Pascal {
    Pascal(int n) 
    { 
        for(int row = 1; row <= n; row++) 
        { 
            // Initializing the Initial Value of Pascal Value as 1
            int pascal_value = 1;
            // For Pring Blank Space 
            for(int i = 1; i < n - row + 1; i++){
                System.out.print(" "); 
            }
            System.out.print(" ");
            // For calculating the Pascal Value
            for(int i = 1; i <= row; i++) 
            {  
                // Assigning the Printable string to string s and printing the s
                String s = " " + pascal_value + " ";
                System.out.print(s); 
                // Calculating the New Pascal Value
                pascal_value = pascal_value * (row - i) / i;  
            } 
            System.out.println(); 
        } 
    } 
}

//Input:
//Enter the number of rows to be printed: 5

//Output:
//      1
//     1  1
//    1  2  1
//   1  3  3  1
// 1  4  6  4  1

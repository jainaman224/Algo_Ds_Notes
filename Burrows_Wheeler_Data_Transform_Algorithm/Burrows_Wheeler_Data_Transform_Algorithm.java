import java.util.*;
public class BurrowsWheeler
{
	public static void main(String[] args) 
    {
        
        //string which is to be compressed
        String input="banana$";
        
        //finding length of string
        int length=input.length();
        
        // finding all possible suffix array of string
        String[] suffixArray =new String[length];
        suffixArray[0]=input;
        for(int i=1;i<length;i++)
        {
        	suffixArray[i]=suffixArray[i-1].charAt(length-1)+suffixArray[i-1].substring(0,length-1);
        }
        
        //sorting suffix array
        Arrays.sort(suffixArray);
        String result="";
        
        //adding last character of sorted strings in result
        for(int i=0;i<length;i++)
        {
        	result=result+suffixArray[i].charAt(length-1);
        }
        
        //output the result
        System.out.print("Burrows - Wheeler Transform of above String is :"+result);
    }
}

// Output :
// Burrows - Wheeler Transform of above String is :annb$aa

import java.io.*; 
import java.util.Scanner; 
  
public class Hexadecimal_To_Decimal  
{  
    static int hexadecimalToDecimal(char hexa[]) 
    {    
        int length = hexa.length; 
        int base = 1; 
        int decimal = 0; 
        for (int i = length - 1; i >= 0; i--) 
        {
            if (hexa[i] >= '0' && hexa[i] <= '9') 
            { 
                decimal += (hexa[i] - 48) * base; 
                base = base * 16; 
            } 
            else if (hexa[i] >= 'A' && hexa[i] <= 'F') 
            { 
                decimal += (hexa[i] - 55) * base; 
                base = base * 16; 
            }
            else if (hexa[i] >= 'a' && hexa[i] <= 'f') 
            { 
                decimal += (hexa[i] - 87) * base; 
                base = base * 16; 
            }  
        }    
        return decimal; 
    } 

    // driver program 
    public static void main (String[] args)  
    { 
        String hexadec;
        Scanner sc = new Scanner(System.in);
        hexadec = sc.nextLine();
        char hexa[] = new char[100] ; 
        hexa = hexadec.toCharArray() ;     
        System.out.println(hexadecimalToDecimal(hexa)); 
    } 
}

//simpson's 1/3 rule in C#
using System; 
  
public class simpsonRule 
{ 
  
    static float func(float x) 
    { 
        return (float)Math.Log(x); 
    } 
  
    static float simpsons_(float ll, float ul, 
                                        int n) 
    { 
        float h = (ul - ll) / n; 
  
        float[] x = new float[10]; 
        float[] fx= new float[10]; 
  
        for (int i = 0; i <= n; i++) { 
            x[i] = ll + i * h; 
            fx[i] = func(x[i]); 
        } 
  
        float res = 0; 
        for (int i = 0; i <= n; i++) { 
            if (i == 0 || i == n) 
                res += fx[i]; 
            else if (i % 2 != 0) 
                res += 4 * fx[i]; 
            else
                res += 2 * fx[i]; 
        } 
          
        res = res * (h / 3); 
        return res; 
    } 
  
    public static void Main() 
    {  
        float lower_limit = 7; 
        float upper_limit = (float)7.3;  
          
        int n = 9;  
          
        Console.WriteLine(simpsons_(lower_limit,  
                                upper_limit, n)); 
    } 
}  
  
//OUTPUT : 0.5680499

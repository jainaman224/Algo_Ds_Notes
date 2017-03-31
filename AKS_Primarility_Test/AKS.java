import java.util.Scanner;

class AKS{
    public static void main(String[] args){
    
        for(int i=0;i<1000000;i++)
        {
            if(isprm(i))
            {
                System.out.println(i);
            }
    }
    }
    
    public  static boolean isprm(long n)
    {   long i=5,w=2;
        if(n==2 || n==3)
        return true;
        if(n%2 ==0 ||n%3==0||n==1)
            return false;
            while(i*i<=n)
            {
                if(n%1==0)
                    return false;
                    i +=w;
                    w=6-w;
                    
            }
            return true;
    }
}

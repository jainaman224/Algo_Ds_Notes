package github;

import java.util.Scanner;
class Process
{
    static Scanner in = new Scanner(System.in);//for input
    float At = 0;//parameters of process
    float Bt = 0;
    float Ct = 0;
    float Tt = 0;
    float Wt = 0;
    float Timeleft ;//only used for srtf

    Process(float a, float b)// constructor
    {
        At = a;
        Bt = b;
    }
   
    public static float calTt(Process p[], int n)//tt = ct-at and avg tt
    {
        float avg = 0;//avg
        for(int i = 0;i< n;i++)
        {
            p[i].Tt = p[i].Ct-p[i].At;
            avg = avg+p[i].Tt;
        }
        avg = avg/n;
        return avg;
    }
   
    public static float calWt(Process p[], int n)//wt = tt-bt and avg wt
    {
        float avg = 0;//avg
        for(int i = 0;i< n;i++)
        {
            p[i].Wt = p[i].Tt-p[i].Bt;
            avg = avg+p[i].Wt;
        }
        avg = avg/n;//avg wt
        return avg;
    }
}

class SRTF
{   
    float Awt;
    float Att;
    float sumBT;
    static Scanner in = new Scanner(System.in);
    public SRTF()
    {
        sumBT = 0;
    }
    
    public void Accept(Process p[],int n)//accept func
    {
        for(int i = 0; i < n; i++)
        {
            System.out.println("Enter arrival time for process P" + i);//at
            float a = in.nextFloat();
            System.out.println("Enter burst time for process P" + i);//bt
            float b = in.nextFloat();
            p[i] = new Process(a, b);
            p[i].Timeleft = p[i].Bt;//used to find shortest process remaining
            sumBT = sumBT + p[i].Bt;//used for cal ct in calcct function
        }
    }
   
    public void CalcCT(Process p[], int n)
    {
        System.out.println();
        System.out.println();
        int min = 0;
        for(int i = 0; i < sumBT; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(p[j].At <= i&&p[min].Timeleft > p[j].Timeleft && p[j].Timeleft != 0)//finding process with least bt
                {
                    min = j;//  process index with min bt
                }
            }
            p[min].Timeleft--;
            if(p[min].Timeleft == 0)//setting ct when execution is done
            {
                p[min].Ct = i + 1;// +1 because it will complete in next cycle
                p[min].Timeleft = 32767;
            }
            System.out.print("P" + min + "| ");//gantt chart
        }    
        Att = Process.calTt(p, n);//att
        Awt = Process.calWt(p, n);//awt
    }
    
    public void Display(Process p[],int n)
    { 
        System.out.println();
        System.out.println("process  Arrival Time  Burst Time  Completion Time  Turnover Time  Waiting Time");//table
        for(int i = 0; i < n; i++)
        {
            System.out.println("P"+i+"\t "+p[i].At+"\t\t"+p[i].Bt+"\t\t"+p[i].Ct+"\t\t"+p[i].Tt+"\t\t"+p[i].Wt);   
        }
        System.out.println();
        System.out.println("Average waiting time  is " + Awt);//other data to be displayed
        System.out.println("Average turnover time  is " + Att);
        System.out.println();
    }
}


public class MAIN {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("SRTF algorithm");
        int n;//no of processes
        System.out.println("Enter no of process");//ip of process
        n = in.nextInt();
        Process P[] = new Process[n];
        SRTF S  = new SRTF();//object of srtf
        S.Accept(P, n);
        S.CalcCT(P, n);//all calculations and gantt chart
        System.out.println();
        S.Display(P, n);//table display
    }   
}

/*sample output
 * SRTF algorithm
Enter no of process
4
Enter arrival time for process P0
0
Enter burst time for process P0
7
Enter arrival time for process P1
2
Enter burst time for process P1
4
Enter arrival time for process P2
4
Enter burst time for process P2
2
Enter arrival time for process P3
7
Enter burst time for process P3
1


P0| P0| P1| P1| P1| P1| P2| P2| P3| P0| P0| P0| P0| P0| 

process  Arrival Time  Burst Time  Completion Time  Turnover Time  Waiting Time
P0          0.0         7.0             14.0            14.0        7.0
P1          2.0         4.0             6.0             4.0         0.0
P2          4.0         2.0             8.0             4.0         2.0
P3          7.0         1.0             9.0             2.0         1.0

Average waiting time  is 2.5
Average turnover time  is 6.0

*/

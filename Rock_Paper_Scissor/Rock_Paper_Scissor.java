import java.util.Scanner;

public class Main
{
    public static int large = 500;
    public static double dp[][][] = new double[large][large][large];

    public static double probrock (int r, int p, int s) {
    if (s == 0 || r == 0)
        return 0.0;

    if (p == 0)
        return 1.0;

    if (dp[r][p][s] != -1.0)
        return dp[r][p][s];

    //total no. of fight = rC1.pC1 + pC1.sC1 + sC1.rC1
    double total = r * p + p * s + s * r;
    double res = 0.0;

    res += probrock (r - 1, p, s) * (((double) (r * p)) / total);	//prob. of fight btw r&p = r*p/total
    res += probrock (r, p - 1, s) * (((double) (s * p)) / total);	//prob. of fight btw s&p = s*p/total
    res += probrock (r, p, s - 1) * (((double) (r * s)) / total);	//prob. of fight btw r&s= r*s/total 

    return dp[r][p][s] = res;
}

public static double probpaper (int r, int p, int s) {
    if (p == 0 || r == 0)
        return 0.0;

    if (s == 0)
        return 1.0;

    if (dp[r][p][s] != -1.0)
        return dp[r][p][s];

    //total no. of fight = rC1.pC1 + pC1.sC1 + sC1.rC1
    double total = r * p + p * s + s * r;
    double res = 0.0;

    res += probpaper (r - 1, p, s) * (((double) (r * p)) / total);
    res += probpaper (r, p - 1, s) * (((double) (s * p)) / total);
    res += probpaper (r, p, s - 1) * (((double) (r * s)) / total);

    return dp[r][p][s] = res;
}

public static double probscissor (int r, int p, int s) {
    if (p == 0 || s == 0)
        return 0.0;

    if (r == 0)
        return 1.0;

    if (dp[r][p][s] != -1.0)
        return dp[r][p][s];

    //total no. of fight = rC1.pC1 + pC1.sC1 + sC1.rC1
    double total = r * p + p * s + s * r;
    double res = 0.0;

    res += probscissor (r - 1, p, s) * (((double) (r * p)) / total);
    res += probscissor (r, p - 1, s) * (((double) (s * p)) / total);
    res += probscissor (r, p, s - 1) * (((double) (r * s)) / total);

    return dp[r][p][s] = res;
}

public static void main (String[]args) {
    int rock, scissor, paper;
    Scanner sc = new Scanner (System.in);
    System.out.println ("Enter total no. of rocks");
    rock = sc.nextInt ();
    System.out.println ("Enter total no. of Scissors");
    scissor = sc.nextInt ();
    System.out.println ("Enter total no. of Papers");
    paper = sc.nextInt ();

    initializeDp (rock, paper, scissor);
    double ansRock = probrock (rock, paper, scissor);

    initializeDp (rock, paper, scissor);
    double ansPaper = probpaper (rock, paper, scissor);

    initializeDp (rock, paper, scissor);
    double ansScissor = probscissor (rock, paper, scissor);

    System.out.println ("Probability of rock to survive is " + ansRock);
    System.out.println ("Probability of scissor to survive is " + ansScissor);
    System.out.println ("Probability of paper to survive is " + ansPaper);
}

public static void initializeDp (int rock, int paper, int scissor) {
     for (int i = 1; i <= rock; i++) {
     for (int j = 1; j <= paper; j++) {
         for (int k = 0; k <= scissor; k++) {
             dp[i][j][k] = -1.0;
                }
            }
        }
    }
}

/*
Sample Input :
Enter total no. of rocks                                                                                                 
3                                                                                                                        
Enter total no. of Scissors                                                                                              
4                                                                                                                        
Enter total no. of Papers                                                                                                
5  

Sample Output :
Probability of rock to survive is 0.3052597434731967                                                                     
Probability of scissor to survive is 0.5104584331671178                                                                  
Probability of paper to survive is 0.18428182335968546   */

#include<iostream>
using namespace std;

int ary[10][10], completed[10], n, cost = 0;

void takeInput()
{
    int i, j;
 
    cout << "Enter the number of villages: ";
    cin >> n;
 	
    //Enter distance between cities
    cout << "\n Enter the Cost Matrix \n";
 
    for (i = 0; i < n; i++)
    {
        cout << "\n Enter Elements of Row " << i+1 << "\n";
 
        for (j = 0; j < n; j++)
            cin >> ary[i][j];
 
        completed[i] = 0;
    }
 	
    //Display matrix of distance between cities
    cout << "\n\n The cost list is:";
 
    for (i = 0; i < n; i++)
    {
        cout << "\n";
 
        for (j = 0; j < n; j++)
            cout << "\t" << ary[i][j];
    }
}

//Function for TSP algo
int least(int c)
{
    int i, nc = 999;
    int min = 999, kmin;
  
    for (i = 0; i < n; i++)
    {
        if ((ary[c][i] != 0) && (completed[i] == 0))
            if (ary[c][i] + ary[i][c] < min)
            {
                min = ary[i][0] + ary[c][i];
                kmin = ary[c][i];
                nc = i;
            }
    }
 
    if (min != 999)
	    cost += kmin;
 
    return nc;
}
 
//Function to determine minimum cost
void mincost(int city)
{
    int i, ncity;
 
    completed[city] = 1;
 
    cout << city + 1 << "--->";
    ncity = least(city);
 
    if (ncity == 999)
    {
        ncity = 0;
        cout << ncity + 1;
        cost += ary[city][ncity];
 
        return;
    }
 
    mincost(ncity);
}
 
//Display results
int main()
{
    takeInput();
 
    cout << "\n\n The Path is: \n";
    mincost(0); //passing 0 because starting vertex
 
    cout << "\n\n Minimum cost is " << cost;
 
    return 0;
}

/* Output:

Enter the number of villages: 4                                                                                         
                                                                                                                        
Enter the Cost Matrix                                                                                                   
                                                                                                                        
Enter Elements of Row: 1                                                                                                
0 10 15 20 

Enter Elements of Row 2                                                                                                 
30 40 15 0                                                                                                              
                                                                                                                        
Enter Elements of Row 3                                                                                                 
0 0 35 25  

Enter Elements of Row 4                                                                                                 
20 10 0 30                                                                                                              
                                                                                                                        
                                                                                                                        
The cost list is:                                                                                                       
        10      15      0       20                                                                                      
        30      40      15      0 
        0       0       35      25                                                                                      
        20      10      0       30                                                                                      
                                                                                                                        
The Path is:                                                                                                            
1--->4--->2--->3--->1 

Minimum cost is 45                                                                                                  
*/

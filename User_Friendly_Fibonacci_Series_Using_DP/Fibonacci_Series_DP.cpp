
/*-------------Dynamic Programming is nothing but using precalculated results-------------------*/
#include <iostream>

using namespace std;

long int storage_memory[100] = {0};    /* This is to store calculated result, we can retreive it from this array.*/

long fibonacci(long int n)          // Function to calculate fibonacci number
{
  if(n == 0 || n == 1)
    return n;
  if(n == 2)
    return 1;
    
  if(storage_memory[n] != 0)          // If that number is already calculated,
    // It will be returned without calculating again.
    return storage_memory[n];                        // This is we called dynamic programming.
  else
  {
    storage_memory[n]=fibonacci(n-1)+fibonacci(n-2);           // If not calculated,
    return storage_memory[n];                                  // Then it is calculated and stored.
  }
}

int main()
{
  int t;
  cout << "How  many numbers of fibonacci series : ";
  cin >> t;
  for(int i = 0; i < t; i++)
    cout << fibonacci(i) << " ";
  return 0;
}

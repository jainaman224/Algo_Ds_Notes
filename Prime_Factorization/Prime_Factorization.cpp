/*
    Prime Factorization of a number

    The task is to prime factorize a number using efficient techniques.
    i.e. denote a number as a product of different prime factors.

*/
#include <bits/stdc++.h>
using namespace std;
#define lint long long int

/*
        Since, 2 is the only even prime number, we compute it's frequence in the
        prime factorization of num separately, and then run the loop from 3, and 
        increment it by 2, so that we only check the odd numbers.
        In the loop, we keep decrementing the value of num by a factor of the number,
        which divides it.
        After the loop, if the value of num still tends to be greater than 2, it means,
        it is a prime factor in itself. Thus, we add to it's prime factors.
*/

void prime_factorize(lint num){
    vector<lint> prime_factors; // To maintain the prime factors of the given number.
    while(!(num%2)){
        prime_factors.push_back(2);
        num/=2;
    }
    for(lint i=3;i*i<=num;i+=2){
        while(!(num%i)){
            prime_factors.push_back(i);
            num/=i;
        }
    }
    if(num>2){
        prime_factors.push_back(num);
    }
    // Printing the prime factors.
    for(lint i=0;i<prime_factors.size();i++){
        cout<<prime_factors[i];
        if(i != prime_factors.size()-1){
            cout<<" * ";
        }
    }
}

int main()
{
    lint num = 100;
    cout<<num<<" = ";
    prime_factorize(num);
}
/*
Input : num = 100.
Output: 100 = 2 * 2 * 5 * 5
*/

#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#include <bits/stdc++.h>

using namespace std;

/*
    1. make every element of array 1.
    2. now make every element of multiple of that number make 0
    beacuase multiple of prime will be a composite number.
    3. time complexity O(loglogn)

*/
vi primes;
bool arr[10000001];

void seive() {
    ll max = 10000000;

    arr[0] = arr[1] = true;
    for (int i = 2; i * i <= max; ++i)
    {
        if(!arr[i]) {
            for (int j = i*i; j <= max; j += i)
            {
                arr[j] = true;
            }
        }
    }

    for(int i=2; i<=max; i++) {
        if(!arr[i]) {
            primes.pb(i);
        }
    }
}

void segSieve(ll a, ll b) {

    seive();
    bool arr[b-a+1];
    memset(arr, true, sizeof(arr));

    // arr[0] = arr[1] = false;
    for(ll i=2; i*i <= b; i++) {
        for(ll j=a; j<=b; j++) {
            if(arr[i]) {
                if(i==j) continue;
                if(j%i==0) {
                    arr[j-a] = false;
                }
            }
        }
    }

    for(ll i=a; i<=b; i++) {
        if(arr[i-a])
        cout << i << "\n";
    }
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    seive();
    int m, n;

    cin >> m >> n;

    // cout << primes[m] << " " << primes[n];
    for (int i = m; i <= n; ++i)
    {
        cout << primes[i];
    }
    return 0;
}


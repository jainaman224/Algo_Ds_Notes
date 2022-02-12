#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;
bool arr[100000001];
vi primes;

void sieve() {

	int max = 100000000;
	arr[0] = arr[1] = true;
	for (int i = 2; i * i <= max; ++i)
	{
		if (!arr[i]) {
			for (int j = i * i; j <= max; j += i)
			{
				arr[j] = true;
			}
		}
	}

	for (int i = 2; i <= max; i++) {
		if (!arr[i]) {
			primes.pb(i);
		}
	}
}


void segmentedSieve(ll l, ll r) {
	bool isPrime[r - l + 1];

	for (int i = 0; i <= r - l; ++i)
	{
		isPrime[i] = true;
	}

	for (int i = 0; primes[i] * 1LL * primes[i] <= r; i++) {
		ll currPrime = primes[i];
		ll base = (l / currPrime) * currPrime;
		if (base < l) {
			base = base + currPrime;
		}

		for (ll j = base; j <= r; j += currPrime) {
			isPrime[j - l] = false;
		}
		if (base == currPrime) {
			isPrime[base - l] = true;
		}
	}
	for (int i = 0; i <= r - l; ++i) {
		if (isPrime[i] == true) {
			cout << i + l << "\n";
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	sieve();
	int t;
	cin >> t;
	while (t--) {
		ll m, n;
		cin >> m >> n;
		if (m == 1) {
			m += 1;
		}
		segmentedSieve(m, n);
		cout << "\n";
	}
	return 0;
}
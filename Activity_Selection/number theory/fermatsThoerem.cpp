#define vi vector<int>
#define pb push_back
#define ll long long
#define mod 1000000007
#include <bits/stdc++.h>
using namespace std;
/*
	Fermat's theorem
	a ^ m-2 = a ^ -1 mod m;
	conditions for theorem
	1) m should be prime
	2) (a, m) should be co-prime
*/
int power(int a, int n, int m) {

	int res = 1;
	while (n) {
		if (n % 2) {
			res = (res * a) % m;
			n--;
		} else {
			a = (a * a) % m;
			n /= 2;
		}
	}
	return res;
}


int main() {

//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int a, m;
		cin >> a >> m;
		cout << "a^-1 = " << power(a, m - 2, m) << endl;
	}
	return 0;
}

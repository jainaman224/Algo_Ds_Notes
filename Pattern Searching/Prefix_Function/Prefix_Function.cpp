#include <iostream>
#include <vector>

using namespace std;

void search(string s, string t) {
	string p = t + "$" + s;
	int n = (int)p.size();
	vector <int> pi(n + 1, 0);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			++j;
		pi[i] = j;
	}
	for (int i = (int)t.size(); i < n; ++i)
		if (pi[i] == (int)t.size())
			cout << "Pattern found at " << i - 2 * (int)t.size() + 1 << endl;
}

int main() {
	string text = "namanchamanbomanamansanam";
	string pattern = "aman";
	search(text, pattern);
	return 0;
}

/* Output

Pattern found at 2
Pattern found at 8
Pattern found at 17

*/

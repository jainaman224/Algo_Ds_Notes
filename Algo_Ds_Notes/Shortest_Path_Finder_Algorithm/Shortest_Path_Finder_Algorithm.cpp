/**
	Shortest path finder algorithm implementation
	Finds shortest distance to all vertices from given one vertex
	Fast in practice
	Works with negative cycles
*/

#include <bits/stdc++.h>

using namespace std;


int main() {
	int n, m;
	n = 5;
	m = 7;

	vector <pair <int, int> > g[n + 1];
	int a[] = {1, 1, 2, 3, 2, 1, 2};
	int b[] = {2, 3, 3, 4, 4, 5, 5};
	int c[] = {1, 4, 2, 8, 6, 7, 5};


	for (int i = 0; i < m; ++i) {
		int v = a[i], u = b[i], w = c[i];
		g[v].push_back(make_pair(u, w));
		g[u].push_back(make_pair(v, w));
	}

	queue <int> q;
	q.push(1);

	int d[n + 1];
	bool inQueue[n + 1];

	for (int i = 1; i <= n; ++i) {
		d[i] = INT_MAX;
		inQueue[i] = false;
	}

	d[1] = 0;
	inQueue[1] = true;

	while (!q.empty()) {
		int v = q.front();
		// cerr << v << " ";
		q.pop();
		inQueue[v] = false;
		for (int i = 0; i < (int)g[v].size(); ++i) {
			int to = g[v][i].first, w = g[v][i].second;
			if (d[to] > d[v] + w) {
				d[to] = d[v] + w;
				if (!inQueue[to]) {
					q.push(to);
					inQueue[to] = true;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << d[i] << " ";

	return 0;
}

/**
	Distances array: 0 1 3 7 6
*/

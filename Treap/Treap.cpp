/**
	Implementation of treap data structure
	Insert function inserts item
	Find returns true if searching item is in treap, else false

	Time: O(log Size)
	Memory: O(Size)
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
	int x, y;
	node *l, *r;
	node() {}
	node(int x) : x(x), y(rand()), l(NULL), r(NULL) {}
};

typedef node* pnode;

pnode merge(pnode a, pnode b) {
	if (!a) return b;
	if (!b) return a;
	if (a -> y > b -> y) {
		a -> r = merge(a -> r, b);
		return a;
	}
	b -> l = merge(a, b -> l);
	return b;
}

void split(pnode t, int x, pnode &a, pnode &b) {
	if (!t)
		return void(a = b = NULL);
	if (t -> x >= x) {
		split(t -> l, x, a, t -> l);
		b = t;
	} else {
		split(t -> r, x - t -> x, t -> r, b);
		a = t;
	}
}

bool find(pnode &t, int x) {
	if (!t) return false;
	if (t -> x == x) return true;
	if (t -> x < x)
		return find(t -> r, x);
	return find(t -> l, x);
}

void insert(pnode &t, int x) {
	if (find(t, x)) return;
	pnode a, b;
	split(t, x, a, b);
	t = merge(merge(a, new node(x)), b);
}

int main() {
	srand(time(0));
	pnode t = NULL;
	vector <int> toInsert = {1, 2, 3, 6, 15};
	vector <int> toFind = {1, 2, 15, 4, 7, 6};
	for (int i = 0; i < toInsert.size(); ++i)
		insert(t, toInsert[i]);
	cout << boolalpha;
	for (int i = 0; i < toFind.size(); ++i)
		cout << "Searching " << toFind[i] << " -> " << find(t, toFind[i]) << endl;
}

/* Output
	Searching 1 -> true
	Searching 2 -> true
	Searching 15 -> true
	Searching 4 -> false
	Searching 7 -> false
	Searching 6 -> true
*/

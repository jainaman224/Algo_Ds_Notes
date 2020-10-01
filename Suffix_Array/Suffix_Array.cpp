#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>

using namespace std;

static const bool LOG_ENABLED = true;


// naive method to compute sa
vector<int> naive(const string &raw)
{
    vector< string > v;
    for (int i = 0; i < raw.size(); ++i)
        v.push_back(raw.substr(i));
    sort(v.begin(), v.end());

    vector<int> result(raw.size());
    for (size_t i = 0; i<v.size(); ++i)
        result[i] = raw.size() - v[i].size();
    return result;
}


vector<int> build_sa(const string& raw)
{
    vector<int> bukkit(max(size_t(CHAR_MAX), raw.size()));
    vector<int> sa(raw.size());
    vector<int> x(raw.size() * 2 , INT_MAX); // trick to avoid x[i + step] outbounds. Here INT_MAX should be larger than N

    // The next 6 lines are stable bukkit sort(keyword=raw[i], result: sa and x)
    for (size_t i = 0; i < raw.size(); ++i)
        ++bukkit[x[i] = raw[i]];
    for (size_t i = 1; i < bukkit.size(); ++i)
        bukkit[i] += bukkit[i-1];
    for (int i = raw.size() - 1; i >= 0; --i)
        sa[--bukkit[raw[i]]] = i;
    for (int step = 1; step < raw.size(); step *= 2)
    {
        if (LOG_ENABLED)
        {
            cout << "========== Step=" << step << " ==========";
            cout << endl;
            cout << "Pre SA:" << endl;
            for (int i = 0; i < raw.size(); ++i)
                cout << sa[i] << " ";
            cout << endl;
        }
        vector<int> new_sa;
        // the 2nd keyword of position N - step, ... must be smallest
        for (size_t i = raw.size() - step; i < raw.size(); ++i)
            new_sa.push_back(i);
        // Then, for each elements that could be 2nd keyword, keep its original order with position sa[i] - step
        for (size_t i = 0; i< raw.size(); ++i)
            if (sa[i] >= step)
                new_sa.push_back(sa[i] - step);
        if (LOG_ENABLED)
        {
            cout << "SA sorted by 2nd keyword:" << endl;
            for (int i = 0; i < raw.size(); ++i)
                cout << new_sa[i] << " ";
            cout << endl;
        }
        fill(bukkit.begin(), bukkit.end(), 0);

        // The next 9 lines perform stable bukkit sort(keyword: x[new_sa[i]] [the first keyword], result: sa)
        for (size_t i = 0; i < new_sa.size(); ++i)
        {
            if (LOG_ENABLED)
                cout << "Adding to bukkit " << x[new_sa[i]] << endl;
            bukkit[x[new_sa[i]]]++;
        }

        for (size_t i = 1; i < bukkit.size(); ++i)
            bukkit[i] += bukkit[i-1];

        for (int i = new_sa.size() - 1; i >= 0; --i)
            sa[--bukkit[x[new_sa[i]]]] = new_sa[i];

        if (LOG_ENABLED)
        {
            cout << "Post SA:" << endl;
            for (int i = 0; i < new_sa.size(); ++i)
                cout << sa[i] << " ";
            cout << endl;
        }

        // To rebuild x from sa
        // Need decide the number based on whether two key pairs are identical,
        // Two identical key pairs (10, 10) should be assigned with the same number in next iteration
        vector<int> newx = x;
        int p = 0;
        newx[sa[0]] = 0;
        for (int i = 1; i<sa.size(); ++i)
            newx[sa[i]] = ((x[sa[i]] == x[sa[i-1]]) && (x[sa[i] + step] == x[sa[i-1]+step])) ? p : ++p;
        x = newx;
        if (LOG_ENABLED)
        {
            cout << "p= " << p << endl;
            for (size_t i = 0; i < raw.size(); ++i)
                cout << "x[" << i << "] = " << x[i] << endl;
            cout << endl;
        }
        // All different, exit
        if (p == raw.size() - 1) break;
    }
    return sa;

}


// For test
void test_one()
{
    string s;
    for (int i = 0; i < 100; ++i)
        s.push_back('A' + rand() % 10);

    vector<int> good = build_sa(s), bad = naive(s);
    bool ok = true;
    if (good.size() != bad.size())
        ok = false;
    else
        for (size_t i = 0; i < good.size(); ++i)
            if (good[i] != bad[i])
                ok = false;

    if (ok)
        cout << "OK!" << endl;
    else
    {
        cout << "Failed for " << s << endl;
        for (size_t i = 0; i < good.size(); ++i)
            cout << good[i] << '\t';
        cout << endl;
        for (size_t i = 0; i < bad.size(); ++i)
            cout << bad[i] << '\t';
        cout << endl;
    }
}

int main()
{
    // For Internal test
    //for (int i=0; i<10000; ++i)
        //test_one();
    string s;
    // testcase: abaab
    cin >> s;
    vector<int> sa = build_sa(s);
    for (size_t i = 0; i < sa.size(); ++i)
        cout << sa[i] << " ";

    return 0;
}

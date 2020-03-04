#include <bits/stdc++.h> 
#define pii pair<int, int> 
#define mp make_pair 
using namespace std; 

void WaterJug(int a, int b, int l){
 
    // Map is used to store the states, every state is hashed to binary value to indicate either that state is visited before or not 
    map<pii, int> m; 
    // flag tells us is the problem solvable
    bool flag = false; 
    vector<pii> path; 

    queue<pii> q; // queue to maintain states 
    q.push({ 0, 0 });  

    while (!q.empty()) { 

        pii curr = q.front(); // current state 

        q.pop(); // pop off used state 

        // if this state is already visited 
        if (m[{ curr.first, curr.second }] == 1) 
            continue; 


        if ((curr.first > a || curr.second > b || curr.first < 0 || curr.second < 0)) 
            continue; 

        // filling the vector for constructing the solution path 
        path.push_back({ curr.first, curr.second }); 

        // marking current state as visited 
        m[{ curr.first, curr.second }] = 1; 

        // if we reach solution state
        if (curr.first == l || curr.second == l) { 
            flag = true; 
            if (curr.first == l) { 
                if (curr.second != 0) 
                    // fill final state 
                    path.push_back({ curr.first, 0 }); 
            }else { 
                if (curr.first != 0) 
                    // fill final state 
                    path.push_back({ 0, curr.second }); 
            } 

            // print the solution
            int sz = path.size(); 
            for (int i = 0; i < sz; i++) 
                cout << "(" << path[i].first << ", " << path[i].second << ")\n"; 
                break; 
        } 

        // start developing intermediate states to reach solution state 
        q.push({ curr.first, b }); // fill Jug2 
        q.push({ a, curr.second }); // fill Jug1 

        for (int p = 0; p <= max(a, b); p++) { 

            // pour amount ap from Jug2 to Jug1 
            int c = curr.first + p; 
            int d = curr.second - p; 

            // check if this state is possible or not 
            if (c == a || (d == 0 && d >= 0)) 
                q.push({ c, d }); 

            // Pour amount p from Jug 1 to Jug2 
            c = curr.first - p; 
            d = curr.second + p; 

            // check if this state is possible 
            if ((c == 0 && c >= 0) || d == b) 
                q.push({ c, d }); 
        } 

        q.push({ a, 0 }); // Empty Jug2 
        q.push({ 0, b }); // Empty Jug1 
    } 

	
    if (!flag) 
        cout << "No solution"; 
} 

// Driver code 
int main() 
{ 
    int jug1 , jug2, litres;
    cin>>jug1>>jug2>>litres;
    cout << "Path:\n"; 
    WaterJug(jug1, jug2, litres); 
    return 0; 
} 

//Input : 5 7 3
//Output: Path:
//(0, 0)
//(0, 7)
//(5, 0)
//(5, 7)
//(5, 2)
//(0, 5)
//(5, 5)
//(3, 7)
//(3, 0)



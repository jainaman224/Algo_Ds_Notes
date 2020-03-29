/*
Quickhull Algorithm for Convex Hull

Given a set of points, a Convex hull is the smallest convex polygon containing
all the given points.

Input is an array of points specified by their x and y coordinates.
Output is a convex hull of this set of points in ascending order of x coordinates.

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ptspr pair<int,int>

set<ptspr> ipts;
set<ptspr> finalpts;


int findside(ptspr p1, ptspr p2, ptspr p)
{
    int val=(( p2.first - p1.first )*( p.second - p1.second ))-
            (( p2.second - p1.second )*( p.first - p1.first ));

    if( val > 0 )
    {
        return 1;
    }

    if( val == 0 )
    {
        return 0;
    }

    if( val < 0 )
    {
        return -1;
    }
}

int distance( ptspr p1, ptspr p2, ptspr p )
{
    return abs(( p.second - p1.second )*( p2.first - p1.first )-
                ( p2.second - p1.second )*( p.first - p1.first ));
}

void findhull(ptspr a[], int n, ptspr p1, ptspr p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    for(int i=0; i<n; i++)
    {
        int temp = distance( p1, p2, a[i] );
        if( findside( p1, p2, a[i] ) == side && temp > max_dist )
        {
            ind = i;
            max_dist = temp;
        }
    }

    if( ind == -1 )
    {
        finalpts.insert( p1 );
        finalpts.insert( p2 );
        return;
    }

    findhull(a, n, a[ind], p1, -findside( a[ind], p1, p2 ));
    findhull(a, n, a[ind], p2, -findside( a[ind], p2, p1 ));
}

void finalptsonhull(ptspr a[], int n)
{
    if(n < 3)
    {
        cout<<"Convex hull not possible\n";
        return;
    }

    int minx = 0,maxx = 0;

    for(int i=0; i<n; i++)
    {
        if( minx > a[i].first )
            minx = a[i].first;

        if( maxx < a[i].first )
            maxx=a[i].first;
    }

    findhull(a, n, a[minx], a[maxx], 1);

    findhull(a, n, a[minx], a[maxx], -1);

    cout<<"The points on the Hull are:\n";

    while(!finalpts.empty())
    {
        cout<<"("<<( *finalpts.begin() ).first<<","<<(*finalpts.begin()).second<<")"<<"\n";

        finalpts.erase(finalpts.begin());
    }
}

int main()
{
    int x, y, n;
    cout<<"Enter number of points \n";
    cin>>n;

    ptspr a[n];
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        a[i] = make_pair(x,y);
    }

    finalptsonhull(a, n);

    return 0;
}

/*
Input : points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                    {0, 0}, {1, 2}, {3, 1}, {3, 3}};
Output :  The points on the Hull are:
          (0, 0) (0, 3) (3, 1) (4, 4)
*/

/***********************************************************************
Segment tree or segtree is a basically a binary tree used for storing the intervals or segments.
Each node in the segment tree represents an interval.
Consider an array A of size N and a corresponding segtree T:
*    The root of T will represent the whole array A[0:N-1].
*    Each leaf in the segtree T will represent a single element A[i] such that 0 <= i < N.
*    The internal nodes in the segtree tree T represent union of elementary intervals A[i:j] where 0 <= i < j < N.


*************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int nextPowerOf2(int n)
{

    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}
class SegmentTree
{
    int *tree;
    int *arr;
    int *lazy;
    int n;
    //BUILD THE SEGMENT TREE
    void build(int node, int start, int end)
    {
        if(start == end)
        {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start)/2;
        build(2*node + 1, start, mid);
        build(2*node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    //UPDATE SEGMENT TREE
    void update(int node, int start, int end, int index, int newVal)
    {
        if(start == end)
        {
            //here, start = end = index
            arr[index] += newVal;
            tree[node] += newVal;
            return;
        }
        else
        {
            int mid = start + (end - start)/2;
            if(index <= mid)
            {
                update(2*node + 1, start, mid, index, newVal);
            }
            else
            {
                update(2*node + 2, mid + 1, end, index, newVal);
            }
            tree[node] = tree[2*node + 1] + tree[2*node + 2];
        }
    }
    int query(int node, int start, int end, int l, int r)
    {
        if(l <= start && end <= r) //this segment lies totaly in query segment
        {
            return tree[node];
        }
        else if(end < l || r < start)
        {
            return 0;
        }
        else
        {
            int mid = start + (end - start)/2;
            int q1,q2;
            q1 = query(2*node + 1, start, mid, l,r);
            q2 = query(2*node + 2, mid+1, end, l,r);
            return q1 + q2;

        }
    }
    void lazyupdate(int node, int start, int end, int l, int r, int delta)
    {
        //range out side
        if(start > r || end < l)
            return;
        //preexisting updates?
        if(lazy[node]!=0)
        {
            tree[node] += (end - start + 1)*lazy[node];
            if(start != end)
            {
                lazy[2*node + 1] += lazy[node];
                lazy[2*node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        //the  current update
        if(l<= start && end <= r)
        {
            tree[node] += (end - start + 1)*delta;
            if(start != end)
            {
                lazy[2*node + 1] += lazy[delta];
                lazy[2*node + 2] += lazy[delta];
            }
            return;
        }
        int mid = start + (end - start)/2;
        lazyupdate(2*node + 1, start, end, l, r, delta);
        lazyupdate(2*node + 2, start, end, l, r, delta);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }

    int lazyquery(int node, int start, int end, int l, int r)
    {
        //range out side
        if(start > r || end < l)
            return 0;
        //preexisting updates
        if(lazy[node] != 0)
        {
            tree[node] +=  (end- start + 1)*lazy[node];
            if(start!=end) //not a leaf node
            {
                lazy[2*node + 2] += lazy[node];
                lazy[2*node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(l<=start &&  end <= r) //completely overlaps
        {
            return tree[node];
        }
        int p1,p2,mid;
        mid = start + (end - start)/2;
        p1 = lazyquery(2*node+1, start, mid, l,r);
        p2 = lazyquery(2*node+2, mid+1, end, l,r);

        return p1 + p2;
    }
    public:
    SegmentTree(int n, int *inputarr):n(n)
    {
        //Copyingt the data
        arr = new int[n];
        for(int i = 0; i < n ; i++)
            arr[i] = inputarr[i];

        //Segment Tree Construction
        int s = n;
        if(!((s&-s) && s)) //if not a power of 2
            s = 2*n;
        else
            s = 2*nextPowerOf2(n);
        tree = new int[s];
        lazy = new int[s];
        memset(lazy,0,s);
        build(0,0,n-1);
    }
    void updateSegment(int index, int delta)
    {
        update(0, 0, n-1, index, delta);
    }
    void updateRange(int l, int r, int delta)
    {
        lazyupdate(0,0,n-1,l,r,delta);
    }
    int querySegment(int l, int r)
    {
        //return query(0,0,n-1,l,r);
        return lazyquery(0,0,n-1,l,r);
    }
};


int main()
{
    int A[5] = {1,2,3,4,5};
    SegmentTree s(5,A);
    cout<<s.querySegment(0,4)<<endl;
    s.updateRange(0,4,1);
    cout<<s.querySegment(0,4)<<endl;
    s.updateRange(0,4,2);
    cout<<s.querySegment(0,4)<<endl;
    //s.updateSegment(5,1);
    return 0;
}

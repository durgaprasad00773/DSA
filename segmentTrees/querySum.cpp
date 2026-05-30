#include<bits/stdc++.h>
using namespace std;

vector<int> SegmentTree;
vector<int> arr;
int n;

void buildSegTree(int i, int l, int r)
{
    if(l == r)
    {
        SegmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    buildSegTree(2 * i + 1, l, mid);
    buildSegTree(2 * i + 2, mid + 1, r);

    SegmentTree[i] = SegmentTree[2 * i + 1] + SegmentTree[2 * i + 2];
}

int querySegTree(int qs, int qe, int i, int l, int r)
{
    if(qe < l || qs > r)
    return 0;

    if(l >= qs && r <= qe)
    return SegmentTree[i];

    int mid = l + (r-l)/2;
    return querySegTree(qs, qe, 2*i+1, l, mid)+querySegTree(qs, qe, 2*i+2, mid+1, r);
}

void updateSegTree(int idx, int val, int i, int l, int r)
{
    if(l == r)
    {
        SegmentTree[i] = val;
        return;
    }
    int mid = l+(r-l)/2;

    if(idx <= mid)
    {
        updateSegTree(idx, val, 2*i+1,  l, mid);
    }
    else
    {
        updateSegTree(idx, val, 2*i+2, mid+1, r);
    }

    SegmentTree[i] = SegmentTree[2*i+1]+SegmentTree[2*i+2];
}

int main()
{
    arr = {5, 8, 6, 3, 2, 7, 2, 6};

    n = arr.size();

    SegmentTree.resize(4 * n, 0);

    buildSegTree(0, 0, n - 1);

    cout << "Initial Queries\n";

    cout << querySegTree(0, 7, 0, 0, n - 1) << endl; // 39
    cout << querySegTree(0, 3, 0, 0, n - 1) << endl; // 22
    cout << querySegTree(2, 5, 0, 0, n - 1) << endl; // 18
    cout << querySegTree(4, 4, 0, 0, n - 1) << endl; // 2
    cout << querySegTree(6, 7, 0, 0, n - 1) << endl; // 8

    cout << "\nUpdate index 3 to 10\n";

    arr[3] = 10;
    updateSegTree(3, 10, 0, 0, n - 1);

    cout << querySegTree(0, 7, 0, 0, n - 1) << endl; // 46
    cout << querySegTree(2, 5, 0, 0, n - 1) << endl; // 25
    cout << querySegTree(3, 3, 0, 0, n - 1) << endl; // 10

    cout << "\nUpdate index 0 to 1\n";

    arr[0] = 1;
    updateSegTree(0, 1, 0, 0, n - 1);

    cout << querySegTree(0, 3, 0, 0, n - 1) << endl; // 25
    cout << querySegTree(0, 0, 0, 0, n - 1) << endl; // 1
    cout << querySegTree(1, 7, 0, 0, n - 1) << endl; // 41

    return 0;
}
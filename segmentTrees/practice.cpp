#include <bits/stdc++.h>
using namespace std;
void build(int index, int l, int r, vector<int> &arr, vector<int> &ST)
{
    if(l==r)
    {
        ST[index] = arr[l];
        return ;
    }

    int mid = l + (r-l)/2;

    build(2*index+1, l, mid, arr, ST);
    build(2*index+2, mid+1, r, arr, ST);

    ST[index] = max(ST[2 * index + 1], ST[2 * index + 2]);
}
int search(int index, int l, int r, int ql, int qr, vector<int> &ST)
{
    if(ql > r || qr < l)
    return INT_MIN;

    if (l >= ql && r <= qr)
    return ST[index];

    int mid = l + (r-l)/2;

    int left = search(2*index+1, l, mid, ql, qr, ST);
    int right = search(2*index+2, mid+1, r, ql, qr, ST);

    return max(left, right);
}
int main()
{
    vector<int> arr = {4, 8, 1, 7, 3};
    int n = arr.size();
    vector<int> ST(4*n);

    build(0, 0, n-1, arr, ST);

    cout << search(0, 0, 4, 1, 3, ST);
}
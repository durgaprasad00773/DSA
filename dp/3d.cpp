#include <bits/stdc++.h>
using namespace std;
int find(int i, int j1, int j2, vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();

    if(j1 < 0 || j1 >= col || j2 < 0 || j2 >= col)
    return -1e9;

    if(i == row-1)
    {
        if(j1 == j2)
        {
            return arr[i][j1];
        }
        return arr[i][j1]+arr[i][j2];
    }
    int maxi = 0;
    vector<int> dj = {-1, 0, 1};
    for(int k=-1; k<2; k++)
    {
        for(int l = -1; l<2; l++)
        {
            if(j1!= j2){
                maxi = max(maxi, arr[i][j1] + arr[i][j2] + find(i+1, j1+k, j2+l, arr));
            }
            else{
                maxi = max(maxi, arr[i][j1] + find(i+1, j1+k, j2+l, arr));
            }
        }
    }

    return maxi;


}
int main()
{
    vector<vector<int>> arr = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };

    cout << find(0, 0, 3, arr);

}
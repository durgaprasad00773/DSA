#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void find(int index, int pay, int &ans, vector<int> &cost)
    {
        int n = cost.size();
        if(index > n)
        return ;

        if(index == n)
        {
            ans = min(ans, pay);
            return ;
        }

        pay += cost[index];

        find(index+1, pay, ans, cost);

        find(index+2, pay, ans, cost);
    }
int main()
{
    vector<int> cost = {10, 15, 20};
    int ans = INT_MAX;
    find(0, 0, ans, cost);
    find(1, 0, ans, cost);

    cout << ans;
}
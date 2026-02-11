#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> ans(2);
    for(int i=0; i<nums.size()-1; i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {3,2,4};
    int target = 6;
    vector <int> ans = twoSum(arr, target);
    for(int i=0; i<2; i++)
    {
        cout << ans[i] <<  "  ";
    }
}
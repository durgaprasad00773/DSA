#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
string non(string &str)
{
    string ans;
    vector<int> repeated(26, 0);
    int n = str.size();
    queue <char> q;
    for(int i=0; i<n; i++)
    {
        for (int i = 0; i < n; i++)
    {
        repeated[str[i] - 'a']++;
        q.push(str[i]);
        while (!q.empty() && repeated[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
        else
        {
            ans.push_back(q.front());
        }
    }
    return ans;
    }
}
int main()
{
    string str = "aabbcc";
    cout << non(str);
}
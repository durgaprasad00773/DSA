#include<iostream>
#include<string>
#include<vector>
using namespace std;
void parenthesis(int n, int left, int right, vector<string> &v, string &temp)
{
    if(left > n && right > n)
    {
        v.push_back(temp);
        return;
    }
    //left bracket
    if(left<=n)
    {
        temp.push_back('(');
        parenthesis(n,left+1,right, v,temp);
        temp.pop_back();
    }
    //right bracket
    if(right < left)
    {
        temp.push_back(')');
        parenthesis(n,left,right+1, v,temp);
        temp.pop_back();
    }
}
int main()
{
    vector <string> v;
    int n;
    cout << "Enter n : ";
    cin >> n;
    int left = 1;
    int right = 1;
    string temp;
    parenthesis(n,left, right, v,temp);
    for(auto i : v)
    {
        cout << i << "  ";
    }
}
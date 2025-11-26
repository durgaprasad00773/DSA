#include<iostream>
#include <vector>
using namespace std;
int main()
{
    string str = "abbbabbcbbac";
    int n = str.length();
    int left = 0;
    int right = 0;
    int len = n;
    int count = 0;
    int arr[256] = {0};
    for(int i=0; i<n; i++)
    {
        if(arr[str[i]] == 0)
        {
            count++;
        }
        else{
            arr[str[i]]++;
        }
    }
    for(int i=0; i<256; i++)
    {
        arr[i] = 0;
    }
    while(right < n)
    {
        //count > 0
        while(count > 0)
        {
            if(arr[str[right]] == 0)
            {
                count--;
                arr[str[right]]++;
                right++;
            }
        }
        len = min(len , right - left + 1);
        while(count == 0)
        {
            if(arr[str[left]] == 0)
            {
                count++;
            }
            arr[str[left]]--;
            left++;
        }
    }
    cout << len;
}
#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s)
{
    int idx[128];
    for (int i = 0; i < 128; i++)
    {
        idx[i] = -1;
    }
    int ans = 0;
    for (int i = 0, j = 0; j < s.size();j++)
    {
      i = (idx[s[j]] > i) ? idx[s[j]] : i;
      ans = (ans > j-i+1) ? ans : j-i+1;
      idx[s[j]] = j+1;
    }
    return ans;
}

int main()
{
    Solution s;
    string str;
    cin>>str;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
}

#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
  int cnt = 0;
  int total = nums1.size() + nums2.size();
  int tofind = total/2;
  vector<int>::iterator i = nums1.begin(), j = nums2.begin();
  vector<int>::iterator pre, now;
  while ( cnt < tofind + 1)
  {
    if (i == nums1.end())
    {
      pre = now;
      now = j;
      j++;cnt++;
    }else if (j == nums2.end())
    {
      pre = now;
      now = i;
      i++;cnt++;
    }else if(*i < *j)
    { 
      pre = now;
      now = i;
      i++;cnt++;
    }else{
      pre = now;
      now = j;
      j++;cnt++;
    }
  }
  if (total - 2 * tofind == 0)
  {
    return (double)(*pre + *now)/2;
  }else
  {
    return (double)(*now);
  }
}
    

int main()
{
  vector<int> c = {5,7,11,12};
  vector<int> m = {1,3,7,9};
  vector<int> dump;
  Solution s;
  cout << (dump.begin() == dump.end())<<endl;
  cout << s.findMedianSortedArrays(c, m)<<endl;
  return 0;
  
}

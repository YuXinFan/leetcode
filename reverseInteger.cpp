#include <string>
#include <iostream>
#include <algorithm>  
#include <cstdlib>
using namespace std;

class Solution {
  public:
    int reverse(int x);
};

int Solution::reverse(int x){
  int absx = abs(x);
  int flag = x > 0;
  string str_t = to_string(absx);
  std::reverse(str_t.begin(), str_t.end());
  long int rt = atol(str_t.c_str());
  if (rt > 2147483647 || rt < -2147483648)
    return 0;
  return rt *= flag ? 1:-1;
}
int main()
{
  Solution s;
  int x;
  cin >> x;
  cout << s.reverse(x)<<endl;
  return 0;
}

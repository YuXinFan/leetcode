#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
        bool isPalindrome(int x);
};

bool Solution::isPalindrome(int x){
  if (x < 0)  return false;
  if (x <= 9) return true;
  string str = to_string(x);
  int len = str.size();
  for(int i = 0; i < len/2; i++){
    if (str[i] != str[len-1-i]) return false;
  }
  return true;
}

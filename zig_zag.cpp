#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string convert(string s, int numRows);
              
};

string Solution::convert(string s, int numRows){
  if (numRows == 1) return s;
  int n = s.size();
  int unit = numRows + numRows -2;
  int numUnits = n / unit;
  int tail = n - numUnits * unit;
  string ret = "";
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numUnits; j++){
      if (0<i && i< numRows-1){
        ret += s[j * unit + i];
        ret += s[(j+1) * unit - i];
      }else{
        ret += s[j * unit + i];
      }
    }
    if (i < tail){
      ret += s[unit * numUnits + i];
      if (unit - i < tail && unit - i >= numRows)
        ret += s[unit * (numUnits+1) - i];
    }
  }
  return ret;
}

int main()
{
  Solution s;
  string str; int n;
  cin >> str >> n;
  cout << s.convert(str, n)<<endl;
  return 0;
}

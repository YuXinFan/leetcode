#include <string>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
  public:
        int myAtoi(string str);
};
/*
int Solution::myAtoi(string str){
  int whiteSpace = str.find_first_not_of(" ");
  if (whiteSpace == 0){
    //cout << str.find_first_of("+-0123456789")<<endl;
    if (str.find_first_of("+-0123456789") == 0){
      bool isPositive = (str[0] == '-')?false:true;
      str = ( isPositive && str[0] != '+')?str:str.substr(1,str.size()-1);
      str = str.substr(0, str.find_first_not_of("0123456789"));
      str = isPositive?str:("-"+str);
      long raw = atol(str.c_str());
      int ret = (raw<=INT_MAX && raw >= INT_MIN)?raw:(isPositive?INT_MAX:INT_MIN);
      return ret;
    }
  }else if (whiteSpace > 0 &&  whiteSpace < str.size()){
    str = str.substr(whiteSpace, str.size()-whiteSpace);
    return myAtoi(str);
  }
  return 0;
}
*/
int Solution::myAtoi(string str){
  bool isPositive = true;
  int p = 0, len = str.size();
  while ( p < len && str[p] == ' '){
    p++;
  }
  if (str[p] == '-'){
    p++;
    isPositive = false;
  }else if (str[p] == '+')  p++;
  int sum = 0; int backup = 0;
  while( p < len && str[p] >= '0' && str[p]<= '9'){
    backup = sum;
    sum = sum * 10 + (str[p]-'0');
    if (backup != sum/10) return isPositive?INT_MAX:INT_MIN;
    p++;
  }
  return isPositive?sum:(-sum);
}

int main(){
  Solution s;
  string str;
  cin >> str;
  cout<<s.myAtoi(str)<<endl;
  return 0;
}


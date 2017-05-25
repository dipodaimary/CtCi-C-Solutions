#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
  bool stringrot(string &str1, string str2){
    if(str1.length()!=str2.length()){
      return false;
    }
    int n=str1.length();
    for(int i=0;i<str1.length();i++){
      bool res = true;
      int index = i;
      for(int j=0;j<str1.length()-1;j++){
        if(str1[j]!=str2[index]){
          res=false;
          break;
        }
        index=(index+1)%n;
      }
      return res;
    }
  }
};
int main(){
  Solution sol;
  string str1="hello";
  string str2 = "lohel";
  cout<<sol.stringrot(str1,str2)<<endl;
}
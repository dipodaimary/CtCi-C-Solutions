#include <iostream>
#include <map>
using namespace std;
int main(){
	string str="dipo daimary";
	map<char,int> mp;
	for(char &c:str){
		mp.insert(c);
	}
	for(auto it=mp.begin();it!=mp.end();it++){
		cout<<*it<<endl;
	}
}

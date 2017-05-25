#include <iostream>
#include <map>
using namespace std;
int main(){
	map<char,int> mp;
	string str="Dipo Daimary";
	for(char c: str){
		if(mp.find(c)==mp.end()){
			mp.insert(make_pair(c,1));
		}else{
			cout<<"Duplicate found: "<<c<<endl;
			return false;
		}
	}
	for(auto it=mp.begin();it!=mp.end();++it){
		it->second=2;
		cout<<(it->second)<<endl;
	}
}

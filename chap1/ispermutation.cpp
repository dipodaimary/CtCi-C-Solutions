#include <iostream>
#include <map>
using namespace std;
int main(){
	map<char,int> mp;
	string str="Dipo Daimary";
	string str2="Daimary Dipo";
	for(char c:str){
		mp.insert(make_pair(c,1));
	}
	for(char c:str2){
		auto it=mp.find(c);
		if(it!=mp.end()){
			it->second=it->second-1;
			if(it->second<0){
			//	cout<<"Strings are not permutation of each other"<<endl;
			//	return 0;
			}	
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++){
		if(it->second>0){
			cout<<"Strings are not permutation of each other"<<endl;
			return 0;
		}
	}
	cout<<"Strings are permutation of each other"<<endl;
}

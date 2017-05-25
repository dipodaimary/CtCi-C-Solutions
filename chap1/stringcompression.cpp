#include <iostream>
#include <map>
#include <sstream>
using namespace std;
int main(int argc, char **argv){
	map<char,int> mp;
	int compress=0;
	string str=argv[1];
	for(char c:str){
		auto it = mp.find(c); 
		if(it==mp.end()){
			mp.insert(make_pair(c,1));
		}else{
			it->second++;
			compress=1;
		}
	}
	stringstream ss;
	for(auto it=mp.begin();it!=mp.end();it++){
		if(compress){
			ss<<it->first<<it->second;
		}else{
			ss<<it->first;
		}
	}
	cout<<ss.str()<<endl;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main(){
	vector<char> mp;
	string str2 = "Taco cat";
	string str="";
	for(char c:str2){
		if(c!=' '){char d=tolower(c);str=str+d;
		}
	}
	cout<<str<<endl;
	for(char c: str){
		if(c!=' '){
			auto it=find(mp.begin(),mp.end(),c);
			if(it!=mp.end()){
				mp.erase(it);
			}else{
				mp.push_back(c);
			}
			copy(mp.begin(),mp.end(),ostream_iterator<char>(cout));
			cout<<endl;
		}
	}
	cout<<"Map size "<<mp.size()<<endl;
	if(mp.size()>1){
		cout<<"No palindrome possible"<<endl;
		return 0;
	}
	if(str.length()%2==0 && mp.size()>0){
		cout<<"No palindrome possible"<<endl;
	}else{
		cout<<"Permutation possible"<<endl;
	}
}

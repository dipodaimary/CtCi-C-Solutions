#include <iostream>
#include <sstream>
using namespace std;
int main(){
	string url="http://www.youtube.com/this is the end movie trailer";
	stringstream ss;
	for(char c:url){
		if(c!=' '){
			ss<<c;
		}else{
			ss<<"%20";
		}
	}
	cout<<ss.str()<<endl;
}

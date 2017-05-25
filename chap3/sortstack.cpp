#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
	void sortstack(stack<int> &s){
		if(s.empty()){
			return;
		}
		int curval = s.top();s.pop();
		sortstack(s);
		pushinorder(curval,s);
	}
	void pushinorder(int data, stack<int> &s){
		if(s.empty()||s.top()<data){
			s.push(data);
			return;
		}else{
			int curval = s.top();s.pop();
			pushinorder(data,s);
			s.push(curval);
		}
	}
};

int main(){
	Solution sol;
	stack<int> s;
	//Add
	s.push(30);
	s.push(-10);
	s.push(-5);
	s.push(18);
	s.push(14);
	s.push(-3);
	//End
	sol.sortstack(s);
	while(!s.empty()){
			cout<<s.top()<<" ";
			s.pop();
	}
	cout<<endl;
}
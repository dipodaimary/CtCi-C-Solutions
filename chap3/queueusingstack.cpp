#include <iostream>
#include <stack>
using namespace std;
class Queue{
	stack<int> inbox,outbox;
public:
	void queue(int item){
		inbox.push(item);
	}
	int dequeue(){
		if(outbox.empty()){
			while(!inbox.empty()){
				int n = inbox.top();
				inbox.pop();
				outbox.push(n);
			}
		}
	}
};
int main(){
	Queue sol;
	sol.queue(1);
}

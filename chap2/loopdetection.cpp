#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
public:
	void loopdetection(ListNode *root){
		ListNode *fast, *slow;
		int loop = 0;
		fast = root;
		slow = root;
		while(slow!=NULL && fast!=NULL && fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast){
				cout<<"Loop detected."<<endl;
				loop=1;
				break;
			}
		}
		if(!loop)
			cout<<"No loop detected."<<endl;
	}
};
int main(){
	Solution sol;
	ListNode *root = new ListNode(1);
	root->next =  new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next =  new ListNode(4);
	root->next->next->next->next = new ListNode(3);
	ListNode *loop = root->next->next->next->next;
	root->next->next->next->next->next = new ListNode(2);
	root->next->next->next->next->next->next = new ListNode(1);
	root->next->next->next->next->next->next->next = new ListNode(8);
	root->next->next->next->next->next->next->next->next = loop;
	sol.loopdetection(root);
}
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	void deletemiddlenode(ListNode *root){
		if(root->next==NULL){
			root=NULL;
		}
		ListNode *slow, *fast;
		slow=root;
		fast=root;
		ListNode *prev;
		while(slow!=NULL && fast->next!=NULL){
			fast=fast->next->next;
			prev = slow;
			slow=slow->next;
		}
		prev->next = slow->next;
		delete(slow);
	}
	void display(ListNode *root){
		while(root!=NULL){
			cout<<root->val<<"->";
			root=root->next;
		}
		cout<<"NULL"<<endl;
	}
};

int main(){
	Solution sol;
	ListNode *root = new ListNode(1);
	root->next =  new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next =  new ListNode(4);
	root->next->next->next->next = new ListNode(5);
	root->next->next->next->next->next = new ListNode(6);
	root->next->next->next->next->next->next = new ListNode(7);
	sol.deletemiddlenode(root);
	sol.display(root);
}
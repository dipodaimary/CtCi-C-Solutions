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
	void kthtolast(ListNode *root, int k){
		ListNode *node1, *node2;
		node1 = root;
		node2 = root;
		for(int i=0;i<k;i++){
			node2 = node2->next;
		}
		while(node2!=NULL){
			node1=node1->next;
			node2=node2->next;
		}
		cout<<node1->val<<endl;
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
	sol.kthtolast(root, 3);
}
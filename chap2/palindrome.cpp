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
	bool palindrome(ListNode *root){
		return palindromeUtil(&root,root);
	}
	bool palindromeUtil(ListNode **left, ListNode *right){
		if(right==NULL)
			return true;
		bool isp = palindromeUtil(left,right->next);
		if(isp==false)
			return false;
		bool isp1 = (right->val == (*left)->val);
		*left = (*left)->next;
		return isp1;
	}
};
int main(){
	Solution sol;
	ListNode *root = new ListNode(1);
	root->next =  new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next =  new ListNode(4);
	root->next->next->next->next = new ListNode(3);
	root->next->next->next->next->next = new ListNode(2);
	root->next->next->next->next->next->next = new ListNode(1);
	//root->next->next->next->next->next->next->next = new ListNode(8);
	cout<<sol.palindrome(root)<<endl;
}
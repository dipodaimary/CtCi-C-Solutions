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
	void sumlists(ListNode *l1, ListNode *l2){
		cout<<number(l1)+number(l2)<<endl;
	}

	int number(ListNode *root){
		int ans=0;
		int count = 0;
		while(root!=NULL){
			ans+=(root->val)*pow(10,count);
			count++;
			root=root->next;
		}
		return ans;
	}
};
int main(){
	Solution sol;
	ListNode *root = new ListNode(1);
	root->next =  new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next =  new ListNode(4);
	root->next->next->next->next = new ListNode(5);
	ListNode *root2=new ListNode(2);
	root2->next = new ListNode(3);
	sol.sumlists(root,root2);
}
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
	void removedup(ListNode *root){
		ListNode *ptr1, *ptr2, *dup;
		ptr1 = root;
		while(ptr1!=NULL && ptr1->next!=NULL){
			ptr2=ptr1;
			while(ptr2->next!=NULL){
				if(ptr1->val==ptr2->next->val){
					dup = ptr2->next;
					ptr1->next=ptr2->next->next;
					delete(dup);
				}else{	
					ptr2=ptr2->next;
				}
			}
			ptr1=ptr1->next;
		}
	}
	void display(ListNode *root){
		while(root!=NULL){
			cout<<root->val<<"->";
			root=root->next;
		}
		cout<<"NULL"<<endl;
	}
};
class Solution2{
public:
	void removedup(ListNode *root){
		set<int> seen;
		ListNode *curr,*prev;
		prev = NULL;
		curr = root;
		while(curr!=NULL){
			if(seen.find(curr->val)!=seen.end()){
				prev->next=curr->next;
				delete(curr);
			}else{
				seen.insert(curr->val);
				prev=curr;
			}
			curr=prev->next;
		}
	}
};
int main(){
	ListNode *root = new ListNode(4);
	root->next=new ListNode(6);
	root->next->next = new ListNode(6);
	ListNode *root2 = root->next->next;
	root2->next = new ListNode(6);
	Solution sol;
	Solution2 sol2;
	sol.display(root);
	sol2.removedup(root);
	sol.display(root);
}
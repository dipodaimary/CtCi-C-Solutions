#include <iostream>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};
class Solution{
	int height(node *root){
		if(root==NULL)
			return 0;
		return 1+max(height(root->left),height(root->right));
	}
public:
	bool isbalanced(node *root){
		if(root==NULL)
			return true;
		int lh = height(root->left);
		int rh = height(root->right);
		if(abs(lh-rh)<=1 && isbalanced(root->left) && isbalanced(root->right))
			return true;
		return false;
	}
};
int main(){
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->left->left->left = new node(8);
	Solution sol;
	if(sol.isbalanced(root)){
		cout<<"Tree is balanced"<<endl;
	}else{
		cout<<"Tree is not balanced"<<endl;
	}
}
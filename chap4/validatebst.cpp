#include <iostream>
#include <climits>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int x): data(x), left(NULL), right(NULL){}
};
class Solution{
	bool isBSTUtil(node *node, int min, int max){
		if(node == NULL)
			return true;
		if(node->data<min || node->data>max)
			return false;
		return (isBSTUtil(node->left,min,node->data-1) && isBSTUtil(node->right,node->data+1,max));
	}
public:
	bool isBST(node *node){
		return isBSTUtil(node, INT_MIN, INT_MAX);
	}
};
int main(){
	node *root = new node(4);
  	root->left        = new node(2);
  	root->right       = new node(5);
  	root->left->left  = new node(1);
  	root->left->right = new node(3);
  	Solution sol;
  	if(sol.isBST(root))
  		cout<<"Is BST"<<endl;
  	else
  		cout<<"Not BST"<<endl;
}
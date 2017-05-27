#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(int x): data(x), left(NULL), right(NULL){};
};
class Solution{
	bool areIdentical(Node *root1, Node *root2){
		if(root1==NULL && root2==NULL)
			return true;
		if(root2==NULL || root1 == NULL)
			return false;
		return (root1->data == root2->data && areIdentical(root1->left,root2->left) && areIdentical(root1->right, root2->right));
	}
public:
	bool isSubtree(Node *T, Node *S){
		if(S==NULL || T==NULL)
			return false;
		if(areIdentical(T,S))
			return true;
		return (isSubtree(T->left,S)||isSubtree(T->right,S));
	}
	~Solution(){
		cout<<endl;
	};
};
int main(){
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    Node *T = new Node(26);
    T->right              = new Node(3);
    T->right->right       = new Node(3);
    T->left               = new Node(10);
    T->left->left         = new Node(4);
    T->left->left->right  = new Node(30);
    T->left->right        = new Node(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    Node *S    = new Node(10);
    S->right          = new Node(6);
    S->left           = new Node(4);
    S->left->right    = new Node(30);
 
 	Solution sol;
    if (sol.isSubtree(T, S))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");
    return 0;
}
#include <iostream>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node *parent;
	//node(int x): data(x), left(NULL), right(NULL){}
};
class Solution{
public:
	node *minValue(node* node){
		node *temp;
		//while(temp->left!=NULL){
			//temp=temp->left;
		//}
		return temp;
	}
	node *inordersuccessor(node *root, node *n){
		if(n->right !=NULL)
			return minValue(n->right);
		node *p = n->parent;
		while(p!=NULL && n==p->right){
			n=p;
			p=p->parent;
		}
		return p;
	}
};
int main(){

}
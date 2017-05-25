#include <iostream>
#include <vector>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(int x): data(x), left(NULL), right(NULL){};
};
class Solution{
	node *minimaltree(vector<int> &arr, int low, int high){
		if(low>high){
			return NULL;
		}
		int mid = (low+high)/2;
		node *root = new node(arr[mid]);
		root->left = minimaltree(arr, low, mid-1);
		root->right = minimaltree(arr,mid+1,high);
		return root;
	}
public:
	node *minimaltree(vector<int> &arr){
		if(arr.size()==0){
			return NULL;
		}
		return minimaltree(arr,0,arr.size()-1);
	}
	void preorder(node *root){
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	~Solution(){
		cout<<endl;
	}
};
int main(){
	Solution sol;
	int a[]={1,2,3,4,5,6,7,8};
	vector<int> arr(a,a+8);
	node *root = sol.minimaltree(arr);
	sol.preorder(root);
}
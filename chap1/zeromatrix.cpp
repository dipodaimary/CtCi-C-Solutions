#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution{
public:
	void zeromatrix(vector<vector<int>> &mat){
		bool firstrow = false;
		bool firstcol = false;
		for(int i=0;i<mat[0].size();i++){
			if(mat[0][i]==0){
				firstrow = true;
			}
		}
		for(int i=0;i<mat.size();i++){
			if(mat[i][0]==0){
				firstcol = true;
			}
		}
		for(int i=0;i<mat.size();i++){
			for(int j=0;j<mat[0].size();j++){
				if(mat[i][j]==0){
					mat[0][j]=0;
					mat[i][0]=0;
				}
			}
		}
		for(int i=0;i<mat.size();i++){
			for(int j=0;j<mat[0].size();j++){
				if(mat[i][0]==0 || mat[0][j]==0){
					mat[i][j]=0;
				}
			}
		}
		if(firstcol){
			for(int i=0;i<mat[0].size();i++){
				mat[i][0]=0;
			}
		}
		if(firstrow){
			for(int j=0;j<mat.size();j++){
				mat[0][j]=0;
			}
		}
	}
};
class Solution2{
public:
	void zeromatrix(vector<vector<int>> &mat){
		vector<int> x,y;
		for(int i=0;i<mat[0].size();i++){
			int boole =1;
			for(int j=0;j<mat.size();j++){
				boole=boole*mat[i][j];
			}
			if(boole){
				x.push_back(i);
			}
		}
		for(int j=0;j<mat.size();j++){
			int boole =1;
			for(int i=0;i<mat[0].size();i++){
				boole=boole*mat[i][j];
			}
			if(boole){
				y.push_back(j);
			}
		}
		copy(x.begin(),x.end(),ostream_iterator<int>(cout," "));cout<<endl;
		copy(y.begin(),y.end(),ostream_iterator<int>(cout," "));cout<<endl;
		for(int i=0;i<mat[0].size();i++){
			for(int j=0;j<mat.size();j++){
				mat[i][j]=0;
			}
		}
		for(auto it=x.begin();it!=x.end();it++){
			for(auto it2=y.begin();it2!=y.end();it2++){
				mat[*it][*it2]=1;
			}
		}
	}
};
int main(){
	vector<vector<int>> mat={{1, 0, 1, 1, 0},{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},{1, 0, 1, 1, 1},{1, 1, 1, 1, 1}};
	/*Solution sol;
	sol.zeromatrix(mat);
	*/
	Solution2 sol2;
	sol2.zeromatrix(mat);
	for(auto it=mat.begin();it!=mat.end();it++){
		copy(it->begin(),it->end(),ostream_iterator<int>(cout," "));
		cout<<endl;
	}
}
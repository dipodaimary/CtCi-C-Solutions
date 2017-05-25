#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
void rotatematrix(vector<vector<int>> &mat){
	int N = mat.size();
	for(int x=0;x<N/2;x++){
		for(int y=x;y<N-x-1;y++){
			int temp = mat[x][y];
			mat[x][y]=mat[y][N-1-x];
			mat[y][N-1-x]=mat[N-1-x][N-1-y];
			mat[N-1-x][N-1-y]=mat[N-1-y][x];
			mat[N-1-y][x]=temp;
		}
	}
}
int main(){
	vector<vector<int>> mat={{1,2,3,4},{7,8,9,10},{11,12,13,14},{15,16,17,18}};
	for(auto it =mat.begin();it<mat.end();it++){
		copy(it->begin(),it->end(),ostream_iterator<int>(cout," "));
		cout<<endl;
	}
	rotatematrix(mat);
	cout<<"Rotated:"<<endl;
	for(auto it =mat.begin();it<mat.end();it++){
		copy(it->begin(),it->end(),ostream_iterator<int>(cout," "));
		cout<<endl;
	}
}
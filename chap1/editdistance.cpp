#include <iostream>
using namespace std;
int min(int x,int y,int z){
	return min(x,min(y,z));
}
int editdistance(string str1, string str2){
	cout<<str1<<endl;
	int m=str1.size();
	int n=str2.size();
	int dp[m+1][n+1];
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			if(i==0){
				dp[i][j]=j;
			}else{
				if(j==0){
					dp[i][j]=i;
				}else{
					if(str1[i-1]==str2[j-1]){
						dp[i][j]=dp[i-1][j-1];
					}else{
						dp[i][j]=1+min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
					}
				}
			}
		}
	}
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[m][n];
}
int main(){
	string str="dipo";
	string str2="dipudaimary";
	int distance = editdistance(str,str2);
	if(distance>1){
		cout<<"more than one edit"<<endl;
	}
}
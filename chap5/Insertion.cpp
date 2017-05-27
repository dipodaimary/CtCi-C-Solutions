#include <iostream>
using namespace std;
class Solution{
public:
	int setBits(int n, int m, int i, int j) {
		int max = ~0;
		int tempI = max - ((1 << j) - 1);
		int tempJ = (1 << i) - 1;
		int tempIJ = tempI | tempJ;
		int tempN = n & tempIJ;
		int tempM = m << i; 
		int tempNM = tempN | tempM;
		return tempNM;
	}
};
int main(){
	int n = 1024;
	int m = 21;
	int output = 1108;
	Solution sol;
	cout<<sol.setBits(n,m,2,6)<<endl;
}
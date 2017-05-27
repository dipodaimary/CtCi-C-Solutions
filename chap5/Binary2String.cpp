#include <iostream>
#include <sstream>
using namespace std;
class Solution{
public:
	string printBinary(double num){
        // Check Number is Between 0 to 1 or Not
        if (num >= 1 || num <= 0)
            return "ERROR";
 
        stringstream binary;
        binary<<".";
 
        while (num > 0){
            if (binary.tellp() >= 32)
                return "ERROR";
            double r = num * 2;
            if (r >= 1){
                binary<<1;
                num = r - 1;
            }else{
                binary<<0;
                num = r;
            }
        }
        return binary.str();
    }
};
int main(){
	Solution sol;
	double num1 = 0.625; // Input value in Decimal
    string output = sol.printBinary(num1);
    cout<<"(0"<<output <<")  in base 2"<<endl;
 
    double num2 = 0.72;
    output = sol.printBinary(num2);
    cout<<"("<<output<<")  in base 2"<<endl;
}
#include <iostream>
using namespace std;
 
int flipBit(unsigned a){
    /* If all bits are l, binary
       representation of 'a' has all 1s */
    if (~a == 0)
        return 8*sizeof(int);
 
    int currLen = 0, prevLen = 0;
 
    // We can always have a sequence of
    // at least one 1
    int maxLen = 1;
 
    while (a!= 0){
        // Current bit is a 1
        if ((a & 1) == 1)
            currLen++;
 
        // Current bit is a 0
        else if ((a & 1) == 0){
            /* Update to 0 (if next bit is 0)
               or currLen (if next bit is 1). */
            prevLen = (a & 2) == 0? 0 : currLen;
            currLen = 0;
        }
 
        // Update maxLen if required
        maxLen = max(prevLen + currLen + 1, maxLen);
 
        // Remove last bit (Right shift)
        a >>= 1;
    }
 
    return maxLen;
}
 
// Driver code
int main(){
   cout << flipBit(1775)<<endl;
   return 0;
}
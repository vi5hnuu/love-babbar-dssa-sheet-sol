// Given a non-negative number N and two values L and R. The problem is to set all the bits in the range L to R in the binary representation of N.

// Example 1:

// Input :
// N = 17, L = 2, R = 3 
// Output :
// 23
// Explanation:
// (17)10 = (10001)2
// (23)10 = (10111)2
// The bits in the range 2 to 3 in the binary
// representation of 17 are set.


 int setAllRangeBits(int N , int L , int R) {
       while((L-1)!=R){
           N=N|(1<<(L-1));
           L++;
       }
       return N;
    }
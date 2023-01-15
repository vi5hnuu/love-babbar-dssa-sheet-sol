// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// -104 <= xn <= 104

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(n<0){
//             // return myPow(1.0/x,-n); //n =-2147483648 or see last sol.
//             return 1.0/x*myPow(1.0/x,-(n+1));
//         }
//         else if(n==0 | x==1.0){
//             return 1.0;
//         }else if(n==2){
//             return x*x;
//         }
        
//         if(n%2==0){
//             double hlf= myPow(x,n/2);
//             return hlf*hlf;
//         }else{
//             return x*myPow(x,n-1);
//         }
//     }
// };

////////////////
// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(x==0){
//             return 0;
//         }
//         if(n==0 | x==1.0){
//             return 1.0;
//         }
//         double t=myPow(x,n/2);
//         if(n%2==0) 
//             return t*t;
//         else 
//             return n<0 ? 1/x*t*t : x*t*t;
//     }
// };
///////////////
class Solution {
public:
    double myPow(double x, int n) {
        if(x==-1.0){
            return n&1 ? -1.0 : 1.0; 
        }else if(x==1.0){
            return 1.0;
        }else if(x==0 || n==INT_MIN){
            return 0;
        }
        else if(n==0){
            return 1.0;
        }
        
        if(n<0){
            x=1/x;
            n=-n;
        }
        double ans=1;
        while(n>0){
            if(n&1)
                ans*=x;
            x*=x;
            n>>=1;
        }

        return ans;
    }
};
/////////////////////////
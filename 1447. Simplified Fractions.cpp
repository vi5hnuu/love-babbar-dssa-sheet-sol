/*
Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.

 

Example 1:

Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.
Example 2:

Input: n = 3
Output: ["1/2","1/3","2/3"]
Example 3:

Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".
 

Constraints:

1 <= n <= 100
*/

// class Solution {
// private:
//     bool haveCommonFactor(int num,int i,int n){
//             for(int k=2;k<=n;k++){
//                 if(num%k==0 && i%k==0){
//                     return true;
//                 }
//             }
//             return false;
//     }
// public:
//     vector<string> simplifiedFractions(int n) {
//         vector<string> ans;
//         for(int num=1;num<n;num++){
//             for(int i=sqrt(num);i<=n;i++){
//                 //
//                if(num!=i && num<i && !haveCommonFactor(num,i,n))
//                     ans.push_back(to_string(num)+"/"+to_string(i));
//             }
//         }
//         return ans;
//     }
// };
///////////////////////////////////////
// class Solution {
// private:
//     int gcd(int num,int i){
//         if(num<i){
//             swap(num,i);
//         }
//         if(i==0){
//             return num;
//         }
//         return gcd(num%i,i);
//     }
// public:
//     vector<string> simplifiedFractions(int n) {
//         vector<string> ans;
//         for(int num=1;num<n;num++){
//             for(int i=sqrt(num);i<=n;i++){
//                 int gc=gcd(num,i);
//                if(num!=i && num<i && (num==1 || !(gc!=1 && num%gc==0 && i%gc==0)))
//                     ans.push_back(to_string(num)+"/"+to_string(i));
//             }
//         }
//         return ans;
//     }
// };

//////////////////////////
class Solution {
private:
    int gcd(int num,int i){
        if(num<i){
            swap(num,i);
        }
        if(i==0){
            return num;
        }
        return gcd(num%i,i);
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for(int denominator=2;denominator<=n;denominator++){
            for(int numerator=1;numerator<denominator;numerator++){
               if(gcd(denominator,numerator)==1)
                    ans.push_back(to_string(numerator)+"/"+to_string(denominator));
            }
        }
        return ans;
    }
};
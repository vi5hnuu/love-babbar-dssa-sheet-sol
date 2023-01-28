/*
Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
Example 2:

Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".
Example 3:

Input: s = "zzzzz"
Output: 15
 

Constraints:

1 <= s.length <= 105
s consists of lowercase letters.
*/

// class Solution {
// public:
//     int countHomogenous(string s) {
//         stack<char> stck;
//         long long count=0;
//         for(const char &c:s){
//             if(stck.empty() || stck.top()!=c){
//                 int n=stck.size();
//                 count=(count+((n+n*(n-1)/2)%(1000000007)))%(1000000007);
//                 stck=stack<char>();
//             }
//                 stck.push(c);
//         }
//         if(!stck.empty()){
//             long long n=stck.size();
//             count=(count+((n+n*(n-1)/2)%(1000000007)))%(1000000007);
//         }
//         return count;
//     }
// };
//////////////////////////////
class Solution {
public:
    int countHomogenous(string s) {
        long long count=0;
        int len=s.length();
        if(len==1){
            return 1;
        }
        
        long long n=1;
        for(int i=1;i<len;i++){
            if(s[i-1]!=s[i]){
                count=(count+((n+n*(n-1)/2)%(1000000007)))%(1000000007);
                n=0;
            }
                n++;
        }
        count=(count+((n+n*(n-1)/2)%(1000000007)))%(1000000007);
        return count;
    }
};
/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

//TLE 218/231 ,  time O(N*N*N) | N is length of string
// class Solution {
// private:
//     bool validParenthesis(const string &s,int i,int j){
//         stack<char> stck;
//         for(int st=i;st<=j;st++){
//             if(stck.empty()){
//                 stck.push(s[st]);
//             }else if(s[st]==')' && stck.top()=='('){
//                 stck.pop();
//             }else{
//                 stck.push(s[st]);
//             }
//         }
//         return stck.empty();
//     }
// public:
//     int longestValidParentheses(string s) {
//         int i=0,j=1;
        
//         int maxLen=0;
//         while(i<j && j<s.length()){
//             cout<<i<<" "<<j<<endl;
//             bool ans=validParenthesis(s,i,j);
//             if(ans){
//                 maxLen=max(maxLen,j-i+1);
//             }
//             j+=2;
//             if(j>=s.length()){
//                 i++;
//                 j=i+maxLen+1;//we have maxLen valid length now we are in search of bigger len
//                 //than maxLen so from [i,maxLen+i+1]
//             }
//         }
//         return maxLen;
//     }
// };
///////////////////////////////////////////////////////
class Solution {
public:
    //betweel two invalid index lies the valid string of parenthesis....
    int longestValidParentheses(string s) {
        int slen=s.length();
        stack<int> stck;
        int maxLen=0;
        for(int i=0;i<slen;i++){
            if(s[i]=='('){
                stck.push(i);
                continue;
            }
            if(stck.empty()){
                stck.push(i);
                continue;
            }
            int tp=stck.top();
            stck.pop();
            if(s[tp]==')'){
                stck.push(i);
            }else{
                if(stck.empty()){
                    maxLen=max(maxLen,i+1);
                }else{
                    maxLen=max(maxLen,i-stck.top());
                }
            }
        }
        return maxLen;
    }
};




/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         ans.clear();
//         string temp;
//         help(0,0,n,temp);
//         return ans;
//     }
// private:
//     vector<string> ans;
//     void help(int o,int c,int n,string temp){
//         if(c==n){
//             ans.push_back(temp);
//         }
//         else{
//             if(o<n)
//                 help(o+1,c,n,temp+'(');
//             if(c<o)
//                 help(o,c+1,n,temp+')');
//         }
//     }
// };
////////////////clean code
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help(ans,n);
        return ans;
    }
private:
    void help(vector<string> &ans,int n,int o=0,int c=0,string temp=""){
        if(c==n){
            ans.push_back(temp);
        }
        else{
            if(o<n)
                help(ans,n,o+1,c,temp+'(');
            if(c<o)
                help(ans,n,o,c+1,temp+')');
        }
    }
};
////////////
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help(ans,n);
        return ans;
    }
private:
    void help(vector<string> &ans,int n,int o=0,int c=0,string temp=""){
        if(c==n){
            ans.push_back(temp);
        }
        else{
            if(o<n)
                help(ans,n,o+1,c,temp+'(');
            if(c<o)//closing only if opening present
                help(ans,n,o,c+1,temp+')');
        }
    }
};
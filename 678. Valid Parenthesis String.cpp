/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.
*/

//TLE 7 / 83 

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkValidString(const string &s,stack<char> &stck,int idx){
        if(idx>=s.length()){
            return stck.empty();
        }

        if(s[idx]=='('){
            stck.push(s[idx]);
            bool ans=checkValidString(s,stck,idx+1);
            stck.pop();
            return ans;
        }else if(s[idx]==')'){
            if(stck.empty() || stck.top()==')'){
                return false;
            }else{
                char c=stck.top();
                stck.pop();
                bool ans=checkValidString(s,stck,idx+1);
                stck.push(c);
                return ans;
            }
        }else{
            bool epty=checkValidString(s,stck,idx+1);
            if(epty){
                return true;
            }
            stck.push('(');
            bool lft=checkValidString(s,stck,idx+1);
            stck.pop();
            if(lft){
                return true;
            }
            bool rt=false;
            if(!stck.empty() && stck.top()=='('){
                char c=stck.top();
                stck.pop();
                rt=checkValidString(s,stck,idx+1);
                stck.push(c);
            }
            return rt;
        }
    }
public:
    bool checkValidString(string s) {
        stack<char> stck;
        return checkValidString(s,stck,0);
    }
};
/////////////////////////////////////////////
// Problem 1: Check Valid Parenthesis of a string containing only two types of characters: '(', ')'

class Solution {
    public boolean checkValidString(String s) {
        int openCount = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                openCount++;
            } else if (c == ')') {
                openCount--;
            }
            if (openCount < 0) return false;    // Currently, don't have enough open parentheses to match close parentheses-> Invalid
                                                // For example: ())(
        }
        return openCount == 0; // Fully match open parentheses with close parentheses
    }
}
// Problem 2: Check Valid Parenthesis of a string containing only three types of characters: '(', ')', '*'

// Example: image
class Solution {
public:
    bool checkValidString(string s) {
        int lpMin=0,lpMax=0; //using them like stack, left parenthesis range [lpMin,lpMax]

        for(const char &c:s){
            if(c=='('){
               lpMin++; 
               lpMax++;
            }else if(c==')'){
                lpMin--; 
                lpMax--;
            }else{//only for '*'
                lpMin--;//take ')'
                lpMax++;//take '('
            }
            if(lpMax<0){
                //we can never succeed )()()()((()))
                //we got more ) then ( => result is first char is ) 
                //=> which cannot make this string valid.
                return false;
            }
            lpMin = max(lpMin, 0);
            //lpMin<0 => we undo line 66 because taking this can never make this valid string..
            //eg *()
            //'if' and 'else if' work as stack for '(' and ')'
            // ((()())) canceld
            //left -> *()
            //now the string can be  
            //(() -> take '(' in a hope that we may get success, [0,1]
            //)(), -> it will disappoint us  -> 'X'
            //we are here to hunt for true,true,true,true,true,true not false
            //lpMin becomes negative becase we cancelled all '(' with ')' and now we got ')'
            //to cancel '(' which we dont have

            //lpMax become min becuase of same reason but but but..
            //it has used actual ')' not from '*' becuase '*' only ++ lpMax only actual ')' -- 
            //lpMax
            //so if lpMax become neg we can be certain to return false;

            //() -> ignore * -> we might get success [0,0]
        }
        return lpMin==0;
    }
};
// Complexity

// Time: O(n)
// Space: O(1)


int main(){
  string tcase="(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())";

  Solution sol;
  cout<<sol.checkValidString(tcase);
  return 0;
}


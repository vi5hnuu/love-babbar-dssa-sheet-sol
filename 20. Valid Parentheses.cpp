/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' )
                p.push(s[i]);
            else{
                if(p.empty())
                    return false;
                char c=p.top();
                p.pop();
                if(!(s[i]-c==1 || s[i]-c==2))
                    return false;
            }
        }
        if(!p.empty())
            return false;
        else
            return true;
    }
};
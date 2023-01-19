/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?
*/


class Solution {
int finalString(string &s){
    int len=s.length();
    int i=-1,j=0;
    while(s[j]=='#'){j++;}
    while(j<len){
        if(s[j]!='#'){
            s[++i]=s[j];
        }else{
            if(i>=0){
                i--;
            }
        }
        j++;
    }
    return i;
}
public:
    bool backspaceCompare(string s, string t) {
        int lastAccumulateIdx_s=finalString(s);
        int lastAccumulateIdx_t=finalString(t);
        if(lastAccumulateIdx_s!=lastAccumulateIdx_t){
            return false;
        }

        for(int i=0;i<=lastAccumulateIdx_s;i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
};
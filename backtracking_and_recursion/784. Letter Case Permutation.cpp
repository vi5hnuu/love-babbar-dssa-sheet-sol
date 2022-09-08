// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]
 

// Constraints:

// 1 <= s.length <= 12
// s consists of lowercase English letters, uppercase English letters, and digits.

class Solution {
    private:
    bool isAlpha(const char &c){
        if((c>='A' && c<='Z') || (c>='a' && c<='z')){
            return true;
        }
        else{
            return false;
        }
    }
    void letterCasePermutation(const string &s,vector<string> &res,string tmp="",int index=0) {
        if(index==s.length()){
            res.push_back(tmp);
            return;
        }
        
        if(isAlpha(s[index])){
            letterCasePermutation(s,res,tmp+static_cast<char>(tolower(s[index])),index+1);
            letterCasePermutation(s,res,tmp+static_cast<char>(toupper(s[index])),index+1);
        }else{
            letterCasePermutation(s,res,tmp+s[index],index+1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        letterCasePermutation(s,ans);
        return ans;
    }
};
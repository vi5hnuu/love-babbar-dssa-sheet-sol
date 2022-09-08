// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

class Solution {
private:
    string chr2str(char n){
        switch(n){
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default:return "unknown";
        }
    }
    void letterCombinations(const vector<string> &dgts,vector<string> &res,string ans="",int index=0) {
        if(index>=dgts.size()){
            res.push_back(ans);
            return;
        }
        
        for(const char &c:dgts[index]){
            letterCombinations(dgts,res,ans+c,index+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        if(!digits.length())
            return {};
        
        vector<string> res;
        vector<string> dgts;
        for(const char &c:digits){
            dgts.push_back(chr2str(c));
        }
        letterCombinations(dgts,res);
        return res;
    }
};
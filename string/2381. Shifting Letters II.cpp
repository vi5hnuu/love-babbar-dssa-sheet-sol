// You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

// Return the final string after all such shifts to s are applied.

 

// Example 1:

// Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
// Output: "ace"
// Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
// Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
// Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".
// Example 2:

// Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
// Output: "catz"
// Explanation: Firstly, shift the characters from index 0 to index 0 backward. Now s = "cztz".
// Finally, shift the characters from index 1 to index 1 forward. Now s = "catz".
 

// Constraints:

// 1 <= s.length, shifts.length <= 5 * 104
// shifts[i].length == 3
// 0 <= starti <= endi < s.length
// 0 <= directioni <= 1
// s consists of lowercase English letters.

/*
//naive
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(const vector<int> &v:shifts){
            for(int i=v[0];i<=v[1];i++){
                if(v[2]==1){
                    char ch=(s[i]+1);
                    if(ch>'z')
                        ch='a'+(ch-'z'-1);
                    s[i]=ch;
                }else{
                    char ch=(s[i]-1);
                    if(ch<'a')
                        ch='z'-('a'-ch-1);
                    s[i]=ch;
                }
            }
        }
        return s;
    }
};
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //line sweep
        int sz=s.length();
        vector<int> sweep(sz+1,0);
        for(const vector<int> &v:shifts){
            if(v[2]==1){
                sweep[v[0]]++;
                sweep[v[1]+1]--;
            }
            else{
                sweep[v[0]]--;
                sweep[v[1]+1]++;
            }
        }
        
        //fill the sweep
        for(int i=1;i<=sz;i++)
            sweep[i]+=sweep[i-1];
        
        //manipulate string
        for(int i=0;i<sz;i++){
            int increaseBy=(s[i]-'a'+sweep[i])%26;
			increaseBy=(increaseBy+26)%26;
			s[i]='a'+increaseBy;
        }
        
        return s;
    }
};
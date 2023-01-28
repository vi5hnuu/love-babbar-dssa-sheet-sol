/*
You are given a string s and array queries where queries[i] = [lefti, righti, ki]. We may rearrange the substring s[lefti...righti] for each query and then choose up to ki of them to replace with any lowercase English letter.

If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.

Return a boolean array answer where answer[i] is the result of the ith query queries[i].

Note that each letter is counted individually for replacement, so if, for example s[lefti...righti] = "aaa", and ki = 2, we can only replace two of the letters. Also, note that no query modifies the initial string s.

 

Example :

Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
Output: [true,false,false,true,true]
Explanation:
queries[0]: substring = "d", is palidrome.
queries[1]: substring = "bc", is not palidrome.
queries[2]: substring = "abcd", is not palidrome after replacing only 1 character.
queries[3]: substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
queries[4]: substring = "abcda", could be changed to "abcba" which is palidrome.
Example 2:

Input: s = "lyb", queries = [[0,1,0],[2,2,1]]
Output: [false,true]
 

Constraints:

1 <= s.length, queries.length <= 105
0 <= lefti <= righti < s.length
0 <= ki <= s.length
s consists of lowercase English letters.
*/


// class Solution {
// private:
//     bool ispalindrome(const string &s,int start,int end,int op){
//         if(start==end){
//             return true;
//         }
//         int slen=s.length();
//         int freq[26]{0};
//         for(int i=start;i<=end;i++){
//             freq[s[i]-'a']++;
//         }
//         int ones=0;
//         for(int j=0;j<26;j++){
//             ones+=freq[j]%2;
//             if(ones/2>op){
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
//         int qlen=queries.size();
//         vector<bool> ans(qlen,false);

//         int k=0;
//         for(const auto &query:queries){
//             int i=query[0];
//             int j=query[1];
//             int opsLeft=query[2];
//             ans[k++]=ispalindrome(s,query[0],query[1],query[2]);
//         }
//         return ans;
//     }
// };
/////////////////////////////
class Solution {
private:
    vector<int> prefix(const string &s){
        int slen=s.length();
        vector<int> pre(slen,0);
        int mask{};
        for(int i=0;i<slen;i++){
            mask^=(1<<(s[i]-'a')); // flip bits -> a -> 000001 => aa -> 000000 
            // => aaa -> 000001 => aaaa -> 000000
            pre[i]=mask;
        }
        return pre;
    }
    int countSetBits(int n){
        int count=0;
        while(n>0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int qlen=queries.size();
        vector<bool> ans(qlen,false);

        vector<int> pre=prefix(s);
        int k=0;
        for(const auto &query:queries){
            int i=query[0];
            int j=query[1];
            int ops=query[2];
            int odds=countSetBits(pre[j]^(i==0 ? 0 : pre[i-1]));//set bits in range
            cout<<odds<<" ";
            ans[k++]= (odds/2)<=ops;
        }
        return ans;
    }
};
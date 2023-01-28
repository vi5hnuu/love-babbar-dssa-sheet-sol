/*
There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.

 

Example 1:

ex-1
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.
Example 2:

ex-2
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.
 

Constraints:

3 <= s.length <= 105
s consists of '*' and '|' characters.
1 <= queries.length <= 105
queries[i].length == 2
0 <= lefti <= righti < s.length
*/

// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//         int qlen=queries.size();
//         vector<int> ans(qlen,0);
//         int k=0;
//         for(const vector<int> &query:queries){
//             int i=query[0];
//             while(i<query[1] && s[i]!='|'){i++;}
//             int count=0;
//             while(i<=query[1]){
//                 if(s[i]=='*'){
//                     count++;
//                 }else{
//                     ans[k]+=count;
//                     count=0;
//                 }
//                 i++;
//             }
//             k++;
//         }
//         return ans;
//     }
// };
/////////////////////////////////////
// class Solution {
// public:
//     vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
//         int qlen=queries.size();
//         int slen=s.length();
//         vector<int> ans(qlen,0);
//         vector<int> ncleft(slen,0);//nearest candle to left incl.
//         vector<int> ncright(slen,0);//nearest candle to right incl.
//         vector<int> candleCount(slen,0);//candles from 0 to i incl.
        
//         int candle=-1;
//         for(int i=0;i<slen;i++){
//             if(s[i]=='|'){
//                 candle= i;
//             }
//             ncleft[i]=candle;
//         }
//         candle=-1;
//         for(int i=slen-1;i>=0;i--){
//             if(s[i]=='|'){
//                 candle= i;
//             }
//             ncright[i]=candle;
//         }
//         int count = 0;
//         for (int i = 0; i <slen; ++i) {
//             if (s[i] == '|') {
//                 ++count;
//             }
//             candleCount[i] = count;
//         }
//         ////////////////////////////////////
//         int k=0;
//         for(const auto &query:queries){
//             int leftCandle=ncright[query[0]];
//             int rightCandle=ncleft[query[1]];
//             if(leftCandle<0 || rightCandle<0){
//                 ans[k++]=0;
//             }else{
//                 int diff=rightCandle-leftCandle;
//                 if(diff<=1){
//                     ans[k++]=0;
//                 }else{
//                     int rmcandles=candleCount[rightCandle]-candleCount[leftCandle]+1;
//                     ans[k++]=diff+1-rmcandles;
//                 }
//             }
//         }
//         return ans;
//     }
// };
////////////////////////////////////////////
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int qlen=queries.size();
        int slen=s.length();
        vector<int> ans;
        vector<int> candleIndexes;

        for(int i=0;i<slen;i++){
            if(s[i]=='|'){
                candleIndexes.push_back(i);
            }
        }
        ////////////////////////////////////
        for(const auto &query:queries){
            int i=lower_bound(candleIndexes.begin(),candleIndexes.end(),query[0])-candleIndexes.begin();
            int j=upper_bound(candleIndexes.begin(),candleIndexes.end(),query[1])-candleIndexes.begin()-1;
            ans.push_back(i < j ? (candleIndexes[j] - candleIndexes[i]) - (j - i) : 0);//(j-i)->candles between
        }
        return ans;
    }
};









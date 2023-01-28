/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:

Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:

Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 

Constraints:

1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters.
*/

//TLE 63 / 93
// class Solution {
// private:
//     long long getMin(initializer_list<long long> li){
//         long long mn=INT_MAX;
//         for(const long long &n:li){
//             mn=min(mn,n);
//         }
//         return mn;
//     }
//     int asciiSumOf(const string &s,int from){
//         int sum=0;
//         for(int i=from;i<s.length();i++){
//             sum+=static_cast<int>(s[i]);
//         }
//         return sum;
//     }
//     long long minimumDeleteSum(const string &s1,const string &s2,int idx1,int idx2) {
//         //if cur char not equal delete either one else move next
        
//         if(idx1>=s1.length() && idx2>=s2.length()){
//             // cout<<"Phase over\n";
//             return 0;
//         }

//         if(idx1>=s1.length()){
//             return asciiSumOf(s2,idx2);
//             // return s2[idx2]+minimumDeleteSum(s1,s2,idx1,idx2+1);
//         }
        
//         if(idx2>=s2.length()){
//             return asciiSumOf(s1,idx1);
//             // return s1[idx1]+minimumDeleteSum(s1,s2,idx1+1,idx2);
//         }
//         if(s1[idx1]==s2[idx2]){
//             return 0+minimumDeleteSum(s1,s2,idx1+1,idx2+1);
//         }
//         long long dlts1=minimumDeleteSum(s1,s2,idx1+1,idx2);
//         // cout<<"deleting "<<s1[idx1]<<endl;
//         dlts1=(dlts1==INT_MAX) ? INT_MAX : dlts1+static_cast<int>(s1[idx1]);

//         // cout<<"deleting "<<s2[idx2]<<endl;
//         long long dlts2=minimumDeleteSum(s1,s2,idx1,idx2+1);
//         dlts2=(dlts2==INT_MAX) ? INT_MAX : dlts2+static_cast<int>(s2[idx2]);
        
//         // cout<<getMin({dlts1,dlts2})<<endl;
//         return getMin({dlts1,dlts2});
//     }
// public:
//     int minimumDeleteSum(string s1, string s2) {
//         //if cur char not equal delete either one else move next
//         return minimumDeleteSum(s1,s2,0,0);
//     }
// };
/////////////////////////////////////////////////////
// class Solution {
// private:
//     long long getMin(initializer_list<long long> li){
//         long long mn=INT_MAX;
//         for(const long long &n:li){
//             mn=min(mn,n);
//         }
//         return mn;
//     }
//     int asciiSumOf(const string &s,int from){
//         int sum=0;
//         for(int i=from;i<s.length();i++){
//             sum+=static_cast<int>(s[i]);
//         }
//         return sum;
//     }
//     long long minimumDeleteSum(const string &s1,const string &s2,int idx1,int idx2,vector<vector<int>> &memo) {
//         //if cur char not equal delete either one else move next
        
//         if(idx1>=s1.length() && idx2>=s2.length()){
//             // cout<<"Phase over\n";
//             return 0;
//         }

//         if(idx1>=s1.length()){
//             return asciiSumOf(s2,idx2);
//             // return s2[idx2]+minimumDeleteSum(s1,s2,idx1,idx2+1);
//         }
        
//         if(idx2>=s2.length()){
//             return asciiSumOf(s1,idx1);
//             // return s1[idx1]+minimumDeleteSum(s1,s2,idx1+1,idx2);
//         }

//         if(memo[idx1][idx2]!=-1){
//             return memo[idx1][idx2];
//         }

//         if(s1[idx1]==s2[idx2]){
//             return memo[idx1][idx2]=0+minimumDeleteSum(s1,s2,idx1+1,idx2+1,memo);
//         }


//         long long dlts1=minimumDeleteSum(s1,s2,idx1+1,idx2,memo);
//         // cout<<"deleting "<<s1[idx1]<<endl;
//         dlts1=(dlts1==INT_MAX) ? INT_MAX : dlts1+static_cast<int>(s1[idx1]);

//         // cout<<"deleting "<<s2[idx2]<<endl;
//         long long dlts2=minimumDeleteSum(s1,s2,idx1,idx2+1,memo);
//         dlts2=(dlts2==INT_MAX) ? INT_MAX : dlts2+static_cast<int>(s2[idx2]);
        
//         // cout<<getMin({dlts1,dlts2})<<endl;
//         return memo[idx1][idx2]=getMin({dlts1,dlts2});
//     }
// public:
//     int minimumDeleteSum(string s1, string s2) {
//         //if cur char not equal delete either one else move next
//         int s1len=s1.length();
//         int s2len=s2.length();
//         vector<vector<int>> memo(s1len,vector<int>(s2len,-1));
//         return minimumDeleteSum(s1,s2,0,0,memo);
//     }
// };
////////////////////////////////////////////////////////
// class Solution {
// private:
//     long long getMin(initializer_list<long long> li){
//         long long mn=INT_MAX;
//         for(const long long &n:li){
//             mn=min(mn,n);
//         }
//         return mn;
//     }
//     int asciiSumOf(const string &s,int to){
//         int sum=0;
//         for(int i=0;i<to;i++){
//             sum+=static_cast<int>(s[i]);
//         }
//         return sum;
//     }
// public:
//     int minimumDeleteSum(string s1, string s2) {
//         //if cur char not equal delete either one else move next
//         int s1len=s1.length();
//         int s2len=s2.length();
//         vector<vector<int>> dp(s1len,vector<int>(s2len,-1));

//         //to follow rec we should traverse it from (n-1,n-1) [next solution]            
//         for(int i=0;i<s1len;i++){//row->word1
//             for(int j=0;j<s2len;j++){//col -> word2
//                 if(i==0 && j==0){
//                     dp[i][j]=(s1[i]==s2[j]) ? 0 : s1[i]+s2[j];
//                 }else if(i==0){
//                     if(s1[i]==s2[j]){
//                         //delete all previous
//                         dp[i][j]=asciiSumOf(s2,j);
//                     }else{
//                         dp[i][j]=dp[i][j-1]+s2[j];
//                     }
//                 }else if(j==0){
//                    if(s1[i]==s2[j]){
//                         //delete all up eles
//                         dp[i][j]=asciiSumOf(s1,i);
//                     }else{
//                         dp[i][j]=dp[i-1][j]+s1[i];
//                     }
//                 }else{
//                    if(s1[i]==s2[j]){
//                         dp[i][j]=dp[i-1][j-1];
//                     }else{
//                         dp[i][j]=getMin({s2[j]+dp[i][j-1],s1[i]+dp[i-1][j]});
//                     }
//                 }
//             }
//         }

//         return dp[s1len-1][s2len-1];
//     }
// };
////////////////////////////////////following recursion
class Solution {
private:
    long long getMin(initializer_list<long long> li){
        long long mn=INT_MAX;
        for(const long long &n:li){
            mn=min(mn,n);
        }
        return mn;
    }
    int asciiSumOf(const string &s,int from){
        int sum=0;
        for(int i=from;i<s.length();i++){
            sum+=static_cast<int>(s[i]);
        }
        return sum;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        //if cur char not equal delete either one else move next
        int s1len=s1.length();
        int s2len=s2.length();
        vector<vector<int>> dp(s1len,vector<int>(s2len,-1));

        for(int i=s1len-1;i>=0;i--){//row->word1
            for(int j=s2len-1;j>=0;j--){//col -> word2
                if(i==s1len-1 && j==s2len-1){
                    dp[i][j]=(s1[i]==s2[j]) ? 0 : s1[i]+s2[j];
                }else if(i==s1len-1){
                    if(s1[i]==s2[j]){
                        //delete all previous
                        dp[i][j]=asciiSumOf(s2,j+1);
                    }else{
                        dp[i][j]=dp[i][j+1]+s2[j];
                    }
                }else if(j==s2len-1){
                   if(s1[i]==s2[j]){
                        //delete all up eles
                        dp[i][j]=asciiSumOf(s1,i+1);
                    }else{
                        dp[i][j]=dp[i+1][j]+s1[i];
                    }
                }else{
                   if(s1[i]==s2[j]){
                        dp[i][j]=dp[i+1][j+1];
                    }else{
                        dp[i][j]=getMin({s2[j]+dp[i][j+1],s1[i]+dp[i+1][j]});
                    }
                }
            }
        }

        return dp[0][0];
    }
};
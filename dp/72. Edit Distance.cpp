/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

//TLE 23 / 1146
// class Solution {
// private:
//     int getMin(initializer_list<int> li){
//         int mn=INT_MAX;
//         for(const int &n:li){
//             mn=min(mn,n);
//         }
//         return mn;
//     }
//     int minDistance(string word1, string word2,int idx1,int idx2) {
//         if(idx2>=word2.length() && idx1>=word1.length()){
//             return 0; 
//         }
//         if(idx2>=word2.length()){
//             int dltrest=minDistance(word1,word2,idx1+1,idx2);
//             dltrest = (dltrest==INT_MAX) ? INT_MAX :dltrest+1;
//             return dltrest;
//         }
//         if(idx1>=word1.length()){
//             int insrtrest=minDistance(word1,word2,idx1,idx2+1);
//             insrtrest = (insrtrest==INT_MAX) ? INT_MAX :insrtrest+1;
//             return insrtrest;
//         }
//         int same=INT_MAX;
//         if(word1[idx1]==word2[idx2])//char matched
//             same=0+minDistance(word1,word2,idx1+1,idx2+1);
            
//         int dlt=minDistance(word1,word2,idx1+1,idx2);
//         dlt = (dlt==INT_MAX) ? INT_MAX :dlt+1;

//         int insrt=minDistance(word1,word2,idx1,idx2+1);
//         insrt = (insrt==INT_MAX) ? INT_MAX :insrt+1;
        
//         int rplc=minDistance(word1,word2,idx1+1,idx2+1);
//         rplc = (rplc==INT_MAX) ? INT_MAX :rplc+1;
        
//         return getMin({same,insrt,dlt,rplc});
//     }
// public:
//     int minDistance(string word1, string word2) {
//         int ans=minDistance(word1,word2,0,0);
//         return ans;
//     }
// };
/////////////////////////////////////////////////////////
//TLE 23 / 1146 
// class Solution {
// private:
//     int getMin(initializer_list<int> li){
//         int mn=INT_MAX;
//         for(const int &n:li){
//             mn=min(mn,n);
//         }
//         return mn;
//     }
//     int minDistance(string word1, string word2,int idx1,int idx2) {
//         if(idx2>=word2.length() && idx1>=word1.length()){
//             return 0; 
//         }
//         if(idx2>=word2.length()){
//             return word1.size()-idx1;//delete rest ops..
//         }
//         if(idx1>=word1.length()){
//             return word2.size()-idx2;//inseert rest ops...
//         }
//         int same=INT_MAX;
//         if(word1[idx1]==word2[idx2])//char matched
//             same=0+minDistance(word1,word2,idx1+1,idx2+1);
            
//         int dlt=minDistance(word1,word2,idx1+1,idx2);
//         dlt = (dlt==INT_MAX) ? INT_MAX :dlt+1;

//         int insrt=minDistance(word1,word2,idx1,idx2+1);
//         insrt = (insrt==INT_MAX) ? INT_MAX :insrt+1;
        
//         int rplc=minDistance(word1,word2,idx1+1,idx2+1);
//         rplc = (rplc==INT_MAX) ? INT_MAX :rplc+1;
        
//         return getMin({same,insrt,dlt,rplc});
//     }
// public:
//     int minDistance(string word1, string word2) {
//         int ans=minDistance(word1,word2,0,0);
//         return ans;
//     }
// };
//////////////////////////////////////////////////
// class Solution {
// private:
//     int getMin(initializer_list<int> li){
//         int mn=INT_MAX;
//         for(const int &n:li){
//             mn=min(mn,n);
//         }
//         return mn;
//     }
//     int minDistance(string word1, string word2,int idx1,int idx2,vector<vector<int>> &memo) {
//         if(idx2>=word2.length() && idx1>=word1.length()){
//             return 0; 
//         }
//         if(idx2>=word2.length()){
//             return word1.size()-idx1;//delete rest ops..
//         }
//         if(idx1>=word1.length()){
//             return word2.size()-idx2;//inseert rest ops...
//         }
//         if(memo[idx1][idx2]!=-1){
//             return memo[idx1][idx2];
//         }
//         int same=INT_MAX;
//         if(word1[idx1]==word2[idx2])//char matched
//             same=0+minDistance(word1,word2,idx1+1,idx2+1,memo);
            
//         int dlt=minDistance(word1,word2,idx1+1,idx2,memo);
//         dlt = (dlt==INT_MAX) ? INT_MAX :dlt+1;

//         int insrt=minDistance(word1,word2,idx1,idx2+1,memo);
//         insrt = (insrt==INT_MAX) ? INT_MAX :insrt+1;
        
//         int rplc=minDistance(word1,word2,idx1+1,idx2+1,memo);
//         rplc = (rplc==INT_MAX) ? INT_MAX :rplc+1;
        
//         return memo[idx1][idx2]=getMin({same,insrt,dlt,rplc});
//     }
// public:
//     int minDistance(string word1, string word2) {
//         int w1len=word1.length();
//         int w2len=word2.length();
//         vector<vector<int>> memo(w1len,vector<int>(w2len,-1));
//         int ans=minDistance(word1,word2,0,0,memo);
//         return ans;
//     }
// };
//////////////////////////////////////////////////
class Solution {
private:
    int getMin(initializer_list<int> li){
        int mn=INT_MAX;
        for(const int &n:li){
            mn=min(mn,n);
        }
        return mn;
    }
    int minDistance(string word1, string word2,int idx1,int idx2,vector<vector<int>> &memo) {
        if(idx2>=word2.length() && idx1>=word1.length()){
            return 0; 
        }
        if(idx2>=word2.length()){
            return word1.size()-idx1;//delete rest ops..
        }
        if(idx1>=word1.length()){
            return word2.size()-idx2;//inseert rest ops...
        }
        if(memo[idx1][idx2]!=-1){
            return memo[idx1][idx2];
        }
        if(word1[idx1]==word2[idx2])//char matched
            return memo[idx1][idx2]=0+minDistance(word1,word2,idx1+1,idx2+1,memo);
            
        int dlt=minDistance(word1,word2,idx1+1,idx2,memo);
        dlt = (dlt==INT_MAX) ? INT_MAX :dlt+1;

        int insrt=minDistance(word1,word2,idx1,idx2+1,memo);
        insrt = (insrt==INT_MAX) ? INT_MAX :insrt+1;
        
        int rplc=minDistance(word1,word2,idx1+1,idx2+1,memo);
        rplc = (rplc==INT_MAX) ? INT_MAX :rplc+1;
        
        return memo[idx1][idx2]=getMin({insrt,dlt,rplc});
    }
public:
    int minDistance(string word1, string word2) {
        int w1len=word1.length();
        int w2len=word2.length();
        vector<vector<int>> memo(w1len,vector<int>(w2len,-1));
        int ans=minDistance(word1,word2,0,0,memo);
        return ans;
    }
};
/////////////////////////////////////////////////
class Solution {
private:
    int getMin(initializer_list<int> li){
        int mn=INT_MAX;
        for(const int &n:li){
            mn=min(mn,n);
        }
        return mn;
    }
public:
    int minDistance(string word1, string word2) {
        int w1len=word1.length();
        int w2len=word2.length();
        if(w1len==0 || w2len==0){
            return max(w1len,w2len);
        }
        vector<vector<int>> dp(w1len,vector<int>(w2len,0));

        for(int i=0;i<w1len;i++){
            for(int j=0;j<w2len;j++){
                if(i==0 && j==0){
                    dp[i][j]= !(word1[i]==word2[j]);
                }else if(j==0){
                    dp[i][j]=word1[i]==word2[j] ? i : dp[i-1][j]+1;//delete count
                }else if(i==0){
                    dp[i][j]=word1[i]==word2[j] ? j : dp[i][j-1]+1;;//delete count
                }else{
                    if(word1[i]==word2[j]){
                        dp[i][j]=dp[i-1][j-1];
                    }else{
                        dp[i][j]=1+getMin({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                    }
                }
            }
        }
        //dp
        for(const vector<int> v:dp){
            for(const int n:v){
                cout<<n<<" ";
            }
            cout<<endl;
        }
        return dp[w1len-1][w2len-1];
    }
};
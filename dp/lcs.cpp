//Longest common subsequence
//TLE O(exp)
/*
class Solution {
private:
    int longestCommonSubsequence(const string &text1,const string &text2,int s1,int s2) {
        if(s1==0 || s2==0)
            return 0;
        if(text1[s1-1]==text2[s2-1])
            return 1+longestCommonSubsequence(text1,text2,s1-1,s2-1);
        else{
            int x1=longestCommonSubsequence(text1,text2,s1-1,s2);
            int x2=longestCommonSubsequence(text1,text2,s1,s2-1);
            return max(x1,x2);
        }
            
        
    }
public:
    //recursive
    int longestCommonSubsequence(string text1, string text2) {
            return longestCommonSubsequence(text1,text2,text1.length(),text2.length());    
    }
};
*/

//memoization
// O(MN)
/*
class Solution {
private:
    int longestCommonSubsequence(const string &text1,const string &text2,int s1,int s2, vector<vector<int>> &memo) {
        if(memo[s1][s2]!=-1)
            return memo[s1][s2];
        
        if(s1==0 || s2==0)
            return memo[s1][s2]=0;
        else if(text1[s1-1]==text2[s2-1])
            return memo[s1][s2]=(1+longestCommonSubsequence(text1,text2,s1-1,s2-1,memo));
        else{
            int x1=longestCommonSubsequence(text1,text2,s1-1,s2,memo);
            int x2=longestCommonSubsequence(text1,text2,s1,s2-1,memo);
            return memo[s1][s2]=max(x1,x2);
        }
            
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.length()+1,vector<int>(text2.length()+1,-1));    
        return longestCommonSubsequence(text1,text2,text1.length(),text2.length(),memo);    
    }
};
*/

//Tabulation
/*
//same as recursion (every possible combination)
    B   A   Z
  0 0   0   0  
A 0 0   1   1
X 0 0   1   1
Y 0 0   1   1
Z 0 0   1   2
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> table(text1.length()+1,vector<int>(text2.length()+1,0));    
        int l1=text1.length(),l2=text2.length();
        for(int i=0;i<l1;i++)
            for(int j=0;j<l2;j++){
                if(text1[i]==text2[j])
                    table[i+1][j+1]=table[i][j]+1;
                else
                    table[i+1][j+1]=max(table[i][j+1],table[i+1][j]);
            }
        return table[l1][l2];
    }
};
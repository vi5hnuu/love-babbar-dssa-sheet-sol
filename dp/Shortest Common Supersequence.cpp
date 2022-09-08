// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.
// Example 2:

// Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
// Output: "aaaaaaaa"

class Solution {
    
public:
    string shortestCommonSupersequence(string str1, string str2) {
        //rest+LCS+rest
        int s1l=str1.length();
        int s2l=str2.length();
        vector<vector<int>> table(s1l+1,vector<int>(s2l+1,0));
        for(int i=0;i<s1l;i++)
            for(int j=0;j<s2l;j++){
                if(str1[i]==str2[j])
                    table[i+1][j+1]=table[i][j]+1;
                else{
                    table[i+1][j+1]=max(table[i+1][j],table[i][j+1]);   
                }
            }
        
        //retraverse matrix
        string result="";
        int i=s1l,j=s2l;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                result+=str1[i-1];
                i--;
                j--;
            }else{
                if(table[i][j-1]>=table[i-1][j]){
                    result+=str2[j-1];
                    j--;
                }else if(table[i][j-1]<table[i-1][j]){
                    result+=str1[i-1];
                    i--;
                }
            }
        }
        while(i>0){
            result+=str1[i-1];
            i--;
        }
        while(j>0){
            result+=str2[j-1];
            j--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
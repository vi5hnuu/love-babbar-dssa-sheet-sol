// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

 

// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4

class Solution {
public:
    int minDistance(string word1, string word2) {
        //step 1 find lcs
        //ans = word1 length-lcs + word2 length -lcs;
        
        int word1L=word1.length();
        int word2L=word2.length();
        int table[word1.length()+1][word2.length()+1];
        for(int row=0;row<=word1L;row++)
            table[row][0]=0;
        for(int col=0;col<=word2L;col++)
            table[0][col]=0;
        
        //LCS
        for(int i=0;i<word1L;i++)
            for(int j=0;j<word2L;j++){
                if(word1[i]==word2[j])
                    table[i+1][j+1]=1+table[i][j];
                else
                    table[i+1][j+1]=max(table[i][j+1],table[i+1][j]);
            }
        return (word1L-table[word1L][word2L])+(word2L-table[word1L][word2L]);
    }
};
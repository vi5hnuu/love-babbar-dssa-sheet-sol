/*
Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.
 

Example 1:

Input: board = {{a,g,b,c},{q,e,e,l},{g,b,k,s}},
word = "geeks"
Output: 1
Explanation: The board is-
a g b c
q e e l
g b k s
The letters which are used to make the
"geeks" are colored.
Example 2:

Input: board = {{a,b,c,e},{s,f,c,s},{a,d,e,e}},
word = "sabfs"
Output: 0
Explanation: The board is-
a b c e
s f c s
a d e e
Same letter can not be used twice hence ans is 0
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isWordExist() which takes board and word as input parameter and returns boolean value true if word can be found otherwise returns false.
 

Expected Time Complexity: O(N * M * 4L) where N = No. of rows in board, M = No. of columns in board, L = Length of word
Expected Space Compelxity: O(L), L is length of word.
 

Constraints:
1 ≤ N, M ≤ 100
1 ≤ L ≤ N*M
*/


class Solution {
private:
    bool dfs(int i,int j,string &word,vector<vector<char>> &board,int &r,int &c,int idx){
        if(idx>=word.length()){
            return true;
        }
        if(i<0 || j<0 || i>=r || j>=c || word[idx]!=board[i][j] || board[i][j]=='/'){
            return false;
        }
        char state=board[i][j];
        board[i][j]='/';
        bool ans=dfs(i,j+1,word,board,r,c,idx+1) ||
        dfs(i,j-1,word,board,r,c,idx+1) ||
        dfs(i+1,j,word,board,r,c,idx+1) ||
        dfs(i-1,j,word,board,r,c,idx+1);
        board[i][j]=state;
        return ans;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,word,board,rows,cols,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
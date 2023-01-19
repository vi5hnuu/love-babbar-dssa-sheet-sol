/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

// class Solution {
// private:
//     bool canMakeWord(vector<vector<char>>& board,vector<vector<bool>>& visited,const string &word,int si,int sj,int wi){
//         if(wi==word.length()){
//             return true;
//         }
//         if( si<0 || sj<0 || sj>=board[0].size() || si>=board.size() ||(board[si][sj]!=word[wi]) || visited[si][sj]){
//             return false;
//         }
//         visited[si][sj]=true;
//         bool ans= canMakeWord(board,visited,word,si+1,sj,wi+1) ||
//         canMakeWord(board,visited,word,si-1,sj,wi+1) ||
//         canMakeWord(board,visited,word,si,sj+1,wi+1) ||
//         canMakeWord(board,visited,word,si,sj-1,wi+1);
//         visited[si][sj]=false;
//         return ans;
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int rows=board.size();
//         int cols=board[0].size();

//         vector<vector<bool>> visited(rows,vector<bool>(cols,false));
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(board[i][j]==word[0]){
//                     if(canMakeWord(board,visited,word,i,j,0)){
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };

///////////////
class Solution {
private:
    bool canMakeWord(vector<vector<char>>& board,vector<int>& visited,const string &word,int si,int sj,int wi){
        if(wi==word.length()){
            return true;
        }
        if( si<0 || sj<0 || sj>=board[0].size() || si>=board.size() ||(board[si][sj]!=word[wi]) || (visited[si]&(1<<sj))){
            return false;
        }
        visited[si]=visited[si] | 1<<sj;
        bool ans= canMakeWord(board,visited,word,si+1,sj,wi+1) ||
        canMakeWord(board,visited,word,si-1,sj,wi+1) ||
        canMakeWord(board,visited,word,si,sj+1,wi+1) ||
        canMakeWord(board,visited,word,si,sj-1,wi+1);
        visited[si]=visited[si] & ~(1<<sj);
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();

        //1 <= m, n <= 6
        vector<int> visited(rows,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==word[0]){
                    if(canMakeWord(board,visited,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
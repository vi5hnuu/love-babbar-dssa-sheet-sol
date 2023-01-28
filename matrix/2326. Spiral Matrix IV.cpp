/*
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:


Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>> spiralMatrix(int rows, int cols, ListNode* head) {
//         vector<vector<int>> sp(rows,vector<int>(cols,-1));
//         int row=0;
//         int col=0;
//         while(head){
//             //to right
//             for(int i=col;i<cols-col;i++){
//                 if(!head)
//                     break;
//                 const int value=head->val;
//                 head=head->next;
//                 sp[row][i]=value;
//             }
//             //to bottom
//             for(int j=row+1;j<rows-row;j++){
//                 if(!head)
//                     break;
//                 const int value=head->val;
//                 head=head->next;
//                 sp[j][cols-1-col]=value;
//             }
//             //to left
//             for(int k=cols-2-col;k>=col;k--){
//                 if(!head)
//                     break;
//                 const int value=head->val;
//                 head=head->next;
//                 sp[rows-1-row][k]=value;
//             }
//             //to up
//             for(int l=rows-1-row-1;l>row;l--){
//                 if(!head)
//                     break;
//                 const int value=head->val;
//                 head=head->next;
//                 sp[l][col]=value;
//             }
//             row++;
//             col++;
//         }
//         return sp;
//     }
// };
/////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> spiralMatrix(int rows, int cols, ListNode* head) {
        vector<vector<int>> sp(rows,vector<int>(cols,-1));
        int sc=0;
        int ec=cols-1;
        int sr=0;
        int er=rows-1;
        while(head){
            //to right
            for(int i=sc;i<=ec;i++){
                if(!head){
                    break;
                }
                sp[sr][i]=head->val;
                head=head->next;
            }
            sr++;
            //to bottom
            for(int j=sr;j<=er;j++){
                if(!head){
                    break;
                }
                sp[j][ec]=head->val;
                head=head->next;
            }
            ec--;
            //to left
            for(int k=ec;er!=(sr-1) && k>=sc;k--){
                if(!head){
                    break;
                }
                sp[er][k]=head->val;
                head=head->next;
            }
            er--;
            //to up
            for(int l=er;sc!=(ec+1) && l>=sr;l--){
                if(!head){
                    break;
                }
                sp[l][sc]=head->val;
                head=head->next;
            }
            sc++;
        }
        return sp;
    }
};

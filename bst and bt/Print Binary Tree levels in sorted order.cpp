/*
Given an array arr[] which contains data of N nodes of Complete Binary tree in level order fashion. The task is to print the level order traversal in sorted order.

Example 1:

Input:
N = 7
arr[] = {7 6 5 4 3 2 1}
Output:
7
5 6
1 2 3 4
Explanation: The formed Binary Tree is:
             7
          /      \
        6         5
      /  \      /   \
     4    3    2     1
Example 2:

Input:
N = 6
arr[] = {5 6 4 9 2 1}
Output:
5
4 6
1 2 9
Explanation: The formed Binary Tree is:
             5
          /     \
        6        4
      /  \      /    
     9    2    1    

Your Task:
You don't need to read input or print anything. Your task is to complete the function binTreeSortedLevels() which takes the array arr[] and its size N as inputs and returns a 2D array where the i-th array denotes the nodes of the i-th level in sorted order.


Expected Time Complexity: O(NlogN).
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 104
*/


class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n){
        if(n==0){
            return {};
        }
        vector <vector <int>> lvlOrder;
        
        int i=0;
        int cCount=1;
        while(i<n){
            vector<int> lvl;
            int lim=cCount+i;
            while(i<lim && i<n){
                lvl.push_back(arr[i]);
                i++;
            }
            sort(lvl.begin(),lvl.end());
            lvlOrder.push_back(lvl);
            cCount=cCount*2;
        }
        return lvlOrder;
    }
};
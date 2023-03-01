/*
Given a Binary Heap of size N in an array arr[]. Write a program to calculate the height of the Heap.

Example 1:

Input: N = 6
arr = {1, 3, 6, 5, 9, 8}
Output: 2
Explaination: The tree is like the following
           (1)
       /   \
    (3)    (6)
    / \     /
  (5) (9) (8)
Example 2:

Input: N = 9
arr = {3, 6, 9, 2, 15, 10, 14, 5, 12}
Output: 3
Explaination: The tree looks like following
               (2)
        /      \
      (3)      (9)
     /  \     /   \
   (5) (15) (10) (14)
   / \
 (6) (12)
Your Task:
You do not need to read input or print anything. Your task is to complete the function heapHeight() which takes the value N and the array arr as input parameters and returns the height of the heap.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 104
1 ≤ arr[i] ≤ 106
*/


class Solution{
public:
    int heapHeight(int N, int arr[]){
        int i=0;
        int height=0;
        while(i<N){
            height++;
            i=2*i+1;
        }
        return height-1;
    }
};

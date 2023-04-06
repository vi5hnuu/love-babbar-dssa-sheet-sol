/*
Given a sorted array arr[] of size N. Find the element that appears only once in the array. All other elements appear exactly twice. 

Example 1:

Input:
N = 11
arr[] = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65}
Output: 4
Explanation: 4 is the only element that 
appears exactly once.
 

Your Task:  
You don't need to read input or print anything. Complete the function findOnce() which takes sorted array and its size as its input parameter and returns the element that appears only once. 


Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 105
-105 <= arr[i] <= 105
*/


class Solution
{
  public:
    int findOnce(int arr[], int n){
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if((mid+1>=n || arr[mid+1]!=arr[mid]) && (mid-1<0 || arr[mid]!=arr[mid-1])){
                return arr[mid];
            }else if((mid+1<n && arr[mid+1]==arr[mid])){
                if((mid-low)%2==0){
                    low=mid+2;
                }else{
                    high=mid-1;
                }
            }else{
                if((high-mid)%2==0){
                    high=mid-2;
                }else{
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};
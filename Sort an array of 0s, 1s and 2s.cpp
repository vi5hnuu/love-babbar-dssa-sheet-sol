/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2
*/


class Solution
{
    public:
    //TLE
    // void sort012(int nums[], int n){
    //     int low=0,mid=0,high=n-1;
    //     while(mid<=high){
    //         switch(nums[mid]){
    //             case 0:swap(nums[low],nums[mid]);low++,mid++;break;
    //             case 1:mid++;break;
    //             case 2:swap(nums[high],nums[mid]);high--;break;
    //         }
    //     }
    // }
     void sort012(int arr[], int n){
       int Z=0,O=0;
       for(int i=0;i<n;i++){
           if(arr[i]==0) Z++;
           else if(arr[i]==1) O++;
       }
       int T=n-Z-O;
       int k=0;
       while(Z){arr[k++]=0;Z--;}
       while(O){arr[k++]=1;O--;}
       while(T){arr[k++]=2;T--;}
    }
    
};
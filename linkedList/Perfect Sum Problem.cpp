/*
Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

Example 1:

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}
Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
             {2, 3, 5}

Your Task:  
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)

Constraints:
1 ≤ N*sum ≤ 106
0<=arr[I]<=106
*/


/*
104 /323
Time Limit Exceeded
*/
// class Solution{
// private:
//     /*
//     2 1
//     1 0
//     */
//     //0<=arr[I]<=106
//     int perfectSumCount(int arr[],int n,int idx,int sum){
//         if(idx>=n){
//             return sum==0;
//         }
//         return perfectSumCount(arr,n,idx+1,sum-arr[idx])+perfectSumCount(arr,n,idx+1,sum);
//     }
// public:
// 	int perfectSum(int arr[], int n, int sum){
// 	    int ans=perfectSumCount(arr,n,0,sum);
// 	    return ans;
// 	}
// };
/////////////////////////
class Solution{
public:
	int perfectSum(int arr[], int n, int sum){
	    vector<vector<int>> dp(sum+1,vector<int>(n,0));
	    
	    dp[0][0]=arr[0]==0 ? 2 : 1;//2 because take it or do not take it -> {},{0}
	    for(int col=1;col<n;col++){//first col
	        if(arr[col]!=0){
	            dp[0][col]=1;//{}
	        }else{
	            dp[0][col]=dp[0][col-1]*2;// {...prev+{0}}+{...prev}
	        }
	    }
	    for(int row=1;row<=sum;row++){//first col
	        if(arr[0]==row) dp[row][0]=1;
	    }
	    
	    for(int r=1;r<=sum;r++){
	        for(int c=1;c<n;c++){
	            if(arr[c]>r){
	                dp[r][c]=dp[r][c-1];
	            }else{
	                dp[r][c]= (dp[r-arr[c]][c-1]+dp[r][c-1])%1000000007;
	            }
	        }
	    }
	    return dp[sum][n-1];
	}
};
/*
10 31
9 7 0 3 9 8 6 5 7 6


9 1
0 0 0 0 0 0 0 0 1
*/
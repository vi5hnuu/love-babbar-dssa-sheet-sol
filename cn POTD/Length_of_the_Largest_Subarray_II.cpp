/*
Problem Statement
You are given ‘N’ integers in the form of an array ‘ARR’. You need to print the length of the longest subarray in which the numbers are present in a continuous sequence.
Note:
This problem is similar to the problem "Length of the Largest Subarray". The only difference is that there can be duplicate elements in this problem.
For Example:
Let ‘ARR’ be: [1, 2, 4]
Then the largest subarray with continuous sequence will be: [1, 2]
So the length will be 2.
Detailed explanation ( Input/output format, Notes, Constraints, Images )
Sample Input 1:
2
6 
3 4 5 1 4 5
4 
1 2 3 4
Sample Output 1:
3
4
Explanation:
For the first test case, ARR’ =[3, 4, 5, 1, 4, 5].  In the given array the largest subarray with continuous elements is [3, 4, 5] of size 3, Hence the answer is 3.

For the second test case, ‘ARR’ = [1, 2, 3, 4]. In the given array the largest subarray with continuous elements is [1, 2, 3, 4] of size 4, Hence the answer is 4.
Sample Input 2:
2
7 
1 2 3 4 5 6 7
2
4 2
Sample Output 2:
7
1

*/
#include <bits/stdc++.h> 
int maxLength(vector<int> &arr){
    int mxC=1;
    int len=arr.size();
    int count=1;
    int i=1;
    while(i<len){
        if(arr[i]-1==arr[i-1]){
            count++;
            // cout<<"-"<<count<<endl;
        }else{
            mxC=max(mxC,count);
            count=1;
        }
        i++;
    }
    mxC=max(mxC,count);
    // cout<<"Over";
    return mxC;
}
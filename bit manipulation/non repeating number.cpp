// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.


// Example 1:

// Input: 
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4 
// Explanation:
// 3 and 4 occur exactly once.

#include<bits/stdc++.h>
using namespace std;


 vector<int> singleNumber(vector<int> nums) 
    {
        int xorr=0;
        for(int x:nums)
            xorr^=x;
            
        int lastSetBit=xorr & ~(xorr-1); //turnoff others except first set bit(from right)
        int firstNum=0;
        int secondNum=0;
        for(int x:nums){
            if((x&lastSetBit)!=0)
                firstNum^=x;
            else
                secondNum^=x;
        }
        if(firstNum>secondNum) return {secondNum,firstNum};
        return {firstNum,secondNum};
    }
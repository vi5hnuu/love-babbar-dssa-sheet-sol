// You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int setBits(int N) {
        int count=0;
        while(N){
            count++;
            N=N & (N-1);
        }
        return count;
    }
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        //find xorr to see diff bits and then count those bits
        int xorr=a^b;
        return setBits(xorr);
    }
};

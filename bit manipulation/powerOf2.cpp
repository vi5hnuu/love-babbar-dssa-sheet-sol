// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){  
        if((n&(n-1))!=0 || n==0)//turn off first set bit
            return false;
        return true;
    }
    //84 -> 1010100 & 1010011 => 1010000
};
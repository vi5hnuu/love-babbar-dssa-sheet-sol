#include<bits/stdc++.h>
using namespace std;

//sol 1
class Solution{
    private:
    int noOfSetBits(int n){
        int count=0;
        while(n!=0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
    public:

    int countSetBits(int n)
    {
        int totalSetBits=0;
        for(int i=1;i<=n;i++)
        totalSetBits+=noOfSetBits(i);
        
        return totalSetBits;
    }
};

//sol2
class Solution{
    private:
    //max power of 2 in range (1,n)
    int maxPowOf2inRangeIndex(int n){
        int x=0;
        while((1<<x)<=n)
            x++;
        return x-1;
    }
    public:
    int countSetBits(int n)
    {
        if(!n)
        return 0;
        int maxpow2Index=maxPowOf2inRangeIndex(n);
        int ttlBits1=(1<<(maxpow2Index-1))*maxpow2Index;
        int restmsbSetbit=n-(1<<maxpow2Index)+1;
        int rest=n-(1<<maxpow2Index);
        int ans=ttlBits1+restmsbSetbit+countSetBits(rest);
        return ans;
    }
};
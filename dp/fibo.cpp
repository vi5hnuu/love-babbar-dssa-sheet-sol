class Solution
{
    public:
    //memoization //top down
    long long findNthFibonacci(int N, long long int dp[])
    {
        if(N==0 || N==1){
            return N;
        }
        return (dp[N-1]!=0 ?  dp[N-1] : dp[N-1]=findNthFibonacci(N-1,dp))+(dp[N-2]!=0 ?  dp[N-2] : dp[N-2]=findNthFibonacci(N-2,dp));
    }

};

//////

class Solution
{
    public:
    //Function to find the nth fibonacci number using bottom-up approach.
    long long findNthFibonacci(int N)
    {
        //tabulation //bottom up
        long long dp[N+1]={0};
            dp[0]=0;
            dp[1]=1;
            for(int i=2;i<=N;i++)
                dp[i]=dp[i-1]+dp[i-2];
            return dp[N];
    }
};
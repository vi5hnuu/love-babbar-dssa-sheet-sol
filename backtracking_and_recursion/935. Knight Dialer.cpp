/*
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:


We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).


Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
Example 3:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
 

Constraints:

1 <= n <= 5000
*/


// class Solution {
// private:
//     int knightDialer(int i,int j,int movesLeft){
//         if(i<0 || j<0 || i>=4 || j>=3 || (i*3+j+1==10 || i*3+j+1==12)){
//             return 0;
//         }
//         if(movesLeft==0){
//             return 1;
//         }
//         int ans=knightDialer(i+1,j+2,movesLeft-1)+
//                knightDialer(i+1,j-2,movesLeft-1)+
//                knightDialer(i-1,j+2,movesLeft-1)+
//                knightDialer(i-1,j-2,movesLeft-1)+
//                knightDialer(i-2,j+1,movesLeft-1)+
//                knightDialer(i-2,j-1,movesLeft-1)+
//                knightDialer(i+2,j+1,movesLeft-1)+
//                knightDialer(i+2,j-1,movesLeft-1);
//         ans%=1000000007;
//         return ans;
//     }
// public:
//     int knightDialer(int n) {
//         //1 <= n <= 5000

//         int count=0;
//         for(int i=0;i<4;i++){
//             for(int j=0;j<3;j++){
//                 if(!(i*3+j+1==10 || i*3+j+1==12)){
//                     count=(count%1000000007+knightDialer(i,j,n-1))%1000000007;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
private:
    long long knightDialer(int i,int j,int movesLeft,vector<vector<int>> &memo){
        if(i<0 || j<0 || i>=4 || j>=3 || (i*3+j+1==10 || i*3+j+1==12)){
            return 0;
        }
        if(movesLeft==0){
            return 1;
        }
        if(memo[i*3+j+1][movesLeft]!=-1){
            return memo[i*3+j+1][movesLeft];
        }
        long long ans=knightDialer(i+1,j+2,movesLeft-1,memo)%1000000007+
                knightDialer(i+1,j-2,movesLeft-1,memo)%1000000007+
                knightDialer(i-1,j+2,movesLeft-1,memo)%1000000007+
                knightDialer(i-1,j-2,movesLeft-1,memo)%1000000007+
                knightDialer(i-2,j+1,movesLeft-1,memo)%1000000007+
                knightDialer(i-2,j-1,movesLeft-1,memo)%1000000007+
                knightDialer(i+2,j+1,movesLeft-1,memo)%1000000007+
                knightDialer(i+2,j-1,movesLeft-1,memo)%1000000007;
        ans%=1000000007;
        return memo[i*3+j+1][movesLeft]=ans;
    }
public:
    int knightDialer(int n) {
        //1 <= n <= 5000
        //1 to 12 digits+1 , [,,n+1)
        vector<vector<int>> memo(13,vector<int>(n+1,-1));//at i*cols+j+1 with movesleft
        int count=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(!(i*3+j+1==10 || i*3+j+1==12)){//condition not necessary
                    count=(count%1000000007+knightDialer(i,j,n-1,memo))%1000000007;
                }
            }
        }
        return count;
    }
};

/*
00 01  02
10 11  12
20 21  22
30 31  32

    ||
    \/
i*cols+col
1 2 3
4 5 6
7 8 9
* 0 #
*/
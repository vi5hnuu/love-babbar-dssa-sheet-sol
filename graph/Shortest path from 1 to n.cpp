/*
Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3 * i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.


Example 1:

Input:
N = 9
Output:
2
Explanation:
9 -> 3 -> 1, so
number of steps are 2. 
â€‹Example 2:

Input:
N = 4
Output:
2
Explanation:
4 -> 3 -> 1, so
number of steps are 2.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumStep() which takes the N as inputs and returns the answer.


Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 105
*/


//TLE
// class Solution{
// private:
//     int dfs(int n){
//         if(n<=0){
//             return INT_MAX;
//         }
//         if(n==1){
//             return 0;
//         }
        
//         int way1=dfs(n-1);//...useless
//         int way2=(n%3!=0 ? INT_MAX : dfs(n/3));
//         int mn=min(way1,way2);
//         return (mn==INT_MAX ? INT_MAX : mn+1);
//     }
// public:
//     int minimumStep(int n){
//         int minSteps=dfs(n);
//         return minSteps==INT_MAX ? -1 : minSteps;
//     }
// };

//TLE
// class Solution{
// private:
//     int dfs(int n,map<int,int> &memo){
//         if(n<=0){
//             return INT_MAX;
//         }
//         if(n==1){
//             return 0;
//         }
//         if(memo[n]>0){
//             return memo[n];
//         }
//         int way1=dfs(n-1,memo);//...useless
//         int way2=(n%3!=0 ? INT_MAX : dfs(n/3,memo));
//         int mn=min(way1,way2);
//         return memo[n]=(mn==INT_MAX ? INT_MAX : mn+1);
//     }
// public:
//     int minimumStep(int n){
//         map<int,int> memo;
//         int minSteps=dfs(n,memo);
//         return minSteps==INT_MAX ? -1 : minSteps;
//     }
// };

class Solution{
private:
    int dfs(int n,map<int,int> &memo){
        if(n<=0){
            return INT_MAX;
        }
        if(n==1){
            return 0;
        }
        if(memo[n]>0){
            return memo[n];
        }
        int ways=(n%3!=0 ? dfs(n-1,memo) : dfs(n/3,memo));//we divide /3 if possible else -1
        return memo[n]=(ways==INT_MAX ? INT_MAX : ways+1);
    }
public:
    int minimumStep(int n){
        map<int,int> memo;
        int minSteps=dfs(n,memo);
        return minSteps==INT_MAX ? -1 : minSteps;
    }
};
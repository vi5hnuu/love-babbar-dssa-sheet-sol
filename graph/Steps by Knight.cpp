/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:

Explanation:

Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
 

 

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the initial position of Knight (KnightPos), the target position of Knight (TargetPos), and the size of the chessboard (N) as input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position or return -1 if its not possible.

 

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

 

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
*/


//this approach can never work as there will be a loop always......
//also dfs is waste of resources here............
// class Solution {
// private:
//     int getMin(initializer_list<int> nums){
//         int mn=INT_MAX;
//         for(int n:nums){
//             mn=min(mn,n);
//         }
//         return mn;
//     }
//     int minStepToReachTarget(vector<int>&targetPos,int N,int i,int j){
// 	    if(i<=0 || j<=0 || i>N || j>N){
// 	        return INT_MAX;
// 	    }
// 	    if(i==targetPos[0] && j==targetPos[1]){
// 	        return 1;
// 	    } 
// 	    int a=minStepToReachTarget(targetPos,N,i+1,j+2);
// 	    int b=minStepToReachTarget(targetPos,N,i+1,j-2);
// 	    int c=minStepToReachTarget(targetPos,N,i-1,j+2);
// 	    int d=minStepToReachTarget(targetPos,N,i-1,j-2);
// 	    int e=minStepToReachTarget(targetPos,N,i+2,j+1);
// 	    int f=minStepToReachTarget(targetPos,N,i+2,j-1);
// 	    int g=minStepToReachTarget(targetPos,N,i-2,j+1);
// 	    int h=minStepToReachTarget(targetPos,N,i-2,j-1);
// 	    int mn=getMin({a,b,c,d,e,f,g,h});
// 	    return mn==INT_MAX ? INT_MAX : mn+1;
// 	}
// public:
//     //Function to find out minimum steps Knight needs to reach target position.
// 	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
// 	    int ans=minStepToReachTarget(TargetPos,N,KnightPos[0],KnightPos[1]);
// 	    return ans==INT_MAX ? -1 : ans;
// 	}
// };
///////////////////////
/*
wont work because position x,y in map is dependent on from which direction knight reached x,y 
class Solution {
private:
    int getMin(initializer_list<int> nums){
        int mn=INT_MAX;
        for(int n:nums){
            mn=min(mn,n);
        }
        return mn;
    }
    int minStepToReachTarget(vector<int> &targetPos,int N,int i,int j,vector<vector<bool>> &visited,unordered_map<int,int> &mp){
	    if(i<=0 || j<=0 || i>N || j>N || visited[i][j]){
	        return INT_MAX;
	    }
	    if(i==targetPos[0] && j==targetPos[1]){
	        return 1;
	    }
	    if(mp[i*N+j]>0){
	        return mp[i*N+j];
	    }
	    visited[i][j]=true;
	    int a=minStepToReachTarget(targetPos,N,i+1,j+2,visited,mp);
	    int b=minStepToReachTarget(targetPos,N,i+1,j-2,visited,mp);
	    int c=minStepToReachTarget(targetPos,N,i-1,j+2,visited,mp);
	    int d=minStepToReachTarget(targetPos,N,i-1,j-2,visited,mp);
	    int e=minStepToReachTarget(targetPos,N,i+2,j+1,visited,mp);
	    int f=minStepToReachTarget(targetPos,N,i+2,j-1,visited,mp);
	    int g=minStepToReachTarget(targetPos,N,i-2,j+1,visited,mp);
	    int h=minStepToReachTarget(targetPos,N,i-2,j-1,visited,mp);
	    int mn=getMin({a,b,c,d,e,f,g,h});
	    visited[i][j]=false;
	    return mp[i*N+j]=(mn==INT_MAX ? INT_MAX : mn+1);
	}
public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));
	    unordered_map<int,int> mp;
	    int ans=minStepToReachTarget(TargetPos,N,KnightPos[0],KnightPos[1],visited,mp);
	    return ans==INT_MAX ? -1 : ans;
	}
};
*/
////////////////////////////////////
class Solution {
public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	    if(KnightPos==TargetPos){
	            return 0;
	    }
	    queue<pair<int,int>> knights;
	    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));
	    visited[KnightPos[0]][KnightPos[1]]=true;
	    knights.push({KnightPos[0],KnightPos[1]});
	    
	    int level=0;//jumps
	    while(!knights.empty()){
	        int x[8]={1,1,-1,-1,-2,-2,2,2};
	        int y[8]={2,-2,2,-2,1,-1,1,-1};
	        int sz=knights.size();
	        
	        while(sz>0){
	            sz--;
	            pair<int,int> knight=knights.front();
	            knights.pop();
	            for(int i=0;i<8;i++){
    	            int pi=knight.first+x[i];
    	            int pj=knight.second+y[i];
    	            if(pi>0 && pi<=N && pj>0 && pj<=N && !visited[pi][pj]){
    	                if(pi==TargetPos[0] && pj==TargetPos[1]){
    	                    return level+1;
    	                }
    	                visited[pi][pj]=true;
    	                knights.push({pi,pj});
    	            }
	            }
	        }
            level++;
	    }
	    return -1;
	}
};
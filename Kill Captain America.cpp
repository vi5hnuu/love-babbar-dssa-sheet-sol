/*
Captain America is hiding from Thanos in a maze full of N rooms connected by M gates.
The maze is designed in such a way that each room leads to another room via gates. All connecting gates are unidirectional. Captain America is hiding only in those rooms which are accessible directly/indirectly through every other room in the maze.
Help Thanos find the number of rooms in which Captain America can hide. 

 

Example 1:

Input:
N = 5 and M = 5
V = [[1, 2], [2, 3], [3, 4], [4, 3], [5, 4]]
Output: 2
Explanation:

We can look closesly after forming graph 
than captain america only can hide in a 
room 3 and 4 because they are the only room 
which have gates through them. So,
answer is 2.

Example 2:

Input:
N = 2, M = 1
V = [[1, 2]]
Output: 1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function captainAmerica() which takes the integer N, an integer M and 2-d array V as input parameters and returns the Total no of rooms.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N+M)

 

Constraints:
1 ≤ n ≤ 30000
1 ≤ m ≤ 200000
1 ≤ p,q ≤ n
*/


class Solution{
private:
    int dfsCount(int u,vector<vector<int>> &adj,vector<bool> &visited){
        visited[u]=true;
        int c=1;
        for(int v:adj[u]){
            if(!visited[v]){
                c+=dfsCount(v,adj,visited);
            }
        }
        return c;
    }
public:
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        //1. remove nodes that do not participate in cycle
        vector<vector<int>> adj(N);
        vector<int> outdegree(N,0);
        for(int i=0;i<V.size()-1;i++){
            int u=V[i][0]-1;
            int v=V[i][1]-1;
            adj[v].push_back(u);//transpose
            outdegree[u]++;
        }
        int terminalCount=0;
        for(int i=0;i<N;i++){
            if(outdegree[i]==0){
                terminalCount++;
            }
        }
        if(terminalCount){//when we select any node in graph we cannot reach that node via these terminal nodes
            return terminalCount==1;
        }
        
        //count cycle lengths
        vector<bool> visited(N,false);
        int nodeCount=0;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                int count=dfsCount(i,adj,visited);
                if(count>1){//
                    nodeCount+=count;
                }
            }
        }
        return nodeCount;
    } 
};
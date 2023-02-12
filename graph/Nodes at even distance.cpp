/*
Given a connected acyclic graph with n nodes and n-1 edges, count the pair of nodes that are at even distance(number of edges) from each other.


Example 1:

Input:
n = 3
graph = {{}, {2}, {1, 3}, {2}}
Output: 1
Explaination: Here there are three pairs {1,2},{1,3}
and {2,3} and only {1,3} has even distance between them.
i.e           1
             /
            2
           /
          3

Example 2:

Input:
n = 5
graph = {{}, {2,4}, {1,3}, {2}, {1,5}, {4}}
Output: 4
Explaination: There are four pairs {1,3},{1,5},{2,4}
and {3,5} which has even distance.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countOfNodes() which takes the array graph[] (given as Adjacency list) and its size n as input parameters and returns the count of pair of nodes that are at even distance from each other


Expected Time Complexity: O(V+E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ n ≤ 104
*/


class Solution{
public:
    int countOfNodes(vector<int> graph[], int n){
        //even even,odd odd level
        vector<bool> visited(n+1,false);
        
        queue<int> nodes;
        nodes.push(1);
        visited[1]=true;
        
        vector<int> EOCount(2);
        bool even=0;
        while(!nodes.empty()){
            int sz=nodes.size();
            EOCount[even]+=sz;
            even=!even;
            while(sz>0){
                sz--;
                 int u=nodes.front();
                nodes.pop();
                for(int v:graph[u]){
                    if(!visited[v]){
                        visited[v]=true;
                        nodes.push(v);
                    }
                }
            }
        }
        
        return EOCount[0]*(EOCount[0]-1)/2+EOCount[1]*(EOCount[1]-1)/2;
    }
};
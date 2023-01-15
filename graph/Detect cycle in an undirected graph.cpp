/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
Example 2:

Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 

No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)


 

Constraints:
1 ≤ V, E ≤ 105
*/

class Solution {
    bool modifiedBfs(int s,vector<int> adj[],bool visited[]){
        visited[s]=true;
        queue<int> nodes;
        nodes.push(s);
        queue<int> parents;
        parents.push(-1);
        
        while(!nodes.empty()){
            int node=nodes.front();
            nodes.pop();
            int par=parents.front();
            parents.pop();
            for(const int &x:adj[node]){
                if(!visited[x]){
                  nodes.push(x);
                  parents.push(node);
                  visited[x]=true;
                }else if(x!=par){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V]={false};
        for(int i=0;i<V;i++){//if grph is not connected [a forest is given]
            if(!visited[i]){
                if(modifiedBfs(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

/*
class Solution {
    bool modifiedDfs(int s,vector<int> adj[],bool visited[],int parent){
        visited[s]=true;
        for(const int &child:adj[s]){
            if(!visited[child]){
              if(modifiedDfs(child,adj,visited,s)){
                    return true;
                }  
            }
            else if(child!=parent)
                return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V]={false};
        for(int i=0;i<V;i++){//if grph is not connected [a forest is given]
            if(!visited[i]){
                if(modifiedDfs(i,adj,visited,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};
*/
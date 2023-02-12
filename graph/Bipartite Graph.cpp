/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105
*/


class Solution {
private:
    bool colorGraphDfs(int source,vector<int> *adj,vector<char> &visited,char color){
        visited[source]=color;
        for(int neighbour:adj[source]){
            if(visited[neighbour]=='X'){
                if(!colorGraphDfs(neighbour,adj,visited,(color=='R' ? 'G':'R'))){
                    return false;
                }
            }else{
                if(visited[neighbour]==visited[source]){
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<char> visited(V,'X');//color->R,G
	    for(int i=0;i<V;i++){
	        if(visited[i]=='X'){
	            if(!colorGraphDfs(i,adj,visited,'R')){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};
////////////////////

// class Solution {
// private:
//     bool colorBfs(int source,vector<int>adj[],vector<char> &visited){
//         queue<int> nodes;
// 	    nodes.push(source);
// 	    visited[source]='R';
	    
// 	    char nxtLvlColor='G';
	    
// 	    while(!nodes.empty()){
// 	        int sz=nodes.size();
// 	        while(sz>0){
// 	            sz--;
// 	            int node=nodes.front();
// 	            nodes.pop();
	            
// 	            for(int neighbour:adj[node]){
// 	                if(visited[neighbour]=='X'){
// 	                    visited[neighbour]=nxtLvlColor;
// 	                    nodes.push(neighbour);
// 	                }else if(visited[node]==visited[neighbour]){
// 	                    return false;
// 	                }
// 	            }
// 	        }
// 	        nxtLvlColor=nxtLvlColor=='G' ? 'R' : 'G';
// 	    }
// 	    return true;
//     }
// public:
// 	bool isBipartite(int V, vector<int>adj[]){
	    
// 	    vector<char> visited(V,'X');//color->R,G
// 	    for(int i=0;i<V;i++){
// 	        if(visited[i]=='X'){
// 	            if(!colorBfs(i,adj,visited)){
// 	                return false;
// 	            }
// 	        }
// 	    }
// 	    return true;
// 	}
// };
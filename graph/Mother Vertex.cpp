/*
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
 

Example 1:

Input: 

Output: 0
Explanation: According to the given edges, all 
nodes can be reaced from nodes from 0, 1 and 2. 
But, since 0 is minimum among 0,1 and 3, so 0 
is the output.
Example 2:

Input: 

Output: -1
Explanation: According to the given edges, 
no vertices are there from where we can 
reach all vertices. So, output is -1.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findMotherVertex() which takes V denoting the number of vertices and adjacency list as imput parameter and returns the verticex from through which we can traverse all other vertices of the graph. If there is more than one possible nodes then returns the node with minimum value.If not possible returns -1.
 

Expected Time Complexity: O(V + E)
Expected Space Compelxity: O(V)
 

Constraints:
1 ≤ V ≤ 500
*/


//TLE 19/1218
// class Solution {
// private:
//     int isMother(int source,vector<int> *adj,vector<bool> &visited){
//         visited[source]=true;
//         int count=0;
//         for(int neighbour:adj[source]){
// 	        if(!visited[neighbour]){
// 	            count+=isMother(neighbour,adj,visited);
// 	        }
// 	    }
// 	    visited[source]=false;
// 	    return count+1;
//     }
// public:
//     //Function to find a Mother Vertex in the Graph.
// 	int findMotherVertex(int V, vector<int>adj[]){
	    
// 	    vector<bool> visited(V,false);
// 	    for(int i=0;i<V;i++){
// 	        int countVisisted=isMother(i,adj,visited);
// 	        if(countVisisted==V){
// 	            return i;
// 	        }
// 	    }
// 	    return -1;
// 	}
// };
//////////////////////////////////////
// class Solution {
// private:
//     int topodfs(int source,vector<int> *adj,vector<bool> &visited,stack<int> &stck){
//         visited[source]=true;
//         for(int neighbour:adj[source]){
// 	        if(!visited[neighbour]){
//                 topodfs(neighbour,adj,visited,stck);
// 	        }
// 	    }
// 	    stck.push(source);
//     }
//     int dfsCount(int source,vector<int> *adj,vector<bool> &visited){
//         visited[source]=false;
//         int count=0;
//         for(int neighbour:adj[source]){
// 	        if(visited[neighbour]){
//                 count+=dfsCount(neighbour,adj,visited);
// 	        }
// 	    }
// 	    return 1+count;
//     }
// public:
//     //Function to find a Mother Vertex in the Graph.
// 	int findMotherVertex(int V, vector<int>adj[]){
	    
// 	    vector<bool> visited(V,false);
// 	    stack<int> stck;
// 	    for(int i=0;i<V;i++){
// 	        if(!visited[i]){
//                 topodfs(i,adj,visited,stck);  
// 	        }
// 	    }
// 	    int countVis=dfsCount(stck.top(),adj,visited);
// 	    return countVis==V ? stck.top() : -1;
// 	}
// };
/////////////////////////////////
/*
if there is no cycle finding mother vertext is very easy just store the indegrees.
if there is more than two node with indegree=0 -> return -1;
else we check the one and only one node with indegree zero is mother or not
and i think we dont have to we can simple return..one and only one node with indegree zero
*/
class Solution {
private:
    int topodfs(int source,vector<int> *adj,vector<bool> &visited,int &mother){
        visited[source]=true;
        for(int neighbour:adj[source]){
	        if(!visited[neighbour]){
                topodfs(neighbour,adj,visited,mother);
	        }
	    }
	    mother=source;
    }
    int dfsCount(int source,vector<int> *adj,vector<bool> &visited){
        visited[source]=false;
        int count=0;
        for(int neighbour:adj[source]){
	        if(visited[neighbour]){
                count+=dfsCount(neighbour,adj,visited);
	        }
	    }
	    return 1+count;
    }
public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[]){
	    
	    vector<bool> visited(V,false);
	    int mother=0;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
                topodfs(i,adj,visited,mother);  
	        }
	    }
	    int countVis=dfsCount(mother,adj,visited);
	    return countVis==V ? mother : -1;
	}
};
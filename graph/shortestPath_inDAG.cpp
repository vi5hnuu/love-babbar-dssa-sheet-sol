// we can use dijkstra algo(BFS) or bellmanford  they have more cmoplexity than toplogical sort alog O(V+E)

// now whats the connection of topological sort with finding meminum distance of all vertices from source to dest in directed acyclic weighted graph.

// now watch closely in toposort we create a logical dependency path [from no dependency to max dependency] and in DAG no cycle so we can say the hortest path of y in [x,y] topo is parent path+my weight.

// also remember a vertex can come as adj of many vertex so update path accordingly

// eg:
//  0-w1>1-w3>2-w4>3
//     |w2
//     3
// source=1

// dist[]=[INF,0,INF,INF]

// one of topo => 0 1 2 3
// we dont update path of 3 second time*

class Solution
{
    private:
    vector<int> getIndegree(int v,vector<int> adj[]){
        vector<int> indegrees(v,0);
        for(int i=0;i<v;i++){
            for(int j=0,cols=adj[i].size();j<cols;j++){
                indegrees[adj[i][j]]++;
            }
        }
        return indegrees;
    }
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> res;
	    vector<int> indegrees=getIndegree(V,adj);
	    queue<int> nodes;
	    for(int i=0;i<V;i++){
	        if(indegrees[i]==0){
	            nodes.push(i);
	        }
	    }
	    while(!nodes.empty()){
	        int node=nodes.front();
	        nodes.pop();
	        res.push_back(node);
	        for(const int &child:adj[node]){
	                indegrees[child]--;
    	            if(indegrees[child]==0){
    	               nodes.push(child);
    	            }
	        }
	    }
	    return res;
	}
	public:
     void findShortestPathInDAG(int src,vector<int> adj[],const vector<int> weight){
        vector<int> distances(V, INT_MAX);
        vector<int> topSortOrdering = topoSort(src);
        distances[src]=0;
        for(int x:topSortOrdering){
            if(distances[x]!=INT_MAX){
                for(const int &neighbour:adj[x]){
                    if(distances[neighbour] > distances[x]+weight[x]){
                        distances[neighbour] = distances[x]+weight[x];
                    }
                }   
            }
        }
        cout<<"The distances from the src node are: ";
        for(int i=0;i<V;++i){
            if(distances[i]==INT_MAX) cout<<"INF ";
            else cout<<distances[i]<<" ";
        }
    }

    
};
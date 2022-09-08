vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //Kahn's algorithm //bfs based
	    //add to queue whose dependency is zero(indegree)
	    queue<int> q;
	    //find indegree
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto neighbour:adj[i]){
	            indegree[neighbour]++;
	        }
	    }
	    ///////Given a Directed Acyclic Graph (DAG) with V vertices and E edges(atleast one vertex has zero indegree)
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    //
	    vector<int> topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto neighbour:adj[node]){
	            indegree[neighbour]--;
	            if(indegree[neighbour]==0)
	                q.push(neighbour);
	        }
	    }
	    return topo;
	}

    
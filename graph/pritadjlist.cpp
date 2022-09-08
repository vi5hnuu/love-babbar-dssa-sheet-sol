  vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        vector<vector<int>> adjj;
        for(int i=0;i<V;i++){
            vector<int> tmp;
            tmp.push_back(i);
            for(const int &x: adj[i])
                tmp.push_back(x);
            adjj.push_back(tmp);
        }
        return adjj;
    }

    // Given the adjacency list of a bidirectional graph. Your task is to copy/clone the adjacency list for each vertex and return a new list.

// 0-> 1-> 4 
// 1-> 0-> 2-> 3-> 4 
// 2-> 1-> 3 
// 3-> 1-> 2-> 4 
// 4-> 0-> 1-> 3
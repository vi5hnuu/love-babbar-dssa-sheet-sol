// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

// Output: 0 1 2 3 4
// Explanation: 
// 0 is connected to 1 , 2 , 3.
// 2 is connected to 4.
// so starting from 0, it will go to 1 then 2
// then 3.After this 2 to 4, thus bfs will be
// 0 1 2 3 4.

// vector<int> bfsOfGraph(int V, vector<int> adj[]) {
//         bool visited[V]={false};
//         queue<int> nodes;
//         nodes.push(0);
//         vector<int> res;
//         while(!nodes.empty()){
//             int sz=nodes.size();
//             while(sz>0){
//                 sz--;
//                 int node=nodes.front();
//                 nodes.pop();
//                 if(!visited[node]){
//                     res.push_back(node);
//                     visited[node]=true;
//                 }
                    
//                 for(const int &x:adj[node]){
//                     if(!visited[x])
//                         nodes.push(x);
//                 }
//             }
//         }
//         return res;
//     }

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        bool visited[V]={false};
        queue<int> nodes;
        nodes.push(0);
        vector<int> res;
        while(!nodes.empty()){
            int sz=nodes.size();
            while(sz>0){
                sz--;
                int node=nodes.front();
                nodes.pop();
                if(!visited[node]){
                    res.push_back(node);
                    visited[node]=true;
                    
                    for(const int &x:adj[node]){
                    if(!visited[x])
                        nodes.push(x);
                    }
                }
                    
                
            }
        }
        return res;
    }
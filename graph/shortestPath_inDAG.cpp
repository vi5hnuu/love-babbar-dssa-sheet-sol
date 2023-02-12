// we can use dijkstra algo(BFS) or bellmanford  they have more cmoplexity than toplogical sort alog O(V+E)

// now whats the connection of topological sort with finding meminum distance of all vertices from source to dest in directed acyclic weighted graph.

// now watch closely in toposort we create a logical dependency path [from no dependency to max dependency] and in DAG no cycle so we can say the shortest path of y in [x,y] topo is parent path+my weight.

// also remember a vertex can come as adj of many vertex so update path accordingly

// eg:
//  0-w1>1-w3>2-w4>3
//     |w2
//     3
// source=1

// dist[]=[INF,0,INF,INF]

// one of topo => 0 1 2 3
// we dont update path of 3 second time*


class Solution{
	public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(auto &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});//u->{v,w}
        }
        vector<int> dis(N, INT_MAX);
        queue<int> q;
        int src = 0;
        q.push(src);
        dis[src] = 0;
        
        //BFS
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto it:adj[u]){
                int v = it.first;
                int weightuv = it.second;
                if(dis[v]>dis[u] + weightuv)
                    dis[v]=dis[u] + weightuv;
                q.push(v);
            }
        }
        
        for(int i = 0; i < dis.size(); i++){
            if(dis[i] == INT_MAX)
            dis[i] = -1;
        }
        return dis;
    }
};

/////////////
/*
do a dry run to understand this better...there are repetiition in queue
*/
// class Solution{
// 	public:
//      vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
//         vector<pair<int,int>> adj[N];
//         for(auto &edge:edges){
//             adj[edge[0]].push_back({edge[1],edge[2]});//u->{v,w}
//         }
//         vector<int> dis(N, INT_MAX);
//         queue<int> q;
//         int src = 0;
//         q.push(src);
//         dis[src] = 0;
        
//         //BFS
//         while(!q.empty()){
//             int u = q.front();
//             q.pop();
            
//             for(auto it:adj[u]){
//                 int v = it.first;
//                 int weightuv = it.second;
//                 if(dis[v]>dis[u] + weightuv)
//                     dis[v]=dis[u] + weightuv;
//                 q.push(v);
//             }
//         }
        
//         for(int i = 0; i < dis.size(); i++){
//             if(dis[i] == INT_MAX)
//             dis[i] = -1;
//         }
//         return dis;
//     }
// };
//understand the singificance of toposort...

class Solution{
private:
    vector<int> topoBfs(vector<pair<int,int>> *adj,int V){
        vector<int> ind(V,0);
        for(int i=0;i<V;i++){
            for(auto &ad:adj[i]){
                ind[ad.first]++;
            }
        }
        queue<int> nodes;
        for(int i=0;i<V;i++){
            if(ind[i]==0){
                nodes.push(i);
            }
        }
        
        vector<int> topoOrder;
        while(!nodes.empty()){
            int node=nodes.front();
            nodes.pop();
            topoOrder.push_back(node);
            for(auto &neigh:adj[node]){
                ind[neigh.first]--;
                if(ind[neigh.first]==0){
                    nodes.push(neigh.first);
                }
            }
        }
        return topoOrder;
    }
public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(auto &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});//u->{v,w}
        }
        vector<int> topoOrder=topoBfs(adj,N);
        vector<int> dis(N, INT_MAX);
        dis[0]=0;
        
        int i=0;
        while(i<N){
            for(auto &neigh:adj[topoOrder[i]]){
                int wuv=neigh.second;
                int u=topoOrder[i];
                int v=neigh.first;
                if(dis[u]!=INT_MAX && dis[v]>dis[u]+wuv){
                    dis[v]=dis[u]+wuv;
                }
            }
            i++;
        }
        
        for(int i=0;i<N;i++){
            if(dis[i]==INT_MAX){
                dis[i]=-1;
            }
        }
        return dis;
    }
};
//////////////////
class Solution{
private:
    vector<int> topoBfs(vector<pair<int,int>> *adj,int V){
        vector<int> ind(V,0);
        for(int i=0;i<V;i++){
            for(auto &ad:adj[i]){
                ind[ad.first]++;
            }
        }
        queue<int> nodes;
        for(int i=0;i<V;i++){
            if(ind[i]==0){
                nodes.push(i);
            }
        }
        
        vector<int> topoOrder;
        while(!nodes.empty()){
            int node=nodes.front();
            nodes.pop();
            topoOrder.push_back(node);
            for(auto &neigh:adj[node]){
                ind[neigh.first]--;
                if(ind[neigh.first]==0){
                    nodes.push(neigh.first);
                }
            }
        }
        return topoOrder;
    }
public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        for(auto &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});//u->{v,w}
        }
        vector<int> topoOrder=topoBfs(adj,N);
        vector<int> dis(N, INT_MAX);
        dis[0]=0;
        
        int i=0;
        while(i<N){
            int u=topoOrder[i];
            if(dis[u]==INT_MAX){
                i++;
                continue;
            }
            //"u"<-node said i am going out of graph and i am relaxing my neighbours
            
            for(auto &neigh:adj[topoOrder[i]]){
                int wuv=neigh.second;
                int v=neigh.first;
                if(dis[v]>dis[u]+wuv){
                    dis[v]=dis[u]+wuv;
                }
            }
            i++;
        }
        
        for(int i=0;i<N;i++){
            if(dis[i]==INT_MAX){
                dis[i]=-1;
            }
        }
        return dis;
    }
};

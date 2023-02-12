class Solution {
    private:
    vector<vector<int>> ShortestdistOfEachnodeFromSourceBFS(int source,int V, vector<int> adj[]) {
        bool visited[V]={false};
        queue<int> nodes;
        nodes.push(source);
        visited[source]=true;
        vector<vector<int>> res(V,{0,0});
        while(!nodes.empty()){
                int node=nodes.front();
                nodes.pop();
                for(const int &x:adj[node]){
                    if(!visited[x]){
                      nodes.push(x);
                      res[x][0]=x;
                      res[x][1]=res[node][1]+1;
                      visited[x]=true;
                    }
            }
        }
        return res;
    }
  public:
    void abc(int V, vector<int> adj[]) {//adj list
        for(const auto &x:ShortestdistOfEachnodeFromSourceBFS(0,V,adj))
            cout<<"distance of node "<<x[0]<<" from "<<0<<" is "<<x[1]<<endl;
    }
};
/*
in case graph is disconnected we need bfs for nonvisited and dist is infinity
*/
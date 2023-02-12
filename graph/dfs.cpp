// Given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..


// Output: 0 1 2 4 3
// Explanation: 
// 0 is connected to 1, 2, 4.
// 1 is connected to 0.
// 2 is connected to 0.
// 3 is connected to 4.
// 4 is connected to 0, 3.
// so starting from 0, it will go to 1 then 2
// then 4, and then from 4 to 3.
// Thus dfs will be 0 1 2 4 3.

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*
class Solution {
  private:
  void dfsOfGraph(int V, vector<int> *&adj,vector<bool> &visited,vector<int> &res,int source) {
        //cout<<visited[source];
        if(!visited[source]){
            res.push_back(source);
            visited[source]=true;
                for(const int &child:adj[source]){
                if(!visited[child])
                dfsOfGraph(V,adj,visited,res,child);
                }
        }
        
  }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<int> res;
        for(int i=0;i<V;i++){//if graph given is disconnected
            if(!visited[i])
            dfsOfGraph(V,adj,visited,res,i);
        }
        return res;
    }
    */
    
//     private:
//   void dfsOfGraph(int V, vector<int> *&adj,vector<bool> &visited,vector<int> &res,int source) {
//         //cout<<visited[source];
//             res.push_back(source);
//             for(const int &child:adj[source]){
//             if(!visited[child]){
//                 visited[child]=true;
//                 dfsOfGraph(V,adj,visited,res,child);
//             }
//         }
        
//   }
//   public:
//     // Function to return a list containing the DFS traversal of the graph.
//     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
//         vector<bool> visited(V,false);
//         vector<int> res;
//         for(int i=0;i<V;i++){
//             if(!visited[i]){
//             visited[i]=true;
//             dfsOfGraph(V,adj,visited,res,i);
//             }
//         }
//         return res;
//     }
// };

/////////////////////////////////////////
/*
eg
    0->1 2
    1->0 3 4
    2->0 3
    3->1 2
    4->1 5
    5->4
*/
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        stack<int> stck;
        vector<bool> visited(V,false);
        stck.push(0);
        visited[0]=true;
        vector<int> res;
        while(!stck.empty()){
            int tp=stck.top();
            stck.pop();
            res.push_back(tp);
            for(int i=adj[tp].size()-1;i>=0;i--){
                //can from zero also but gfg output show we should from end
                //wrong XXXXXXXXXXXXXXXXXXXXXXXXXX knw why ?
                int neighbour=adj[tp][i];
                if(!visited[neighbour]){
                    visited[neighbour]=true; //this shouldn't happen...
                    stck.push(neighbour);
                }
            }
        }
        return res;
    }
};

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        stack<int> stck;
        vector<bool> visited(V,false);
        stck.push(0);
        vector<int> res;
        while(!stck.empty()){
            int tp=stck.top();
            stck.pop();
            
            if(!visited[tp]){
                res.push_back(tp);
                visited[tp]=true;
            }
            for(int i=adj[tp].size()-1;i>=0;i--){
                //can from zero also but gfg output show we should from end
                //CORRECT
                int neighbour=adj[tp][i];
                if(!visited[neighbour]){
                    stck.push(neighbour);
                }
            }
        }
        return res;
    }
};
///////////////////////////////////////////

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  
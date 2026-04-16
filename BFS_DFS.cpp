#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void dfs(int node , vector<int>& res , vector<int>& visited , vector<vector<int>>& adj) {
        visited[node] = 1 ;
        res.push_back(node) ;

        for(auto adjNode : adj[node]) {
            if(!visited[adjNode]) {
                dfs(adjNode , res , visited , adj) ;
            }
        } 
    }

    vector<int> dfsOfGraph(int V , vector<vector<int>> edges) {
        vector<vector<int>> adj(V) ;

        for(auto edge : edges) {
            int u = edge[0] ;
            int v = edge[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        
        vector<int> res ;
        vector<int> visited(V , 0) ;
        
        dfs(0 , res , visited , adj) ;
        
        return res ;
    }
    
    vector<int> bfsOfGraph(int V , vector<vector<int>> edges) {
        vector<vector<int>> adj(V) ;

        for(auto edge : edges) {
            int u = edge[0] ;
            int v = edge[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        queue<int> q ;
        vector<int> visited(V , 0) ;
        vector<int> res ;

        q.push(0) ;
        visited[0] = 1 ;

        while(!q.empty()) {
            int node = q.front() ;
            q.pop() ;
            res.push_back(node) ;

            for(auto adjNode : adj[node]) {
                if(!visited[adjNode]) {
                    q.push(adjNode) ;
                    visited[adjNode] = 1 ;
                }
            }
        }
        
        return res ;
    }
} ;

void solve() {
    int V , E ; 
    cin >> V >> E ;
    
    vector<vector<int>> edges ;
    for(int i = 0 ; i < E ; i++) {
        int u , v ; 
        cin >> u >> v ;
        edges.push_back({u , v}) ;
    }
    
    Solution obj ;
    
    vector<int> dfsResult = obj.dfsOfGraph(V , edges) ;
    cout << "DFS: " ;
    for(auto node : dfsResult) {
        cout << node << ' ' ;
    }
    cout << endl ;
    
    vector<int> bfsResult = obj.bfsOfGraph(V , edges) ;
    cout << "BFS: " ;
    for(auto node : bfsResult) {
        cout << node << ' ' ;
    }
    cout << endl ;
}

int main() {
    freopen("input.txt" , "r+" , stdin) ;
    freopen("output.txt" , "w+" , stdout) ;
    int t = 1 ;
    cin >> t ;

    while(t--) {
        solve() ;
    }

    return 0 ;
}
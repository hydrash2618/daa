#include <bits/stdc++.h>
using namespace std ;

bool isSafe(int node , vector<int>& color , vector<vector<int>>& adj , int c) {
    for(auto adjNode : adj[node]) {
        if(color[adjNode] == c) {
            return false ;
        }
    }
    return true ;
}

bool func(int node , vector<int>& color , int m , int V , vector<vector<int>>& adj) {
    if(node == V) {
        return true ;
    }

    for(int i = 1 ; i <= m ; i++) {
        if(isSafe(node , color , adj , i)) {
            color[node] = i ;
            
            if(func(node + 1 , color , m , V , adj)) {
                return true ;
            }
            
            color[node] = 0 ;
        }
    }
    
    return false ;
}

void solve() {
    int V , E , m ; 
    cin >> V >> E >> m ;

    vector<vector<int>> adj(V) ;
    for(int i = 0 ; i < E ; i++) {
        int u , v ; 
        cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    vector<int> color(V , 0) ;
    
    if(func(0 , color , m , V , adj)) {
        cout << "YES\n" ;
        for(int i = 0 ; i < V ; i++) {
            cout << color[i] << ' ' ;
        }
        cout << endl ;
    } 
    else {
        cout << endl ;
    }
}

int main() {
    int T = 1 ; 
    cin >> T ;

    while(T--) {
        solve() ;
    }

    return 0 ;
}
#include<bits/stdc++.h>
using namespace std ;

// O(V^3)
int BellmanFord(int src , int dest , int V , vector<vector<int>>& edges) {
    vector<int> dist(V , 1e9) ;
    dist[src] = 0 ;
    
    for(int i = 0 ; i < V - 1 ; i++) {
        for(auto edge : edges) {
            int u = edge[0] ;
            int v = edge[1] ;
            int wt = edge[2] ;

            if(dist[u] == 1e9) continue ;

            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt ;
            }
        }
    }

    bool flag = false ;
    for(auto edge : edges) {
        int u = edge[0] ;
        int v = edge[1] ;
        int wt = edge[2] ;

        if(dist[u] == 1e9) continue ;

        if(dist[u] + wt < dist[v]) {
            dist[v] = dist[u] + wt ;
            flag = true ;
        }
    }

    if(flag) {
        cout << "Negative Cycle Detected" << endl ;
    }
    return dist[dest] ;
}

void solve() {
    int V , E ; cin >> V >> E ;
    int src , dest ; cin >> src >> dest ;

    vector<vector<int>> edges ;
    for(int i = 0 ; i < E ; i++) {
        int u , v , wt ; cin >> u >> v >> wt ;
        edges.push_back({u , v , wt}) ;
    }

    cout << BellmanFord(src , dest , V , edges) << endl ;
}

int main() {
    freopen("input.txt" , "r" , stdin) ;
    freopen("output.txt" , "w" , stdout) ;

    int T ; cin >> T ;
    while(T--) {
        solve() ;
    }
    return 0 ;
}
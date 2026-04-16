#include <bits/stdc++.h>
using namespace std ;

// O(E log V)
int dijkstra(int src , int dest , int V , vector<vector<pair<int , int>>>& adj) {
    vector<int> dist(V , 1e9) ;
    dist[src] = 0 ;
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;
    pq.push({0 , src}) ; // { dist , node }

    while(!pq.empty()) {
        auto [currDist , node] = pq.top() ;
        pq.pop() ;

        if(dist[node] < currDist) continue ;

        for(auto [adjNode , adjDist] : adj[node]) {
            if(currDist + adjDist < dist[adjNode]) {
                dist[adjNode] = currDist + adjDist ;
                pq.push({dist[adjNode] , adjNode}) ;
            }
        }
    }

    return dist[dest] ;
}

void solve() {
    int V , E ; cin >> V >> E ;
    int src , dest ;
    cin >> src >> dest ;
    vector<vector<pair<int , int>>> adj(V) ;

    for(int i = 0 ; i < E ; i++) {
        int u , v , wt ;
        cin >> u >> v >> wt ;
        adj[u].push_back({v , wt}) ;
        adj[v].push_back({u , wt}) ;
    }

    cout << dijkstra(src , dest , V , adj) << endl ;
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
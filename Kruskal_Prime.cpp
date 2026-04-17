#include <bits/stdc++.h>
using namespace std ;

class DSU {
    vector<int> parent , rank ;
public:
    DSU(int n) {
        parent.resize(n) ;
        rank.resize(n , 0) ;
        for(int i = 0 ; i < n ; i++) {
            parent[i] = i ;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) {
            return node ;
        }
        return parent[node] = findUPar(parent[node]) ;
    }

    void unionByRank(int u , int v) {
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;
        
        if(ulp_u == ulp_v) return ;
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v ;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u ;
        }
        else {
            parent[ulp_v] = ulp_u ;
            rank[ulp_u]++ ;
        }
    }
} ;

int kruskal(int V , vector<vector<int>>& edges) {
    sort(edges.begin() , edges.end()) ;
    
    DSU dsu(V) ;
    int mstWeight = 0 ;

    for(auto it : edges) {
        int wt = it[0] ;
        int u = it[1] ;
        int v = it[2] ;

        if(dsu.findUPar(u) != dsu.findUPar(v)) {
            mstWeight += wt ;
            dsu.unionByRank(u , v) ;
        }
    }

    return mstWeight ;
}

int prim(int V , vector<vector<pair<int , int>>>& adj) {
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;
    
    vector<int> visited(V , 0) ;
    int mstWeight = 0 ;

    pq.push({0 , 0}) ;

    while(!pq.empty()) {
        auto [wt , node] = pq.top() ;
        pq.pop() ;

        if(visited[node]) continue ;

        visited[node] = 1 ;
        mstWeight += wt ;

        for(auto [adjNode , edgWt] : adj[node]) {
            if(!visited[adjNode]) {
                pq.push({edgWt , adjNode}) ;
            }
        }
    }

    return mstWeight ;
}

void solve() {
    int V , E ; 
    cin >> V >> E ;

    vector<vector<int>> edges ;
    vector<vector<pair<int , int>>> adj(V) ;

    for(int i = 0 ; i < E ; i++) {
        int u , v , wt ; 
        cin >> u >> v >> wt ;
        
        edges.push_back({wt , u , v}) ;
        
        adj[u].push_back({v , wt}) ;
        adj[v].push_back({u , wt}) ;
    }

    int kruskalAns = kruskal(V , edges) ;
    int primAns = prim(V , adj) ;

    cout << "MST Weight using Kruskal's: " << kruskalAns << endl ;
    cout << "MST Weight using Prim's: " << primAns << endl ;
}

int main() {
    int T = 1 ; 
    cin >> T ;

    while(T--) {
        solve() ;
    }

    return 0 ;
}
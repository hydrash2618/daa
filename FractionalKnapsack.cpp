#include <bits/stdc++.h>
using namespace std ;

double fractionalKnapsack(int W , vector<int>& val , vector<int>& wt , int n) {
    vector<int> ind(n) ;
    for(int i = 0 ; i < n ; i++) {
        ind[i] = i ;
    }

    sort(ind.begin() , ind.end() , [&](int i , int j) {
        double r1 = (double)val[i] / (double)wt[i] ;
        double r2 = (double)val[j] / (double)wt[j] ;
        return r1 > r2 ;
    }) ;
    
    double finalvalue = 0.0 ;
    
    for(int i = 0 ; i < n ; i++) {
        int idx = ind[i] ;
        
        if(wt[idx] <= W) {
            W -= wt[idx] ;
            finalvalue += val[idx] ;
        } 
        else {
            finalvalue += val[idx] * ((double)W / (double)wt[idx]) ;
            break ;
        }
    }
    
    return finalvalue ;
}

void solve() {
    int n , W ; 
    cin >> n >> W ;

    vector<int> val(n) ;
    vector<int> wt(n) ;
    
    for(int i = 0 ; i < n ; i++) {
        cin >> val[i] >> wt[i] ;
    }

    cout << fixed << setprecision(2) << fractionalKnapsack(W , val , wt , n) << endl ;
}

int main() {
    int T = 1 ; 
    cin >> T ;

    while(T--) {
        solve() ;
    }

    return 0 ;
}
#include <bits/stdc++.h>
using namespace std ;

// O(n * W)
int func(int ind , int W , vector<int>& wt , vector<int>& val , vector<vector<int>>& dp) {
    if(ind == 0) {
        return 0 ;
    }

    if(dp[ind][W] != -1) return dp[ind][W] ;

    int pick = 0 ;
    if(W - wt[ind - 1] >= 0) {
        pick = val[ind - 1] + func(ind - 1 , W - wt[ind - 1] , wt , val , dp) ;
    }
    int notPick = 0 + func(ind - 1 , W , wt , val , dp) ;

    return dp[ind][W] = max(pick , notPick) ;
}

void solve() {
    int n , w ; cin >> n >> w ;
    vector<int> wt(n) , val(n) ;
    vector<vector<int>> dp(n + 2 , vector<int>(w + 2 , 0)) ;


    for(int i = 0 ; i < n ; i++) {
        cin >> wt[i] ;
    }

    for(int i = 0 ; i < n ; i++) {
        cin >> val[i] ;
    }

    for(int ind = 1 ; ind <= n ; ind++) {
        for(int W = 0 ; W <= w ; W++) {
            int pick = 0 ;
            if(W - wt[ind - 1] >= 0) {
                pick = val[ind - 1] + dp[ind - 1][W - wt[ind - 1]] ;
            }
            int notPick = 0 + dp[ind - 1][W] ;

            dp[ind][W] = max(pick , notPick) ;
        }
    }

    cout << dp[n][w] << endl ;
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
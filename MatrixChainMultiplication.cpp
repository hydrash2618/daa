#include <bits/stdc++.h>
using namespace std ;

/*
    Observations:-

    10 15 20 25
        A  B  C

    1 2 3 4 5 6 7 8 9 10
      i       B     j
*/

int mcm(int i , int j , vector<int>& arr , vector<vector<int>>& dp) {
    if(i >= j) {
        return 0 ;
    }

    if(dp[i][j] != -1) return dp[i][j] ;

    int ops = INT_MAX ;
    for(int k = i ; k < j ; k++) {
        ops = min(ops , (arr[i - 1] * arr[k] * arr[j]) + mcm(i , k , arr , dp) + mcm(k + 1 , j , arr , dp)) ;
    }
    return dp[i][j] = ops ;
}

void solve() {
    int n ; cin >> n ;
    vector<int> arr(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
    }

    vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , -1)) ;

    cout << mcm(1 , n - 1 , arr , dp) << endl ;
}

int main() {
    int T ; cin >> T ;
    while(T--) {
        solve() ;
    }

    return 0 ;
}
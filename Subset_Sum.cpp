#include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
#define MOD (int)(1e9 + 7) ;

/*==============================================================*/
/*
    PROBLEM OBSERVATIONS
   
*/
/*==============================================================*/

void func(int ind , vector<int>& temp , int target , vector<int>& arr ) {
    if(target == 0) {
        cout << "[ " ;
        for(auto it : temp) {
            cout << it << ' ' ;
        }
        cout << "]" << endl ;
        return ;
    }

    if(ind < 0) {
        return ;
    }

    if(target - arr[ind] >= 0) {
        temp.push_back(arr[ind]) ;
        func(ind - 1 , temp , target - arr[ind] , arr) ;
        temp.pop_back() ;
    } 
    func(ind - 1 , temp , target , arr) ;
}

void solve() {
    int n , target ; cin >> n >> target ;
    vector<int> arr(n) ;

    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
    }

    vector<int> temp ;
    func(n - 1 , temp , target , arr) ;
}

int main() {
    freopen("input.txt" , "r+" , stdin) ;
    freopen("output.txt" , "w+" , stdout) ;

    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    ll t = 1 ;
    cin >> t ;

    while (t--) {
        solve() ;
    }

    return 0 ;
}
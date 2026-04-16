#include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
#define MOD (int)(1e9 + 7) ;

/*==============================================================*/
/*
    PROBLEM OBSERVATIONS
   
*/
/*==============================================================*/

// O(n * m)
void solve() {
    string text ; cin >> text ;
    string pattern ; cin >> pattern ;

    int ts = text.size() ;
    int ps = pattern.size() ;

    if(ps > ts) {
        cout << "No" << endl ; return ;
    }

    for(int i = 0 ; i <= ts - ps ; i++) {
        bool flag = false ;

        for(int j = 0 ; j < ps ; j++) {
            if(text[i + j] != pattern[j]) {
                flag = true ;
                break ;
            }
        }

        if(!flag) {
            cout << "Yes" << endl ; return ;
        }
    }
    cout << "No" << endl ;
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
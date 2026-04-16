#include <bits/stdc++.h>
using namespace std ;

vector<int> computeLPS(string s) {
    int n = s.size() ;
    vector<int> LPS(n , 0) ;
    
    int i = 1 , j = 0 ;
    
    while(i < n) {
        if(s[i] == s[j]) {
            LPS[i] = j + 1 ;
            i++ ;
            j++ ;
        }
        else {
            while(j > 0 && s[i] != s[j]) {
                j = LPS[j - 1] ;
            }
            
            if(s[i] == s[j]) {
                LPS[i] = j + 1 ;
                j++ ;
            }
            i += 1 ;
        }
    }
    
    return LPS ;
}

vector<int> search(string pattern , string text) {
    string s = pattern + '$' + text ;
    vector<int> LPS = computeLPS(s) ;
    
    int m = pattern.size() ;
    vector<int> ans ;
    
    for(int i = m + 1 ; i < s.size() ; i++) {
        if(LPS[i] == m) {
            ans.push_back(i - 2 * m) ;
        }
    }
    
    return ans ;
}

void solve() {
    string text , pattern ; 
    cin >> text >> pattern ;
    
    vector<int> ans = search(pattern , text) ;
    
    for(auto ind : ans) {
        cout << ind << ' ' ;
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
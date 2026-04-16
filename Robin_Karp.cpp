#include <bits/stdc++.h>
using namespace std ;

vector<int> search(string pat , string txt) {
    int n = pat.length() ;
    int m = txt.length() ;
    
    int p = 7 , mod = 101 ;
    int hashPat = 0 , hashText = 0 ;
    int pRight = 1 , pLeft = 1 ;
    
    for(int i = 0 ; i < n ; i++) {
        hashPat += ((pat[i] - 'a' + 1) * pRight) % mod ;
        hashText += ((txt[i] - 'a' + 1) * pRight) % mod ;
        pRight = (pRight * p) % mod ;
    }
    
    vector<int> ans ;
    
    for(int i = 0 ; i <= m - n ; i++) {
        
        if(hashPat == hashText) {
            if(txt.substr(i , n) == pat) {
                ans.push_back(i) ;
            }
        }
        
        if(i < m - n) {
            hashText = (hashText - ((txt[i] - 'a' + 1) * pLeft) % mod + mod) % mod ;
            hashText = (hashText + ((txt[i + n] - 'a' + 1) * pRight) % mod) % mod ;
            hashPat = (hashPat * p) % mod ;
            
            pLeft = (pLeft * p) % mod ;
            pRight = (pRight * p) % mod ;
        }
    }
    
    return ans ;
}

void solve() {
    string txt , pat ; 
    cin >> txt >> pat ;
    
    vector<int> ans = search(pat , txt) ;
    
    for(auto it : ans) {
        cout << it << ' ' ;
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
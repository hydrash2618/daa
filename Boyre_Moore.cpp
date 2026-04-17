#include <bits/stdc++.h>
using namespace std ;



bool search(string& pat , string& txt) {
    int ts = txt.size() , ps = pat.size() ;
    if(ps > ts) return false ;

    map<char , int> mpp ;
    for(int i = 0 ; i < ps ; i++) {
        mpp[pat[i]] = max(1 , ps - i - 1) ;
    }


    int i = 0 ;
    while(i <= ts - ps) {
        int j = i + ps - 1 ;
        bool flag = true ;

        for(int k = ps - 1 ; k >= 0 ; k--) {
            if(txt[j] != pat[k]) {
                flag = false ;
                if(mpp.find(txt[j]) != mpp.end()) {
                    i += mpp[txt[j]] ;
                }
                else {
                    i += ps ;
                }
                break ;
            }
            else {
                j-- ;
            }
        }

        if(flag) {
            return 1 ;
        }
    }
    return 0 ;
}

// bool search(string& pat , string& txt) {
//     int ts = txt.size() , ps = pat.size() ;
//     if(ps > ts) return false ;

//     map<char , int> mpp ;
//     for(int i = 0 ; i < ps ; i++) {
//         mpp[pat[i]] = i ;
//     }

//     int i = 0 ;
//     while(i <= ts - ps) {
//         int j = i + ps - 1 ;
//         bool flag = true ;

//         for(int k = ps - 1 ; k >= 0 ; k--) {
//             if(txt[j] != pat[k]) {
//                 flag = false ;
//                 if(mpp.find(txt[j]) != mpp.end()) {
//                     i += max(1 , k - mpp[txt[j]]) ;
//                 }
//                 else {
//                     i += k + 1 ;
//                 }
//                 break ;
//             }
//             else {
//                 j-- ;
//             }
//         }

//         if(flag) {
//             return 1 ;
//         }
//     }
//     return 0 ;
// }

void solve() {
    string txt , pat ; 
    cin >> txt >> pat ;
    
    bool ans = search(pat , txt) ;
    if(ans) {
        cout << "YES" << endl ;
    }
    else {
        cout << "NO" << endl ;
    }
}

int main() {
    int T ; cin >> T ;
    while(T--) {
        solve() ;
    }

    return 0 ;
}
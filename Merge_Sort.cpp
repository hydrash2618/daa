#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;

// O(n log n)
void merger(ll low , ll mid , ll high , vector<ll>& arr) {
    ll left = low ;
    ll right = mid + 1 ;
    vector<ll> temp ;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]) ;
            left++ ;
        }
        else {
            temp.push_back(arr[right]) ;
            right++ ;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]) ;
        left++ ;
    }

    while(right <= high) {
        temp.push_back(arr[right]) ;
        right++ ;
    }

    for(ll i = low ; i <= high ; i++) {
        arr[i] = temp[i - low] ;
    }
}

void mergeSort(ll low , ll high , vector<ll>& arr) {
    if(low >= high) return ;

    ll mid = low + ((high - low) / 2) ;
    mergeSort(low , mid , arr) ;
    mergeSort(mid + 1 , high , arr) ;
    merger(low , mid , high , arr) ;
}

void solve() {
    ll n ; cin >> n ;
    vector<ll> arr(n) ;

    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
    }

    for(auto it : arr) {
        cout << it << ' ' ;
    }
    cout << endl ;

    mergeSort(0 , n - 1 , arr) ;
    
    for(auto it : arr) {
        cout << it << ' ' ;
    }
    cout << endl ;
}

int main() {
    freopen("input.txt" , "r+" , stdin) ;
    freopen("output.txt" , "w+" , stdout) ;

    ll T ; cin >> T ;
    while(T--) {
        solve() ;
    }

    return 0 ;
}
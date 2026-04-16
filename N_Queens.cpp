#include <bits/stdc++.h>
using namespace std ;

// bool check(int row , int col , int n , vector<vector<char>>& grid) {
//     // in same row
//     for(int c = 0 ; c < col ; c++) {
//         if(grid[row][c] == 'Q') return false ;
//     }

//     // in principal diagonal
//     int i = row - 1 , j = col - 1 ;

//     while(i >= 0 && j >= 0) {
//         if(grid[i][j] == 'Q') return false ;
//         i-- ;
//         j-- ;
//     }

//     i = row + 1 ;
//     j = col - 1 ;

//     // in secondary diagonal
//     while(i < n && j >= 0) {
//         if(grid[i][j] == 'Q') return false ;
//         i++ ;
//         j-- ;
//     }
    
//     return true ;
// }

void func(int col , int n, vector<int>& rowChecker , vector<int>& primaryDiagonalChecker , vector<int>& secondaryDiagonalChecker, vector<vector<char>>& grid) {
    if(col >= n) {
        for(auto r : grid) {
            for(auto c : r) {
                cout << c << ' ' ;
            }
            cout << endl ;
        }
        cout << endl ;
        return ;
    }

    for(int row = 0 ; row < n ; row++) {
        if(rowChecker[row] == 0 && primaryDiagonalChecker[(col - row) + (n - 1)] == 0 && secondaryDiagonalChecker[row + col] == 0) {
            rowChecker[row]++ ;
            primaryDiagonalChecker[(col - row) + (n - 1)]++ ;
            secondaryDiagonalChecker[row + col]++ ;
            grid[row][col] = 'Q' ;

            func(col + 1 , n , rowChecker , primaryDiagonalChecker , secondaryDiagonalChecker , grid) ;

            grid[row][col] = '.' ;
            rowChecker[row]-- ;
            primaryDiagonalChecker[(col - row) + (n - 1)]-- ;
            secondaryDiagonalChecker[row + col]-- ;
        }
    }
}

void solve() {
    int n ; cin >> n ;
    vector<vector<char>> grid(n , vector<char>(n , '.')) ;
    vector<int> rowChecker(n , 0) ;
    vector<int> primaryDiagonalChecker(2 * n , 0) ;
    vector<int> secondaryDiagonalChecker(2 * n , 0) ;

    func(0 , n , rowChecker , primaryDiagonalChecker , secondaryDiagonalChecker , grid) ;
}

int main() {
    int T ; cin >> T ;
    while(T--) {
        solve() ;
    }

    return 0 ;
}
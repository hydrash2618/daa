#include <bits/stdc++.h>
using namespace std ;

using Matrix = vector<vector<int>> ;

Matrix add(Matrix& A , Matrix& B) {
    int n = A.size() ;
    Matrix C(n , vector<int>(n , 0)) ;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            C[i][j] = A[i][j] + B[i][j] ;
        }
    }
    return C ;
}

Matrix sub(Matrix& A , Matrix& B) {
    int n = A.size() ;
    Matrix C(n , vector<int>(n , 0)) ;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            C[i][j] = A[i][j] - B[i][j] ;
        }
    }
    return C ;
}

Matrix strassen(Matrix& A , Matrix& B) {
    int n = A.size() ;
    
    if(n == 1) {
        return {{A[0][0] * B[0][0]}} ;
    }
    
    int newSize = n / 2 ;
    Matrix A11(newSize , vector<int>(newSize , 0)) ;
    Matrix A12(newSize , vector<int>(newSize , 0)) ;
    Matrix A21(newSize , vector<int>(newSize , 0)) ;
    Matrix A22(newSize , vector<int>(newSize , 0)) ;
    
    Matrix B11(newSize , vector<int>(newSize , 0)) ;
    Matrix B12(newSize , vector<int>(newSize , 0)) ;
    Matrix B21(newSize , vector<int>(newSize , 0)) ;
    Matrix B22(newSize , vector<int>(newSize , 0)) ;
    
    for(int i = 0 ; i < newSize ; i++) {
        for(int j = 0 ; j < newSize ; j++) {
            A11[i][j] = A[i][j] ;
            A12[i][j] = A[i][j + newSize] ;
            A21[i][j] = A[i + newSize][j] ;
            A22[i][j] = A[i + newSize][j + newSize] ;
            
            B11[i][j] = B[i][j] ;
            B12[i][j] = B[i][j + newSize] ;
            B21[i][j] = B[i + newSize][j] ;
            B22[i][j] = B[i + newSize][j + newSize] ;
        }
    }
    
    Matrix tempA1 = add(A11 , A22) ;
    Matrix tempB1 = add(B11 , B22) ;
    Matrix M1 = strassen(tempA1 , tempB1) ;
    
    Matrix tempA2 = add(A21 , A22) ;
    Matrix M2 = strassen(tempA2 , B11) ;
    
    Matrix tempB3 = sub(B12 , B22) ;
    Matrix M3 = strassen(A11 , tempB3) ;
    
    Matrix tempB4 = sub(B21 , B11) ;
    Matrix M4 = strassen(A22 , tempB4) ;
    
    Matrix tempA5 = add(A11 , A12) ;
    Matrix M5 = strassen(tempA5 , B22) ;
    
    Matrix tempA6 = sub(A21 , A11) ;
    Matrix tempB6 = add(B11 , B12) ;
    Matrix M6 = strassen(tempA6 , tempB6) ;
    
    Matrix tempA7 = sub(A12 , A22) ;
    Matrix tempB7 = add(B21 , B22) ;
    Matrix M7 = strassen(tempA7 , tempB7) ;
    
    Matrix tempC11_1 = add(M1 , M4) ;
    Matrix tempC11_2 = sub(tempC11_1 , M5) ;
    Matrix C11 = add(tempC11_2 , M7) ;
    
    Matrix C12 = add(M3 , M5) ;
    Matrix C21 = add(M2 , M4) ;
    
    Matrix tempC22_1 = sub(M1 , M2) ;
    Matrix tempC22_2 = add(tempC22_1 , M3) ;
    Matrix C22 = add(tempC22_2 , M6) ;
    
    Matrix C(n , vector<int>(n , 0)) ;
    for(int i = 0 ; i < newSize ; i++) {
        for(int j = 0 ; j < newSize ; j++) {
            C[i][j] = C11[i][j] ;
            C[i][j + newSize] = C12[i][j] ;
            C[i + newSize][j] = C21[i][j] ;
            C[i + newSize][j + newSize] = C22[i][j] ;
        }
    }
    
    return C ;
}

void solve() {
    int n ; 
    cin >> n ;
    
    int m = 1 ;
    while(m < n) {
        m *= 2 ;
    }
    
    Matrix A(m , vector<int>(m , 0)) ;
    Matrix B(m , vector<int>(m , 0)) ;
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> A[i][j] ;
        }
    }
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> B[i][j] ;
        }
    }
    
    Matrix C = strassen(A , B) ;
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout << C[i][j] << ' ' ;
        }
        cout << endl ;
    }
}

int main() {
    int T = 1 ; 
    cin >> T ;
    while(T--) {
        solve() ;
    }

    return 0 ;
}
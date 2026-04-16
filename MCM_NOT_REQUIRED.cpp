#include <bits/stdc++.h>
using namespace std;

// Helper function to print the optimal parenthesization
void printParens(int i, int j, vector<vector<int>>& bracket, char& matrixName) {
    // Base case: If it's a single matrix, just print its name (e.g., 'A')
    if (i == j) {
        cout << matrixName++;
        return;
    }

    cout << "(";
    
    // Recursively print the left sub-problem using the optimal split point 'k'
    printParens(i, bracket[i][j], bracket, matrixName);
    
    // Recursively print the right sub-problem
    printParens(bracket[i][j] + 1, j, bracket, matrixName);
    
    cout << ")";
}

int mcm(int i, int j, vector<int>& arr, vector<vector<int>>& dp, vector<vector<int>>& bracket) {
    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != -1) return dp[i][j];

    int minOps = INT_MAX;
    int optimalK = -1; // To track where the best split happens

    for (int k = i; k < j; k++) {
        int cost = (arr[i - 1] * arr[k] * arr[j]) 
                   + mcm(i, k, arr, dp, bracket) 
                   + mcm(k + 1, j, arr, dp, bracket);

        // If we found a strictly better cost, save it AND save the 'k'
        if (cost < minOps) {
            minOps = cost;
            optimalK = k; 
        }
    }

    // Store the optimal split point for this range
    bracket[i][j] = optimalK;
    
    return dp[i][j] = minOps;
}

void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> bracket(n, vector<int>(n, -1)); // New array

    // Run the DP to fill both the dp and bracket tables
    int minCost = mcm(1, n - 1, arr, dp, bracket);
    
    cout << "Minimum Operations: " << minCost << endl;
    
    cout << "Optimal Parenthesization: ";
    char matrixName = 'A'; // Start naming matrices from 'A'
    printParens(1, n - 1, bracket, matrixName);
    cout << endl;
}

int main() {
    int T = 1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
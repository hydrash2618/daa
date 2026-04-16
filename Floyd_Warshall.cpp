#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];

            if (adj[i][j] == -1)
            {
                adj[i][j] = 1e9;
            }
        }
    }

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][via] != 1e9 && adj[via][j] != 1e9)
                {
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] >= 1e9)
            {
                adj[i][j] = -1;
            }
        }
    }

    for (auto it : adj)
    {
        for (auto it1 : it)
        {
            cout << it1 << ' ';
        }
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
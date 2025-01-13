#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
vector<vector<char>> grid; 
vector<vector<int>> dp;
int n, paths = 0;

signed main() {
    cin >> n;

    grid.resize(n + 1, vector<char>(n + 1));
    dp.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[1][1] = (grid[1][1] != '*') ? 1 : 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '*') continue; 
            if (i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n][n] << endl; 
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
bool valid, iT, jT;
int n;

bool solve(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &dp){
    if(!valid) return false;
    if(i == n && grid[i][j] == '1' or j == n && grid[i][j] == '1') return true;

    if(i < n) iT = dp[i+1][j];
    if(j < n) jT = dp[i][j+1];

    if(!iT && !jT) valid = false;

    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        valid = true;
        iT = true, jT = true;

        vector<vector<char>> grid(n+1, vector<char>(n+1));
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) cin >> grid[i][j];

        for (int i = n; i > 0; i--)
            for (int j = n; j > 0; j--){
                if (!valid) break;
                if(grid[i][j] == '1') {
                    dp[i][j] = 1;
                    solve(i,j, grid, dp);
                }
            }

        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}
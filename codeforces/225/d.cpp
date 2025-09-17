#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do { cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS___)
#else
#define dbg(...) 42
#endif

int mx = 1e3+1;

void solve(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;

    vector<int> cntW(m), cntB(m);
    vector<vector<char>> c(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if(c[i][j] == '#' ? cntB[j]++ : cntW[j]++);
        }
    }

    vector<vector<int>> dp(mx, vector<int>(2, 1e9)), nxt(mx, vector<int>(2, 1e9));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                nxt[j+1][k] = min(nxt[j+1][k], dp[j][k] + (k ? cntB[i] : (n-cntB[i])));
                if(j >= x-1) nxt[0][!k] = min(nxt[0][!k], dp[j][k] + (k ? cntB[i] : (n-cntB[i])));
            }
        }
        swap(dp, nxt);
        for (int j = 0; j < mx; j++)
        {
            for (int k = 0; k < 2; k++) nxt[j][k] = 1e9;
        }
    }

    int ans = 1e9;
    for (int i = x; i <= y; i++) ans = min({ans, dp[i][0], dp[i][1]});
    cout << ans << endl;
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}
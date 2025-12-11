#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

vector<bool> visited;
const int mx = 100;
vector<vector<int>> dp (mx+1123, vector<int>(mx+1123));

int mex(int ix, int jx){
    visited.clear();
    visited.resize(1000);

    for (int i = 0; i < ix; i++) visited[dp[i][jx]] = true;

    for (int i = 0; i < jx; i++) visited[dp[ix][i]] = true;
    
    int minIdx = min(ix, jx);
    
    for (int i = 1; i <= minIdx; i++) visited[dp[ix-i][jx-i]] = true;
    
    for (int i = 0; i < 1000; i++) if(!visited[i]) return i;
}

signed main(){
    fastio;
    int n;
    cin >> n;
    
    dp[0][0] = 999;

    for (int i = 1; i <= 100; i++) dp[i][0] = dp[0][i] = dp[i][i] = 999;
    
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if(i != j) dp[i][j] = mex(i, j);
        }
    }

    int ans = 0;
    bool corner = false;
    for (int i = 0; i < n; i++)
    {
        int l,c;
        cin >> l >> c;

        if(dp[l][c] == 999) corner = true;

        ans ^= dp[l][c];
    }
    

    cout << (corner or ans ? "Y" : "N") << '\n';
    return 0;
}
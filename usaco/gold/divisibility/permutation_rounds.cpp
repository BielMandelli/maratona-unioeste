#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

const int MOD = 1e9+7;

vector<vector<int>> g;
vector<int> cycles;
vector<bool> visited;

int dfs(int cur, int sz){
    if(visited[cur]) return sz-1;
    visited[cur] = true;

    for(auto v : g[cur]){
        // cout << v << " : " << sz << endl;
        return dfs(v, sz+1);
    }
}

int fastexp(int x, int y) {
    int ans = 1;
    x %= MOD;
    while (y) {
        if (y & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    g.resize(n+1);
    visited.resize(n+1);
    for(auto &x : a) cin >> x;

    for (int i = 0; i < n; i++)
    {
        g[i+1].push_back(a[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        if(!visited[i]) {
            cycles.push_back(dfs(i, 1));
        }
    }
    
    map<int,int> cnt;
    for (int i = 0; i < cycles.size(); i++)
    {
        int x = cycles[i];
        for (int j = 2; j*j <= x; j++)
        {
            int cur = 0;
            while (x%j == 0)
            {
                cur++;
                x /= j;
            }
            if(cur) cnt[j] = max(cnt[j], cur);
        }
        if(x>1) cnt[x] = max(cnt[x], 1LL);
    }

    int ans = 1;
    for(auto [x,y] : cnt){
        ans = (ans * fastexp(x,y)) % MOD;
    }
    
    cout << ans % MOD << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}
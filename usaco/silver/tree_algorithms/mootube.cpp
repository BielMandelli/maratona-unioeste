#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> g;
vector<vector<int>> rel;

int ans = 0;
void dfs(int node, int parent, int k){
    if(parent != -1 && k <= rel[node][parent]) ans++;
    else if (parent != -1) return;

    for(auto ch : g[node]){
        if(ch != parent) {
            dfs(ch, node, k);
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    g.resize(n+1);
    rel.resize(n+1, vector<int>(n+1));

    vector<int> h(n+1, 1e10);
    for (int i = 0; i < n-1; i++)
    {
        int pi, qi, ri;
        cin >> pi >> qi >> ri;
        g[pi].push_back(qi);
        g[qi].push_back(pi);
        rel[pi][qi] = ri;
        rel[qi][pi] = ri;
        h[qi] = min(h[qi], ri);
        h[pi] = min(h[pi], ri);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(rel[i][j] > 0) continue;
            rel[i][j] = min(h[i], h[j]);
            rel[j][i] = min(h[i], h[j]);
        }
    }
    
    for (int i = 0; i < q; i++)
    {
        ans = 0;
        int x, y;
        cin >> x >> y;
        dfs(y, -1, x);
        cout << ans << endl;
    }
    
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}
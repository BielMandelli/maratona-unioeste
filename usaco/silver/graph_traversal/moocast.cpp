#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

struct Cow {
    int x,y,r;
};
vector<Cow> c;
vector<vector<int>> g;
vector<bool> visited;
int ans = 0;

bool compare(Cow &x, Cow &y){
    if(x.x != y.x) return x.x < y.x;
    else return x.y < y.y;
}

int dist(const Cow &x, const Cow &y) {
    int dx = y.x - x.x;
    int dy = y.y - x.y;
    return dx * dx + dy * dy;
}

int cnt = 0;

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;
    cnt++; 

    for(auto ch : g[node]){
        if(visited[ch]) continue;
        dfs(ch);
    }
}

void solve(){
    int n;
    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].x >> c[i].y >> c[i].r;
        c[i].r *= c[i].r;
    }

    sort(c.begin(), c.end(), compare);

    g.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j) continue;
            int d = dist(c[i], c[j]);
            if(d <= c[i].r) g[i].push_back(j);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        visited.resize(n);
        cnt = 0;
        dfs(i);
        ans = max(ans, cnt);
        visited.clear();
    }
    
    cout << ans << endl;
}

signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}
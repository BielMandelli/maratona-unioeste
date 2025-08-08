#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<pair<int, bool>>> g;

void solve(){
    int n,m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        char c;
        cin >> c >> u >> v;
        u--;
        v--;
        g[u].push_back({v, c == 'S'});
        g[v].push_back({u, c == 'S'});
    }
    
    int cp = 0;
    bool valid = true;
    vector<int> visited(n, -1);

    for (int i = 0; i < n; i++)
    {
        if(visited[i] == -1){
            cp++;
            queue<pair<int, bool>> q;
            q.push({i, true});

            while (!q.empty())
            {
                auto [u, sts] = q.front();
                q.pop();

                visited[u] = sts;

                for(auto adj : g[u]){
                    bool type = adj.second ? sts : !sts;

                    if(visited[adj.first] == -1) q.push({adj.first, type});
                    else if(visited[adj.first] == !type){
                        valid = false;
                        break;
                    }
                }
            }
            
        }
    }

    if(valid){
        cout << 1;
        for(int i = 0; i < cp; i++) cout << 0;
        cout << endl;
    } else cout << 0 << endl;
    
}

signed main()
{
    // bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}
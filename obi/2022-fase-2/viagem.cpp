#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, v, maxx = 1e9+10;
vector<tuple<int,int,int>> graph[10010];
int dp[10010][210];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> n >> m;

    int x, y, a, b;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> a >> b;
        graph[x].push_back({y, a, b});
        graph[y].push_back({x, a, b});
    }

    int init, end;
    cin >> init >> end;

    for (int c = 0; c <= v; c++)
    {
        for (int i = 1; i <= n; i++) dp[i][c] = maxx;
        
        dp[end][c] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (auto tup : graph[i])
            {
                if(get<2>(tup) == 0 or get<2>(tup) > c) continue;
                dp[i][c] = min(dp[i][c], dp[get<0>(tup)][c - get<2>(tup)] + get<1>(tup));
            }
        }

        set<pair<int, int>> s;

        for (int i = 1; i <= n; i++) s.insert({dp[i][c], i});

        while(!s.empty())
        {
            int cur = s.begin()->second;
            s.erase(s.begin());

            for(auto tup : graph[cur])
            {
                if(get<2>(tup) != 0) continue;

                if(dp[get<0>(tup)][c] > dp[cur][c] + get<1>(tup))
                {
                    s.erase( {dp[get<0>(tup)][c] , get<0>(tup)} );
                    dp[get<0>(tup)][c] = dp[cur][c] + get<1>(tup);
                    s.insert( {dp[get<0>(tup)][c] , get<0>(tup)} );
                }
            }
        }
    }

    if(dp[init][v] != maxx) cout << dp[init][v] << endl;
    else cout << -1 << endl;
    
    return 0;
}
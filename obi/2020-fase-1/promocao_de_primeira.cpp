#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;
int n, x, y, e, ans = 0;
vector<vector<pair<int,int>>> graph;

void dfs(int i, int parent, int &max0, int &max1){
    max0 = 0, max1 = 0;
    for (auto neigh : graph[i])
    {
        if(neigh.first != parent) {
            int childm1, childm0;
            dfs(neigh.first, i, childm0, childm1);
            if (neigh.second == 0) max0 = max(max0, childm1 + 1);
            else max1 = max(max1, childm0 + 1);
        }
    }
    
    ans = max(ans, max1 + max0 + 1);
}

signed main(){
    fastio;

    cin >> n;

    graph.resize(n);

    for (int i = 0; i < n-1; i++)
    {
        cin >> x >> y >> e;
        x--; y--;
        graph[x].emplace_back(y, e);
        graph[y].emplace_back(x, e);
    }

    ans = 0;
    int max0 = 0, max1 = 0;
    dfs(0, -1, max0, max1);
    
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
vector<vector<int>> graph;
long double ans = 0;

void dfs(int node, int parent, double prob, double path){
    int children = (!parent) ?  graph[node].size() : graph[node].size() - 1;

    if (children == 0) {
        ans += prob * path;
        return;
    }
    
    for (auto child : graph[node]) if(child != parent) dfs(child, node, prob/children, path+1);
     
}

signed main() {
    bieo;
    int n;

    cout << setprecision(15) << fixed;

    cin >> n;
    graph.resize(n+1);

    for (int i = 0; i < n-1; i++)
    {
        int v,u;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0, 1, 0);
    
    cout << ans << endl;
        
    return 0;
}

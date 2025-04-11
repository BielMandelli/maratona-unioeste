#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long

vector<vector<int>> graph;
vector<int> cnt(101, 0);

void dfs(int node, vector<bool> &visited){
    if(!visited[node]) visited[node] = true;

    bool hasChild = false;
    for(auto child : graph[node]){
        if(!visited[child]){
            dfs(child, visited);
        }
        hasChild = true;
    }

    if(!hasChild) cnt[node]++;
}

signed main()
{
    bieo;
    int n;
    cin >> n;

    vector<bool> visited(n+1);
    graph.resize(n+1);

    for (int i = 0; i < n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        dfs(i, visited);
        visited.clear();
        visited.resize(n+1);
    }
    
    int ans = 0;
    bool valid = true;
    for (int i = 0; i < 101; i++)
    {
        if(cnt[i] > 0){
            if(!ans) ans = i;
            else {
                valid = false;
                break;
            }
        }
    }
    
    if(valid) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
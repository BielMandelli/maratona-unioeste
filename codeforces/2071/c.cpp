#include <bits/stdc++.h>
#define int long long
using namespace std;
 
void dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& dist) {
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            dist[neighbor] = dist[node] + 1;
            dfs(neighbor, node, tree, dist);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, st, en;
        cin >> n >> st >> en;

        vector<vector<int>> tree(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> dist(n + 1, -1);
        dist[en] = 0;
        dfs(en, -1, tree, dist);
    
        vector<int> perm(n);

        iota(perm.begin(), perm.end(), 1);
        sort(perm.begin(), perm.end(), [&](int a, int b) {
            return dist[a] > dist[b];
        });
    
        if (dist[st] == -1) {
            cout << "-1" << endl;
        } else {
            for (int p : perm) cout << p << " ";
            cout << endl;
        }
    }

    return 0;
}
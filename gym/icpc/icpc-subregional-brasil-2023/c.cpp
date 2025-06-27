#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

vector<vector<int>> tree;
vector<int> val;
vector<int> ans;

void dfs(int node, int parent, vector<int> &lis) {
    int x = val[node];
    auto it = lower_bound(lis.begin(), lis.end(), x);
    int pos = it - lis.begin();
    
    int replaced = -1;
    bool appended = false;

    if (it == lis.end()) {
        lis.push_back(x);
        appended = true;
    } else {
        replaced = *it;
        *it = x;
    }

    ans[node] = lis.size(); 

    for (int v : tree[node]) {
        if (v != parent) dfs(v, node, lis);
    }

    if (appended) lis.pop_back();
    else lis[pos] = replaced;
}

void solve() {
    int n;
    cin >> n;
    tree.resize(n);
    val.resize(n);
    ans.resize(n);

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }

    for (int i = 0; i < n; i++) cin >> val[i];

    vector<int> lis;
    dfs(0, -1, lis);

    for (int i = 1; i < n; i++) cout << ans[i] << ' ';
     
    cout << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
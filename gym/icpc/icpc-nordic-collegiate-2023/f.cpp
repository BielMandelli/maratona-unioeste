#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

const int MAXN = 500;

vector<vector<int>> tree(MAXN + 1);
vector<int> primes, ans(MAXN + 1, -1), anc(MAXN + 1);
vector<pair<int,int>> leafs;
 
void dfs(int node, int parent, int depth) {
    if (ans[node] != -1) depth = 0;

    for (auto child : tree[node]) {
        if (child == parent) continue;
        dfs(child, node, depth + 1);
    }
    anc[node] = parent;
    if(tree[node].size() == 1 && ans[node] == -1) leafs.push_back({depth, node});
}

void calc(int node, int prime){
    if(ans[node] != -1) return;
    vector<int> path = {node};

    while (ans[anc[path.back()]] == -1) path.push_back(anc[path.back()]);
    
    int cur = ans[anc[path.back()]] * prime;
    while (!path.empty())
    {
        ans[path.back()] = cur;
        cur *= prime;
        path.pop_back();
    }
}

void init() {
    int limit = 4000;
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
        if (primes.size() == 60) break;
    }
}

int solve() {
    int n;
    cin >> n;
    init();

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    leafs.push_back({1, 1});
    ans[1] = 1;
    int pi = 0;
    
    while (leafs.size())
    {
        leafs.clear();
        dfs(1, 1, 0);
        sort(leafs.rbegin(), leafs.rend());
        calc(leafs[0].second, primes[pi]);
        pi++;
        dfs(1, 1, 0);
    }
    
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

signed main() {
    bieo;
    int t = 1;
    while (t--) solve();
    return 0;
}

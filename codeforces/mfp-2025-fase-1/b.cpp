#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
vector<int> level;
vector<int> parent;
int g = -1, d = 0;

int find(int i)
{
    int root = parent[i];

    if (parent[root] != root) return parent[i] = find(root);
    
    return root;
}

void unite(int a, int b)
{
    int x = find(a);
    int y = find(b);

    if (x == y) return;

    if (level[x] < level[y]) parent[x] = y;
    else if (level[y] < level[x]) parent[y] = x;
    else {
        parent[y] = x;
        level[x]++;
    }
}

signed main()
{
    bieo;
    int n, m;
    cin >> n >> m;

    level.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i <= n; i++) parent[i] = i;
    
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) d++;
        else unite(x,y);
    }

    for (int i = 1; i <= n; i++) if(parent[i] == i) g++;
    
    
    if (!g && !d) cout << "BOM" << endl;
    else cout << "RUIM " << d << " " << g << endl;

    return 0;
}

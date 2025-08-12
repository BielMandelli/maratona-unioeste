#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

int n, k, r, ans = 0;
vector<vector<array<int, 4>>> g;
vector<pair<int,int>> cow;
vector<vector<int>> visited;
int dx[4] = {-1, 1, 0, 0}; // N, S, L, O
int dy[4] = {0, 0, 1, -1};

void dfs(int i, int j, vector<pair<int,int>> &cells) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    cells.push_back({i,j});

    for (int l = 0; l < 4; l++) {
        int ni = i + dx[l], nj = j + dy[l];
        if (ni <= 0 || nj <= 0 || ni > n || nj > n) continue;
        if (g[i][j][l]) continue; 
        else dfs(ni, nj, cells);         
    }
}

void solve() {
    cin >> n >> k >> r;
    g.resize(n+1, vector<array<int,4>>(n+1, {0,0,0,0}));
    visited.resize(n+1, vector<int>(n+1));

    for (int i = 0; i < r; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int dir1, dir2;
        if (r1 == r2) {
            if (c1 < c2) { dir1 = 2; dir2 = 3; }
            else { dir1 = 3; dir2 = 2; }
        } else {
            if (r1 < r2) { dir1 = 1; dir2 = 0; }
            else { dir1 = 0; dir2 = 1; }
        }

        g[r1][c1][dir1] = 1;
        g[r2][c2][dir2] = 1;
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        cow.push_back({x,y});
    }

    vector<vector<pair<int,int>>> comp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
        {
            if(!visited[i][j]){
                vector<pair<int,int>> c;
                dfs(i, j, c);
                comp.push_back(c);
            }
        }
    }

    map<pair<int,int>, int> mp;
    for (int i = 0; i < comp.size(); i++)
        for(auto cell : comp[i]) mp[cell] = i;

    for (int i = 0; i < k; i++)
        for (int j = i+1; j < k; j++)
            if(mp[cow[i]] != mp[cow[j]]) ans++;
    
    cout << ans << endl;
}

signed main() {
    bieo;
    solve();
}

#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

struct cell {
    int i, j;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }

    vector<cell> mId;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == mx) mId.push_back({i, j});

    for (int i = 0; i < n; i++) {
        int uniqC = -1;
        bool valid = true;

        for (auto cell : mId) {
            if (cell.i == i) continue;
            if (uniqC == -1) uniqC = cell.j;
            else if (uniqC != cell.j) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << mx - 1 << endl;
            return;
        }
    }

    cout << mx << endl;
}

signed main()
{
    bieo;
    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}
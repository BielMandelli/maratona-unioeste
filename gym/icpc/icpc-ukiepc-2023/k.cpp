#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> inc, dec;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) inc.insert(i);
        else dec.insert(i);
    }

    set<int> ans = (inc.size() >= m / 2) ? inc : dec;

    if(inc.size() < m/2 && dec.size() < m/2)  cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (int id : ans) cout << id << " ";
        cout << endl;
    }
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

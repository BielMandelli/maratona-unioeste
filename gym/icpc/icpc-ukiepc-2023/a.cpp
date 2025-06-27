#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n, W;
    cin >> n >> W;

    int k = n/2; 

    vector<pair<int, int>> e;

    for (int i = 0; i < k; i++) {
        int w = W - i;   
        int q = i;       
        e.push_back({w, q});
    }

    for (int i = 0; i < n - k; i++) {
        int w = W + 1000 + i; 
        int q = 0;            
        e.push_back({w, q});
    }

    set<pair<int, int>> uniq;
    for (auto &[w, q] : e) {
        while (uniq.count({w, q})) q++; 
        uniq.insert({w, q});
    }

    for (auto [w, q] : e) cout << w << ' ' << q << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    sort(a.begin(), a.end());
    vector<int> ans;

    for (int i = 0, j = n-1; i < n; i++, j--) ans.push_back((a[i]+a[j])/2);
    
    sort(ans.begin(), ans.end());

    cout << ans.back() << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
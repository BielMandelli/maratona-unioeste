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

    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i] - a[i+1]) <= 1) {
            cout << 0 << endl;
            return;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int vmn = min(a[i], a[i+1]);
        int vmx = max(a[i], a[i+1]);

        if (i > 0) {
            if (max(vmn, a[i-1]-1) <= min(vmx, a[i-1]+1)) {
                cout << 1 << endl;
                return;
            }
        }

        if (i < n - 2) { 
            if (max(vmn, a[i+2]-1) <= min(vmx, a[i+2]+1)) {
                cout << 1 << endl;
                return;
            }
        }
    }
    
    cout << -1 << endl;
}

signed main() {
    bieo;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
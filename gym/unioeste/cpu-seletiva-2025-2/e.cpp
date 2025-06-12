#include <bits/stdc++.h>
using namespace std;
#define beeu cin.tie(0)->sync_with_stdio(0)
#define int long long
const int MOD = 1e9+7;
 
signed main() {
    int t;
    cin >> t;
 
    while(t--) {
        int n, u, r, l, val;
        cin >> n >> u;
        vector<int> diff(n+1);
 
        for (int i = 0; i < u; ++i) {
            cin >> l >> r >> val;
            diff[l] += val;
            diff[r+1] -= val;
        }

        int q, aux;
        cin >> q;
        for (int i = 0; i < q; ++i) {
            cin >> aux;

            int res = 0;
            for (int j = 0; j <= aux; ++j) {
                res += diff[j];
            }
            cout << res << endl;
        }
    }
    return 0;
}

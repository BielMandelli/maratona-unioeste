#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> counts(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= n) {
            counts[val]++;
        }
    }

    vector<int> diff(n + 2, 0);

    for (int m = 0; m <= n; ++m) {
        int min_k = counts[m];
        int max_k = n - m;

        if (min_k <= max_k) {
            diff[min_k]++;
            if (max_k + 1 <= n) {
                diff[max_k + 1]--;
            }
        }

        if (counts[m] == 0) {
            break;
        }
    }

    int cur_cnt = 0;
    for (int k = 0; k <= n; ++k) {
        cur_cnt += diff[k];
        cout << cur_cnt << " ";
    }
    cout << endl;
}

signed main()
{
    bieo;
    int t=1;
    cin >> t;

    while (t--) solve();
    
    return 0;
}
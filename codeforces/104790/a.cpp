#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bieo cin.tie(0)->sync_with_stdio(0)
#define endl '\n'

signed main() {
    bieo;
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> d(n);
    int total = 0;
    for(auto &x : d) {
        cin >> x;
        total+= x;
    }
    
    sort(d.begin(), d.end(), greater<int>());
    int pass = 0, cur = 0;
    for(int i = cur, j = 0; i < n && j < m; i++, j++){
        pass+= d[i];
        cur++;
    }

    for(int i = cur, j = 0; i < n && j < k; i++, j++){
        pass+= d[i];
        cur++;
    }

    double ans = (double) pass/ (double) total * 100.0;

    cout << setprecision(20) << fixed;
    cout << ans << endl;

    return 0;
}

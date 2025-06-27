#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    double m1,m2,x1,x2,f;
    cin >> m1 >> m2 >> x1 >> x2 >> f;

    double g = (m1*m2);
    double div = (abs(x1-x2)*abs(x1-x2)) * f;
    double ans = div/g;
    cout << setprecision(10) << fixed;
    cout << ans << endl;
}

signed main() {
    bieo;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
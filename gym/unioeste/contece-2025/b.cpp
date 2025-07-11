#include <bits/stdc++.h>
using namespace std;
#define bieo cin.tie(0)->sync_with_stdio(0)
#define int long long
#define endl '\n'

void solve() {
    double c, d, t;
    cin >> c >> d >> t;

    double ans = d/c - t;
    if(ans < 0.0) ans = 0.0;
    cout << setprecision(1) << fixed;
    cout << ans << endl;
}


signed main()
{
    bieo;
    int t=1;
    // cin >> t;

    while (t--) solve();
    
    return 0;
}